#include <iostream>
#include <string>

using namespace std;

struct Train {
    string nazn;
    int numr;
    int time;
};

int string_compare(string str1,string str2){
    int n = min(str1.length(),str2.length());
    for (int i = 0;i<n;i++){
        if (str1[i]>str2[i]){
            return 1;
            break;
        }
        else if (str2[i]>str1[i]){
            return 2;
            break;
        }
    }
}

int main()
{
    Train rasp[8];

     //чтение переменных

     for (int i = 0;i<8;i++){
        cin >> rasp[i].nazn;
        cin >> rasp[i].numr;
        cin >> rasp[i].time;
     }

     //сортировка массива

     for(int i=0; i<7; i++){
        for(int j=i+1; j<8; j++){
            if(string_compare(rasp[i].nazn,rasp[j].nazn)==1) swap(rasp[i],rasp[j]);
        }
     }

     //вывод отсортированного массива

     for (int i = 0;i<8;i++){
        cout << rasp[i].nazn << ' ';
        cout << rasp[i].numr << ' ';
        cout << rasp[i].time << endl;
     }

     //вывод поездов с временем отправления больше введённого

     int t,k = 0;
     cin >> t;

     for(int i = 0;i<8;i++){
        if (rasp[i].time > t){
            cout << rasp[i].nazn << ' ';
            cout << rasp[i].numr << ' ';
            cout << rasp[i].time << endl;
            k++;
        }
        else if (i==7 && k==0) cout << "There is no train for that time";
     }

    return 0;
}
