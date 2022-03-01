#pragma once
#include<iostream>
#include"Database.h"

using namespace std;

class DBFile {
public:
	void write(const string path, const vector<RoomForSale> data);
	vector<RoomForSale> read(const string path);
};
