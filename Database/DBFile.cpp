#include"DBFile.h"
#include<fstream>
#include<sstream>

void DBFile::write(const string path, const vector<RoomForSale> data) {
	ofstream out(path);
	if (out.is_open()) {
		for (auto value : data) {
			out << value.id << ' ';
			out << value.date << ' ';
			out << value.price << ' ';
			out << value.count << ' ';
			out << value.floor << ' ';
			out << value.square << ' ';
			out << value.adrees << "\n";
		}
		out.close();
	}
}

vector<RoomForSale> DBFile::read(const string path) {
	ifstream in(path);
	vector<RoomForSale> result;
	if (in.is_open()) {
		string value;
		while (getline(in, value)) {
			istringstream stream(value);
			vector<string> data;
			while (stream >> value) { data.push_back(value); }
			auto newTable = RoomForSale{
				stoi(data[0]),
				data[1],
				stoi(data[2]),
				stoi(data[3]),
				stoi(data[4]),
				stoi(data[5]),
				data[6]
			};
			result.push_back(newTable);
		}
		in.close();
	}
	return result;
}