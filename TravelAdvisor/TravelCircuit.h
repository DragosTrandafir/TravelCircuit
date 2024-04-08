#include<iostream>
using namespace std;
#include "Trip.h"
#pragma once
class TravelCircuit
{
public:
	TravelCircuit();
	TravelCircuit& operator=(const TravelCircuit& other);
	TravelCircuit(int prandom_number, Trip ptrips[11]);

	int total_cost() const;
	int total_dist() const;
	int total_time() const;
	void update_static();

	int random_nr_getter() const;
	Trip trips_getter() const;

	TravelCircuit longest_getter() const;
	TravelCircuit m_expensive_getter() const;
	TravelCircuit g_distance_getter() const;

	friend std::ostream& operator<<(std::ostream& os, const TravelCircuit& t1);
private:
	Trip trips[11];
	int random_number;
	static TravelCircuit longest;
	static TravelCircuit m_expensive;
	static TravelCircuit g_distance;
};

