//============================================================================
// Name        : Queue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

//вспомогательная структура ячейки очереди

struct Node {
	Node *next;
	Node *previous;
	int value;
};

//структура очереди

struct queue{

	Node *start = 0;
	Node *end = 0;


	//конструктор

	queue(){
		start = 0;
		end = 0;
	}

	//диструктор

	~queue(){
		delete start;
		delete end;
	}

	//добавления элемента в конец

	void push(int x){
		Node *a = new Node;
		a->value = x;
		if (start == 0){
			start = a;
			end = a;
			a->previous = 0;
			a->next = 0;
		}
		else {
			a->previous = end;
			end->next = a;
			end = a;
			a->next = 0;
		}
	}

	//удаление первого элемента

	void pop(){
		start = start->next;
		delete start->previous;
		start->previous = 0;
	}

	//проверка очереди на пустоту

	bool empty() {
		return (start == end == 0);
	}

	//взятие первого элемента очереди

	int front(){
		return start->value;
	}

	//взятие последнего элемента

	int back (){
		return end->value;
	}

	//определение размера очереди

	int size (){
		Node *t = start;
		int k = 0;
		while(t){
			t = t->next;
			k++;
		}
		return k;
	}

	//вывод очереди

	void print(){
		Node *t = start;
		while(t){
			cout << t->value << " ";
			t = t->next;
		}
	}

};

int main() {

	//ввод данных ведётся из файла input.txt

	ifstream fin ("input.txt");

	queue d;

	int n; //n - длина очереди
	fin >> n;
	int x;
	for (int i = 0; i<n; i++){
		fin >> x;
		d.push(x);
	}

	fin.close();

	d.print();

	cout << endl;

	cout << d.front() << " " << d.back() << " " << d.size() << endl;

	d.push(0);

	d.pop();

	d.print();

	return 0;
}
