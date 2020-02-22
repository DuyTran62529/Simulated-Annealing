#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include "partprogh.h"

using namespace std;

CellDistArray moveFunc(CellDistArray Sol, int cellNum){
	//Random generator setup
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  	default_random_engine generator (seed);
  	uniform_int_distribution<int> dist(0, cellNum-1);

  	int first_rand = dist(generator);
  	int sec_rand = dist(generator);

  	while (Sol.getCellSet(first_rand) == Sol.getCellSet(sec_rand)){
  		sec_rand = dist(generator);
  	}

  	Sol.swapSet(first_rand, sec_rand);

  	return Sol;
}