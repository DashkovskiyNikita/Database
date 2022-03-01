#include<iostream>
#include<vector>
#include<string>
#include"Database.h"
#include"DBUtils.h"


void Database::load(const std::vector<RoomForSale> _data) {
	data = _data;
};

void Database::insert(const RoomForSale newRoom) {
	data.push_back(newRoom);
}

void Database::del(const int id) {
	for (auto it = data.begin(); it != data.end(); ++it) {
		if (id == it->id) {
			data.erase(it);
			break;
		}
	}
}

void Database::print() {
	for (auto room : data) {
		output(room, ",");
	}
}

void Database::print(const int roomCount) {
	for (auto room : data) {
		if (room.count == roomCount) {
			output(room, ",");
		}
	}
}

vector<RoomForSale> Database::exp() {
	return data;
}

void Database::find(const int id) {
	RoomForSale r1;
	for (auto room : data) {
		if (room.id == id) r1 = room;
	}
	for (auto r2 : data) {
		if (isSuit(r1, r2)) {
			output(r2, ",");
			break;
		}
	}
}

int Database::lastID() {
	return data.size() - 1;
}