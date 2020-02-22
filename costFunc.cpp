#include <iostream>
#include <string>
#include <vector>
#include "partprogh.h"

using namespace std;

int costFunc(CellDistArray& Sol, NetMatrix& nmatrix, int cellNum){

	int r_start = 0;
	int cost = 0;

	for (int col = 0; col < cellNum - 1; col++){
		for (int row = r_start; row < cellNum; row++){
			if (Sol.getCellSet(row) != Sol.getCellSet(col)){
				cost = cost + nmatrix.getNet(row, col);
			}
		}

		r_start++;
	}

	return cost;
}