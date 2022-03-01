#include"DBUtils.h"
#include<iostream>
#include<cmath>
using namespace std;

void output(const RoomForSale value, const std::string divider = "") {
	cout << value.id << divider;
	cout << value.date << divider;
	cout << value.price << divider;
	cout << value.count << divider;
	cout << value.floor << divider;
	cout << value.square << divider;
	cout << value.adrees << "\n";
}

bool isSuit(const RoomForSale r1, const RoomForSale r2) {
	if (r1.count == r2.count && r1.floor == r2.floor && r1.id != r2.id) {
		int diff = abs(r1.square - r2.square);
		return (r1.square * 0.01 * diff <= 20);
	}
	else return false;
}