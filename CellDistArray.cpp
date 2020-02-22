#include <iostream>
#include <string>
#include <vector>
#include "partprogh.h"

using namespace std;

CellDistArray::CellDistArray(int cellNum){
	this->CellArray = vector<bool>(cellNum, 0);
}

bool CellDistArray::getCellSet(int cell){
	return this->CellArray[cell];
}

void CellDistArray::setCellSet(int cell, bool cellVal){
	this->CellArray[cell] = cellVal;
}

void CellDistArray::swapSet(int c1, int c2){
	bool temp;

	temp = this->CellArray[c1];
	this->CellArray[c1] = this->CellArray[c2];
	this->CellArray[c2] = temp;
}

CellDistArray::~CellDistArray(){}
