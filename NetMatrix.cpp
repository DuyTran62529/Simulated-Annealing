#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "partprogh.h"

using namespace std;

NetMatrix::NetMatrix(vector <string>& NetArray, int cellNum, int netNum) {
	int net [2];
	int node1;
	int node2;
	this->matrix = vector< vector<int> >(cellNum, vector<int> (cellNum, 0));
	
	for (int i = 0; i < netNum; i++){
		istringstream iss(NetArray[i]);
		iss >> node1;
		iss >> node2;

		if (node1 > node2){
			net[0] = node2;
			net[1] = node1;
		}
		else{
			net[0] = node1;
			net[1] = node2;
		}

		this->matrix[net[1]-1][net[0]-1]++;
	}
}

int NetMatrix::getNet(int row, int col){
	return this->matrix[row][col];
}

NetMatrix::~NetMatrix(){}