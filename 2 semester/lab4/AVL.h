#pragma once
#include <iostream>
#include "Data.h"

struct Node {
	Data data = { 0, 0, 0, 0 };
	Node* LeftChild = NULL;
	Node* RightChild = NULL;
	int height = 1;
};

struct AVLTree {
	Node* root;

	AVLTree() {
		root = NULL;
	}

	Node* smallLeftRotate(Node* node);
	Node* smallRightRotate(Node* node);

	bool insert(const Data& data);								// 2 функции для добавления в дерево
	Node* addNode(const Data& value, Node* node);

	int height(Node* node);

	bool find(const Data& value);
	Node* findNode(const Data& value, Node* node);

	void print();												// 2 функции для вывода элементов в дереве
	void printTree(Node* node);
};
