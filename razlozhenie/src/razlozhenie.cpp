//============================================================================
// Name        : razlozhenie.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int most_l = 0, min, c_from;;

	int summa[n];

	for (int i = 1;i<=n;i++){
		summa[0] = i;
		for (int j = 1;j<n;j++){
			if(j<=n-i) summa[j] = 1;
			else summa[j] = 0;
		}
		min = i;
		c_from = n-i;
		while(most_l != c_from){
			for(int i1 = 0;i1<=n-i;i1++){
				if (summa[i1]<min && summa[i1]<i) {
					min = summa[i1];
					most_l = i1;
				}
			}
			if(summa[most_l] + summa[c_from]<=i){
				summa[most_l] += summa[c_from];
				summa[c_from] = 0;
			}
			c_from -= 1;
			for(int g = 0;g<=n-i;g++)
				cout << summa[g] << '+';
			cout << endl;
		}
	}

	return 0;
}
