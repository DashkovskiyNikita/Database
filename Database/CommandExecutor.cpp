#include"CommandExecutor.h"
#include"DBFile.h"
#include<sstream>
#include<algorithm>

using namespace std;


CommandExecutor::CommandExecutor(Database* database) : database(database) { }

void CommandExecutor::execute(Command command) {
	auto data = command.data;
	switch (command.type) {
	case Type::LOAD:
		load(data);
		break;
	case Type::SAVE:
		exp(data);
		break;
	case Type::PRINT:
		print(data);
		break;
	case Type::ADD:
		insert(data);
		break;
	case Type::EXPORT:
		exp(data);
		break;
	case Type::FIND:
		find(data);
		break;
	case Type::DELETE:
		del(data);
		break;
	}
}

void CommandExecutor::load(const std::string path) {
	DBFile file;
	auto db = file.read(path);
	database->load(db);
}

void CommandExecutor::exp(const std::string path) {
	DBFile file;
	auto db = database->exp();
	file.write(path, db);
}

void CommandExecutor::print(const std::string data) {
	if (data.empty()) database->print();
	else {
		int value = stoi(data);
		database->print(value);
	}
}

void CommandExecutor::insert(const std::string data) {
	string value = data;
	replace(value.begin(), value.end(), ',', ' ');
    istringstream stream(value);
	vector<string> result;
	while (stream >> value) { result.push_back(value); }
	auto newTable = RoomForSale{
		database->lastID() + 1,
		result[0],
		stoi(result[5]),
		stoi(result[1]),
		stoi(result[2]),
		stoi(result[3]),
		result[4],
	};
	database->insert(newTable);
}

void CommandExecutor::find(const std::string data) {
	int id = stoi(data);
	database->find(id);
}

void CommandExecutor::del(const std::string data) {
	int id = stoi(data);
	database->del(id);
}

