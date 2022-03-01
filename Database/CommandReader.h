#pragma once
#include<string>
#include<map>
using namespace std;

enum class Type {
	LOAD,ADD,DELETE,SAVE,
	PRINT,EXPORT,FIND
};

struct Command {
	Type type;
	std::string data;
};


class CommandReader {
private:
	map<string, Type> commands = {
				{"load",Type::LOAD },
				{"save",Type::SAVE },
				{"insert",Type::ADD },
				{"del",Type::DELETE },
				{"print",Type::PRINT },
				{"export",Type::EXPORT },
				{"find",Type::FIND }
	};
	Type commandType(const std::string input);
public:
	Command read(const std::string input);
};
