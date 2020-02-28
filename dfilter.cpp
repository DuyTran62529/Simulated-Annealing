#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream CostIn ("Cost.txt");
	ifstream AccIn ("Accepted move.txt");
	ifstream ItIn ("Iteration.txt");

	ofstream CostOut ("C_ft.txt");
	ofstream AccOut ("Ac_ft.txt");
	ofstream ItOut ("I_ft.txt");

	string temp1, temp2, temp3;
	int i = 0;

	while (getline(CostIn,temp1)){
		if (i == 0){
			CostOut << temp1 << '\n';
		}

		i++;

		if (i == 111){
			i = 0;
		}
	}

	i = 0;

	while (getline(AccIn,temp2)){
		if (i == 0){
			AccOut << temp2 << '\n';
		}

		i++;

		if (i == 111){
			i = 0;
		}
	}

	i = 0;

	while (getline(ItIn,temp3)){
		if (i == 0){
			ItOut << temp3 << '\n';
		}

		i++;

		if (i == 111){
			i = 0;
		}
	}

	i = 0;

	CostIn.close();
	AccIn.close();
	ItIn.close();
	CostOut.close();
	AccOut.close();
	ItOut.close();

	return 0;

}