//============================================================================
// Name        : bankomat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {

	//массив со всеми возможными значениями купюр

	int bills[6] = {500, 200, 100, 50, 20, 10};

	//ввод ведётся из файла
	ifstream fin("input.txt");

	int n; //n - сумма которую надо выдать
	fin >> n;

	int current_n = n; //current_n - нерасчитанная сумма на каждом повторении цикла
	int counter = 0; //counter - счётчик использованных купюр

	//на каждом круге цикла выбирается купюра с максимально возможным значением

	while(current_n>bills[5]){
		for(int i = 0; i<6; i++){
			if (bills[i]<=current_n){
				current_n -= bills[i];
				counter++;
			}
		}
	}

	if (current_n) cout << "-1";
	else cout << counter;

	return 0;
}
