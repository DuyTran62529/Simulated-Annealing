#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include "partprogh.h"

using namespace std;

CellDistArray moveFunc(CellDistArray Sol, int Cell1, int Cell2){
	
  Sol.swapSet(Cell1, Cell2);

  return Sol;
}