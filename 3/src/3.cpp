//============================================================================
// Name        : 3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct SetOfStacks{

	vector < stack <int>* > l;
	int maximum;
	int currentStack;

	SetOfStacks(int n){
		maximum = n;
		currentStack = -1;
	}

	int popAt(int x){
		int t = 0;
		if (currentStack!=-1){
			if(l[x]->empty()) return -1;
			else{
			t = l[x]->top();
			l[x]->pop();
			return t;
			}
		}
		return -1;
	}

	void push_(int x){
		if (currentStack==-1) {
			l.push_back(new stack <int>);
			currentStack = 0;
			l[0]->push(x);
		}
		else {
			if (l[currentStack]->size()==maximum){
				l.push_back(new stack <int>);
				currentStack+=1;
				l[currentStack]->push(x);
			}
			else{
				l[currentStack]->push(x);
			}
		}
	}

	int pop_(){
		if(l[currentStack]->empty()){
			if(currentStack == 0) return -1;
			else{
				--currentStack;
				return popAt(currentStack);
			}
		}
		else{
			return popAt(currentStack);
		}
	}
};

int main() {

	int n = 10;
	//cin >> n;

	SetOfStacks dishes(n);

	for(int i = 0; i<16; i++){
		dishes.push_(i);
	}

	//cout << dishes.popAt(1) << endl;

	for(int i = 0; i<16; i++){
		cout << dishes.pop_() << endl;
	}
	return 0;
}
