#include<iostream>
#include"CommandReader.h"
#include"CommandExecutor.h"
#include"Database.h"
#include"DBUtils.h"
#include"DBFile.h"

using namespace std;


int main()
{
	Database* database = new Database();
	CommandReader commandReader;
	CommandExecutor commandExecutor(database);
	
	while (true) {
		string input;
		getline(cin, input);
		auto command = commandReader.read(input);
		commandExecutor.execute(command);
	}
}

