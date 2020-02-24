#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>
#include <random>
#include "partprogh.h"

using namespace std;

bool acceptMove(int delCost, double Temp){
	//Random generator setup
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  	default_random_engine generator (seed);
  	uniform_real_distribution<double> dist(0.0, 1.0);

	if (delCost < 0){
		return true;
	}
	else{
		double boltz = pow(2.72, -(delCost/(2.72*Temp)));
		double r = dist(generator);

		if (r < boltz){
			return true;
		}
		else{
			return false;
		}
	}
}