//============================================================================
// Name        : stl_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

//структура ученика

struct student{
	string surname;
	string name;
	int math;
	int phy;
	int inf;
};

//создание компаратора для сортировки вектора учеников

bool comp(pair<student,float> firstEl, pair<student,float> lastEl){
	return (firstEl.second<lastEl.second)? true : false;
}

int main() {

	ifstream fin ("input.txt");

	//n - размер вектора учеников

	int n;
	fin >> n;

	//создание вектора учеников

	vector < pair<student,float> > a(n);

	//ввод данных об учениках

	for (int i=0; i<n; i++){
		fin >> a[i].first.name;
		fin >> a[i].first.surname;
		fin >> a[i].first.math;
		fin >> a[i].first.phy;
		fin >> a[i].first.inf;
		a[i].second = (a[i].first.math+a[i].first.phy+a[i].first.inf)/3;
	}

	//сортировка вектора впорядке убывания

	stable_sort (a.begin(),a.end(),comp);

	//вывод имён и фамилий учеников

	for (int i=0; i<n; i++){
		cout << a[i].first.name << " " << a[i].first.surname << endl;
	}

	fin.close();

	return 0;
}
