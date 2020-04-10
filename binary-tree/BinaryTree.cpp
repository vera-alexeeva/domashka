//============================================================================
// Name        : BinaryTree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

//вспомогательная структура узла дерева

struct Node{
	int value;
	Node *left;
	Node *right;

	Node(int x) {
		right = 0;
		left = 0;
		value = x;
	}
};

//структура "дерево"

struct tree {

	Node *root;

	tree() {
		root = 0;
	}

	//метод обхода дерева и вывода вершин в порядке обхода

	void _visit(Node * x){
		if (x) {
			_visit(x->left);
			cout << x->value << " ";
			_visit(x->right);
		}
	}

	void visit(){
		_visit(root);
	}

	//метод добавления элемента в дерево

	Node * add(int x) {
		if (!root) {
			root = new Node(x);
			return root;
		}
		return search(x, root);
	}

	//метод поиска элемента в дереве

	Node* search(int x, Node * node) {
		if (x == node->value) {
			return node;
		}
		if (x > node->value) {
			if (!node->right) {
				node->right = new Node(x);
				return node->right;
			}
			return search(x, node->right);
		} else {
			if (!node->left) {
				node->left = new Node(x);
				return node->left;
			}
			return search(x, node->left);
		}

	}

	//метод удаления элемента из дерева

	void DeleteNode(int x){
		Node *deleted_node;
		Node *previous;
		Node *t = root;
		while(t->value!=x){
			previous = t;
			if(x>t->value) {
				t = t->right;
			}
			else{
				t = t->left;
			}
		}

		deleted_node = t;

		if(!deleted_node->left && !deleted_node->right){
			delete deleted_node;
			if(x>previous->value) previous->right = 0;
			else previous->left = 0;
		}
		if (deleted_node->left && !deleted_node->right){

			pair<Node *,Node *> mostRight;
			mostRight = MostRight(deleted_node->left);
			if (deleted_node->value > previous->value){
				previous->right = mostRight.first;
			}
			else previous->left = mostRight.first;
			mostRight.second->right = 0;

			pair<Node *,Node *> mostLeft;
			mostLeft = MostLeft(mostRight.first);
			mostLeft.first->left = deleted_node->left;

			delete deleted_node;

		}
		if (!deleted_node->left && deleted_node->right){

			pair<Node *,Node *> mostLeft;
			mostLeft = MostLeft(deleted_node->right);
			mostLeft.second->left = 0;
			if (deleted_node->value>previous->value) {
				previous->right = mostLeft.first;
			}
			else previous->left = mostLeft.first;

			pair<Node *,Node *> mostRight;
			mostRight = MostRight(mostLeft.first);
			mostRight.first->right = mostLeft.second;

			delete deleted_node;
		}
		if (deleted_node->left && deleted_node->right){

			pair<Node *,Node *> mostLeft = MostLeft(deleted_node->right);
			if (deleted_node->value>previous->value) {
				previous->right = mostLeft.first;
			}
			else previous->left = mostLeft.first;
			mostLeft.first->left = deleted_node->left;
			mostLeft.second->left = 0;

			pair<Node *,Node *> mostRight;
			mostRight = MostRight(mostLeft.first);
			mostRight.first->right = deleted_node->right;

			delete deleted_node;
		}
		}


	//нахождение самой левой ноды и предыдущей ноды(всп. функция для ф. DeleteNode)

	pair<Node *,Node*> MostLeft(Node *node){
		Node *previous = node;
		while(node->left){
			previous = node;
			node = node->left;
		}
		pair<Node *,Node *> mostLeft;
		mostLeft.first = node;
		mostLeft.second = previous;
		return mostLeft;
	}

	//нахождение самой правой ноды и предыдущей ноды(всп. функция для ф. DeleteNode)

	pair<Node *,Node*> MostRight(Node *node){
		Node *previous = node;
		while(node->right){
			previous = node;
			node = node->right;
		}
		pair<Node *,Node *> mostRight;
		mostRight.first = node;
		mostRight.second = previous;
		return mostRight;
	}

};


int main() {

	//ввод данных ведётся из файла input.txt

	ifstream fin("input.txt");

	int n;  //n - количество узлов в начальном дереве
	fin >> n;

	tree oak;

	int x;

	Node *t;

	for (int i=0; i<n; i++){
		fin >> x;
		t = oak.add(x);
		x = 0;
	}

	fin.close();

	oak.visit();

	cout << endl;

	t = oak.add(5);

	oak.visit();

	cout << endl;

	//oak.DeleteNode(5);

	oak.visit();

	return 0;
}
