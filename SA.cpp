#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include "partprogh.h"

using namespace std;
using namespace std::chrono;

int main(){
	
	//Read in netlist
	string InFile;
	cout << "Input file name (don't include .net): ";
	cin >> InFile;
	NetIn nlist(InFile + ".net");

	int cellNum = nlist.getCellNum();

	//Generate holding objects
	NetMatrix nmatrix(nlist.getNetArray(), cellNum, nlist.getNetNum());
	CellDistArray c_array(cellNum);

	//Next solution holder
	CellDistArray next_sol(cellNum);

	//Best solution holder
	CellDistArray best_sol(cellNum);
	int best_sol_cost = 10000000;

	//Delta cost
	int del_cost;

	//Random generator setup
	unsigned seed = system_clock::now().time_since_epoch().count();
  	default_random_engine generator (seed);
  	uniform_int_distribution<int> dist1(0, cellNum-1);

	//Create random solution
	for (int i = 0; i < (cellNum/2); i++){
		int cell = dist1(generator);
		while (c_array.getCellSet(cell) == 1){
			cell = dist1(generator);
		}
		c_array.setCellSet(cell, 1);
	}

	//Set initial temperature
	double T_0;
	double T;
	cout << "Inital temperature (40000 if unsure): ";
	cin >> T_0;
	T = T_0;

	//Set freezing temperature
	double T_f;
	cout << "Freezing temperature (0.1 if unsure): ";
	cin >> T_f;

	//Set temperature drop rate 
	double drop_rate;
	cout << "Cooling rate (0.95 if unsure): ";
	cin >> drop_rate;

	//Set number of move per temperature
	int moves;
	cout << "Moves per temp (250 if unsure): ";
	cin >> moves;

	//Start program clock 
	auto p_start = high_resolution_clock::now();

	//Simulated annealing
	/*double average_temp_dur = 0;
	double average_move_dur = 0;*/

	while (T > T_f){
		auto t_start = high_resolution_clock::now();
		int temp_loop_count = 1;

		for (int i = 1; i <= moves; i++){

			auto m_start = high_resolution_clock::now();

			next_sol = moveFunc(c_array, cellNum);

			int cost_cur = costFunc(c_array, nmatrix, cellNum);
			int cost_next = costFunc(next_sol, nmatrix, cellNum);
			del_cost = cost_next - cost_cur;

			if (acceptMove(del_cost, T)){
				c_array = next_sol;				

				if (cost_next <= best_sol_cost){
					best_sol = c_array;
					best_sol_cost = cost_next;
				}
			}

			/*auto m_stop = high_resolution_clock::now();
			auto move_dur = duration_cast<microseconds>(m_stop - m_start);
			average_move_dur = (average_move_dur*(i-1) + move_dur.count())/ i;*/
		}
		T = T * drop_rate;

		/*auto t_stop = high_resolution_clock::now();
		auto temp_dur = duration_cast<microseconds>(t_stop - t_start);
		average_temp_dur = (average_temp_dur*(temp_loop_count-1) + temp_dur.count())/ temp_loop_count;
		temp_loop_count++;*/
	}

	//Output
	ofstream OutFile (InFile + "_result.txt");

	cout << best_sol_cost << '\n';
	
	if (OutFile.is_open()){
		OutFile << best_sol_cost << '\n';
	}
	else cout << "Unable to write file" << '\n';

	for (int i = 0; i < cellNum; i++){
		if (best_sol.getCellSet(i) == 0){
			cout << i + 1 << " ";
			
			if (OutFile.is_open()){
				OutFile << i + 1 << " ";
			}
		}
	}

	cout << '\n';
	if (OutFile.is_open()){
		OutFile << '\n';
	}

	for (int i =0; i < cellNum; i++){
		if (best_sol.getCellSet(i) == 1){
			cout << i + 1 << " ";
			
			if (OutFile.is_open()){
				OutFile << i + 1 << " ";
			}
		}
	}

	if (OutFile.is_open()) OutFile.close();

	//Stop program clock
	auto p_stop = high_resolution_clock::now();
	auto p_dur = duration_cast<microseconds>(p_stop - p_start);

	cout << '\n';
	cout << "Program duration: " << p_dur.count() << " ms \n";
	/*cout << "Per temp duration: " << average_temp_dur << " ms \n";
	cout << "Per move duration:  " << average_move_dur << " ms \n";*/

	return 0;
}
