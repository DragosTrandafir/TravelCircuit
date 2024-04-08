#include<iostream>
using namespace std;
#pragma once
class Trip
{
public:
	Trip();
	Trip(int pdistance,int pprice,int ptime);

	int dist_getter() const;
	int price_getter() const;
	int time_getter() const;

	void dist_setter(int d) ;
	void price_setter(int p) ;
	void time_setter(int t);

	friend Trip operator<(const Trip& t1, const Trip& t2);
	friend ostream& operator<<(ostream& os, const Trip& t1);
private:
	int distance;
	int price;
	int time;
};

