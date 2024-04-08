#include "Trip.h"
#include<iostream>

Trip::Trip() {
	this->distance = 1;
	this->price = 1;
	this->time = 1;
}
Trip::Trip(int pdistance, int pprice, int ptime) :distance{ pdistance }, price{ pprice }, time{ ptime } {

}
int Trip::dist_getter() const {
	return this->distance;
}
int Trip::price_getter() const {
	return this->price;
}
int Trip::time_getter() const {
	return this->time;
}

void Trip::dist_setter(int d) {
	if (d > 0)
		this->distance = d;
	else
		std::cout << "Error";
}
void Trip::price_setter(int p) {
	this->price = p;
}
void Trip::time_setter(int t) {
	if(t>0)
	 this->time = t;
	else
		std::cout << "Error";
}
Trip operator<(const Trip& t1, const Trip& t2) {
	if (t1.price_getter() == t2.price_getter()) {
		if (t1.dist_getter() < t2.dist_getter())
			return t2;
		else if (t1.dist_getter() > t2.dist_getter())
			return t1;
		else {
			if (t1.time_getter() < t2.time_getter())
				return t2;
			else if (t1.time_getter() > t2.time_getter())
				return t1;
		}
	}
	else if (t1.price_getter() < t2.price_getter())
		return t2;
	else
		return t1;
}
ostream& operator<<(ostream& os, const Trip& t1) {
	os << "Distance: "<<t1.dist_getter() << " Price " << t1.price_getter() << " Time " << t1.time_getter() << "  ";
	return os;
}