//============================================================================
// Name        : horse_.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int main () {

	int n;
	int m;
	cin >> n >> m;

	//создание поля n x m; n - кол-во строк, m - кол-во столбцов

	//vector<vector<int> > pole (n, vector<int>(m));

	int **pole = new int * [n];
	for (int i = 0; i<n; i++)
		pole[i] = new int [m];

	for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				pole[i][j] = 0;

	//начальное состояние

	pole[0][0] = 1;
	pole[1][2] = 1;
	pole[2][1] = 1;

	//прямой пересчёт

	for (int i=2; i<31; i++){
		for (int j=2; j<34; j++){
			pole[i][j] = pole[i-1][j-2] + pole[i-2][j-1];
		}
	}

	//вывод ответа: ответ находится в ячейке pole[n-1][m-1]

	cout << pole[n-1][m-1];

	return 0;
}

