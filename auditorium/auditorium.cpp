//============================================================================
// Name        : auditorium.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//структура лекции с полями: время начала; время конца

struct lecture {
	int left;
	int right;
};

bool comp(lecture x, lecture y){
	return (x.left<y.left);
}

int main() {

	ifstream fin("input.txt");

	int n;
	fin >> n;

	//вектор со списком расписания занятий учитилей

	vector <lecture> rasp(n);

	for (int i = 0; i<n; i++){
		fin >> rasp[i].left >> rasp[i].right;
	}

	fin.close();

	//сортировка вектора в порядке неубывания времени начала лекции

	sort(rasp.begin(), rasp.end(), comp);

	int k = 0;
	int t = 0;

	//вектор временных рамок последней лекции для каждой аудитории

	vector <lecture> rasp_of_aud(n);

	for (int i = 0; i<n; i++){
			rasp_of_aud[i].left = 0;
			rasp_of_aud[i].right = 0;
		}

	//заполнение вектора лекций в аудиториях

	for (int i = 0; i<n; i++){
		if (rasp[i].left < rasp_of_aud[k].right) {
			t = 0;
			for (int j = 0; j<=k; j++){
				if(rasp[i].left >= rasp_of_aud[j].right){
					t++;
					rasp_of_aud[j].left = rasp[i].left;
					rasp_of_aud[j].right = rasp[i].right;
				}
			}
			if (!t){
				k++;
				rasp_of_aud[k].left = rasp[i].left;
				rasp_of_aud[k].right = rasp[i].right;
			}
		}
		else {
			rasp_of_aud[k].left = rasp[i].left;
			rasp_of_aud[k].right = rasp[i].right;
		}
	}

	cout << k+1;

	return 0;
}
