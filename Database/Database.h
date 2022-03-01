#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct RoomForSale {
	int id;
	std::string date;
	int price;
	int count;
	int floor;
	int square;
	std::string adrees;
};

class Database {
private:
	std::vector<RoomForSale> data;
public:
	void load(const std::vector<RoomForSale> data);
	void insert(const RoomForSale newRoom);
	void del(const int id);
	void print();
	void print(const int roomCount);
	vector<RoomForSale> exp();
	void find(const int id);
	int lastID();
};
