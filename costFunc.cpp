#include <iostream>
#include <string>
#include <vector>
#include "partprogh.h"

using namespace std;

int costFunc(CellDistArray& Sol, NetMatrix& nmatrix, int Cell1, int Cell2){

	int b1 = 0;
	int c1 = 0;
	int b2 = 0;
	int c2 = 0;

	for (int i = 0; i < nmatrix.getVectorSize(Cell1); i++){
		if (nmatrix.getNet(Cell1,i) != Cell2){
			if (Sol.getCellSet(Cell1) != Sol.getCellSet(nmatrix.getNet(Cell1,i))){
				b1++;
			}
			else{
				c1++;
			}
		}	
	}

	for (int i = 0; i < nmatrix.getVectorSize(Cell2); i++){
		if (nmatrix.getNet(Cell2,i) != Cell1){
			if (Sol.getCellSet(Cell2) != Sol.getCellSet(nmatrix.getNet(Cell2,i))){
				b2++;
			}
			else{
				c2++;
			}
		}
	}

	return b1 - c1 + b2 - c2;
}