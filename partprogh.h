#ifndef PARTPROGH_H
#define PARTPROGH_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NetIn {
public:
	NetIn(string FileDir);
	~NetIn();
	int getCellNum();
	int getNetNum();
	vector<string>& getNetArray();
private:
	int c;
	int n;
	vector<string> net;
};

class NetMatrix {
public:
	NetMatrix(vector<string>& NetArray, int cellNum, int netNum);
	~NetMatrix();
	int getNet(int row, int col);

private:
	vector< vector<int> > matrix;
};

class CellDistArray {
public:
	CellDistArray(int cellNum);
	~CellDistArray();
	bool getCellSet(int cell);
	void setCellSet(int cell, bool cellVal);
	void swapSet(int c1, int c2);

private:
	vector<bool> CellArray;
};

CellDistArray moveFunc(CellDistArray Sol, int cellNum);

int costFunc(CellDistArray& Sol, NetMatrix& nmatrix, int cellNum);

bool acceptMove(int delCost, double Temp);

#endif
