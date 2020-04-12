
#include <iostream>
#include <vector>

using namespace std;

int main () {

	int n, m;
	cin >> n >> m;

	//создание поля n x m; n - кол-во строк, m - кол-во столбцов

	vector<vector<int> > pole (n, vector<int>(m, 0));

	//начальное состояние

	pole[0][0] = 1;
	pole[1][2] = 1;
	pole[2][1] = 1;

	//прямой пересчёт

	for (int i=2; i<n; i++){
		for (int j=2; j<m; j++){
			pole[i][j] = pole[i-1][j-2] + pole[i-2][j-1];
		}
	}

	//вывод ответа: ответ находится в ячейке pole[n][m]

	cout << pole[n][m];

	return 0;
}
