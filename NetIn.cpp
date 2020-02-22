#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "partprogh.h"

using namespace std;

NetIn::NetIn(string FileDir){

	ifstream NetList (FileDir.c_str());

	string InStr;

	if (NetList.is_open()){
		getline(NetList, InStr);
		stringstream(InStr) >> this->c;
		getline(NetList, InStr);
		stringstream(InStr) >> this->n;

		while (getline(NetList,InStr)){
			this->net.push_back(InStr);
		}

		NetList.close();
		cout << "File read successfully" << '\n';		
	}

	else{
		cout << "Error reading file" << '\n';
	}
}

int NetIn::getCellNum(){
	return this->c;
}

int NetIn::getNetNum(){
	return this->n;
}

vector<string>& NetIn::getNetArray(){
	return this->net;
}

NetIn::~NetIn(){}
