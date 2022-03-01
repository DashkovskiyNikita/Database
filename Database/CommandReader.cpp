#include"CommandReader.h"
#include<vector>
#include<sstream>

Type CommandReader::commandType(const std::string input) {
	auto it = commands.find(input);
	if (it != commands.end()) return commands[input];
	else throw std::invalid_argument("Unknown command: " + input);
}

Command CommandReader::read(const std::string input) {
	std::vector<string> operands;
	istringstream stream(input);
	std::string value;
	while (stream >> value) operands.push_back(value);
	Type type = commandType(operands[0]);
	std::string operand = operands.size() < 2 ? "" : operands[1];
	return Command{ type,operand };
}