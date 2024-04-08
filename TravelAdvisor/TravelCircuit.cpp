#include "TravelCircuit.h"
#include<iostream>
#include<cstdlib>

TravelCircuit TravelCircuit::longest= TravelCircuit();
TravelCircuit TravelCircuit::m_expensive= TravelCircuit();
TravelCircuit TravelCircuit::g_distance= TravelCircuit();

TravelCircuit::TravelCircuit() {
	random_number = 1 + rand() % (10 - 1 + 1);
	for (int i = 1; i <= random_number; i++) {
		int random_distance = 1 + rand() % (10 - 1 + 1);

		int random_price = 1 + rand() % (10 - 1 + 1);


		int random_time = 1 + rand() % (10 - 1 + 1);

		this->trips[i] = Trip(random_distance, random_price, random_time);
	}
}

TravelCircuit& TravelCircuit::operator=(const TravelCircuit& other)
{
	if (&other != this) {
		for (int i = 1; i <= other.random_number; i++)
			this->trips[i] = other.trips[i];
		this->random_number = other.random_number;
	}
	return *this;
}
TravelCircuit::TravelCircuit(int prandom_number, Trip ptrips[11]) :random_number{ prandom_number } {
	for (int i = 1; i <= random_number; i++)
		this->trips[i] = trips[i];
}
int TravelCircuit::total_cost() const {
	int s = 0;
	for (int i = 1; i <= this->random_number; i++)
		s += trips[i].price_getter();
	return s;

}
int TravelCircuit::total_dist() const {
	int s = 0;
	for (int i = 1; i <= this->random_number; i++)
		s += trips[i].dist_getter();
	return s;
}
int TravelCircuit::total_time() const {
	int s = 0;
	for (int i = 1; i <= this->random_number; i++)
		s += trips[i].time_getter();
	return s;
}

void TravelCircuit::update_static() {
	if (this->total_time() > longest.total_time()) {
		longest = *this;
	}
	if (this->total_cost() > m_expensive.total_cost()) {
		m_expensive = *this;
	}
	if (this->total_dist() > g_distance.total_dist())
		g_distance = *this;
}

int TravelCircuit::random_nr_getter() const {
	return this->random_number;

}

Trip TravelCircuit::trips_getter() const {
	return this->trips[this->random_number];
}

TravelCircuit TravelCircuit::longest_getter() const
{
	return longest;
}

TravelCircuit TravelCircuit::m_expensive_getter() const
{
	return m_expensive;
}

TravelCircuit TravelCircuit::g_distance_getter() const
{
	return g_distance;
}


std::ostream& operator<<(std::ostream& os2, const TravelCircuit& t1)
{
	os2 << "Number of Travel objects: " << t1.random_number << std::endl;
	for (int i = 1; i <= t1.random_number; i++)
		std::cout<< t1.trips[i] << std::endl;
	return os2;
}
