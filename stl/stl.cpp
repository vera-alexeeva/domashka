//============================================================================
// Name        : stl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {

	ifstream fin("input.txt");

	//n-размер вектора

	int n;
	fin >> n;

	//объявление вектора и ввод значений

	vector <int> a(n);

	for (int i=0; i<n; i++){
		fin >> a[i];
	}

	//сортировка вектора в порядке невозрастания

	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());

	//вывод вектора

	for (int i=0; i<n; i++){
			cout << a[i];
		}

	fin.close();

	return 0;
}
