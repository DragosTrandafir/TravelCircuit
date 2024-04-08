#include<iostream>
#include"TravelCircuit.h"
void trip_advisor(int budget, int time, TravelCircuit* travel_circuits, TravelCircuit* new_travel_circuits,int *nr_elem) {
	for(int i=0;i<99;i++)
		for(int j=i+1;j<100;j++)
			if (travel_circuits[i].total_cost() > travel_circuits[j].total_cost()) {
				TravelCircuit aux = travel_circuits[i];
				travel_circuits[i]= travel_circuits[j];
				travel_circuits[j]=aux;
			}
	
	int budget_lim = travel_circuits[0].total_cost();
	int time_lim = travel_circuits[0].total_time();
	for (int i = 1; i < 100; i++)
		if (budget_lim <= budget && time_lim <= time) {
			new_travel_circuits[i-1] = travel_circuits[i-1];
			budget_lim += travel_circuits[i].total_cost();
			time_lim += travel_circuits[i].total_time();
			*nr_elem += 1;
		}
		else break;

}
int main() {
	TravelCircuit t1;
	TravelCircuit* t2 = new TravelCircuit;

	TravelCircuit travel_circuits[100];
	TravelCircuit* new_travel_circuits = new TravelCircuit[100];
	int* nr_elem=new int();
	travel_circuits[0] = t1;
	travel_circuits[1] = *t2;
	for (int i = 2; i < 100; i++)
		travel_circuits[i] = TravelCircuit();
	for (int i = 0; i < 100; i++)
	{
		travel_circuits[i].update_static();
		std::cout <<i<<" "<< travel_circuits[i] << std::endl;
	}
	std::cout<<std::endl;
	std::cout << travel_circuits[99].longest_getter() << std::endl;
	std::cout << travel_circuits[99].m_expensive_getter() << std::endl;
	std::cout << travel_circuits[99].g_distance_getter() << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	trip_advisor(20, 20, travel_circuits, new_travel_circuits, nr_elem);
	for (int i = 0; i < *nr_elem; i++)
		std::cout << new_travel_circuits[i] << std::endl;

	delete t2;
	delete[] new_travel_circuits;
	delete nr_elem;
	return 0;
}   