//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

	string ip;
	int dots, i = 0, chisla[4], k = 0;
	bool flag = true;

	for(int j = 0;j<4;j++){
			chisla[j] = -1;
		}

	ifstream fin("input.txt");
	fin >> ip;
	fin.close();

	while(ip[i]!=0 && flag){
		switch (ip[i])
		{
		case '0':
			chisla[k] = chisla[k]*10+0;
			break;
		case '1':
			chisla[k] = chisla[k]*10+1;
			break;
		case '2':
			chisla[k] = chisla[k]*10+2;
			break;
		case '3':
			chisla[k] = chisla[k]*10+3;
			break;
		case '4':
			chisla[k] = chisla[k]*10+4;
			break;
		case '5':
			chisla[k] = chisla[k]*10+5;
			break;
		case '6':
			chisla[k] = chisla[k]*10+6;
			break;
		case '7':
			chisla[k] = chisla[k]*10+7;
			break;
		case '8':
			chisla[k] = chisla[k]*10+8;
			break;
		case '9':
			chisla[k] = chisla[k]*10+9;
			break;
		case '.':
			dots++;
			k++;
			break;
		default:
			flag = false;
			break;
		}
		i++;
		if (dots!=3) flag = false;

	}

	for(int j = 0;j<4;j++){
		if(chisla[j]>=256 || chisla[j]==-1) flag = false;
	}

	if (flag) cout << "It is true IP";
	else cout << "It is not IP";

	return 0;
}
