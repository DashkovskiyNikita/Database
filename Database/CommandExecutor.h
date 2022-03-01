#pragma once
#include"Database.h"
#include"CommandReader.h"

class CommandExecutor {
private:
	Database* database;
public:
	CommandExecutor(Database* database);
	void execute(Command command);
private:
	void load(const std::string path);
	void insert(const std::string data);
	void del(const std::string data);
	void print(const std::string data);
	void exp(const std::string path);
	void find(const std::string data);
};
