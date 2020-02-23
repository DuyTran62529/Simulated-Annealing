#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "partprogh.h"

using namespace std;

NetMatrix::NetMatrix(vector <string>& NetArray, int cellNum, int netNum) {
	int node1;
	int node2;

	this->matrix = vector< vector<int> >(cellNum, vector<int> (0, 0));

	for (int i = 0; i < netNum; i++){
		istringstream iss(NetArray[i]);
		iss >> node1;
		iss >> node2;

		this->matrix[node1-1].push_back(node2-1);
		this->matrix[node2-1].push_back(node1-1);
	}
}

int NetMatrix::getNet(int row, int col){
	return this->matrix[row][col];
}

int NetMatrix::getVectorSize(int cell){
	return this->matrix[cell].size();
}
NetMatrix::~NetMatrix(){}