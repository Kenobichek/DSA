#pragma once
#include <iostream>
#include <vector>
#include "Data.h"
using namespace std;

struct Node {
	Data data = {0, 0, 0, 0};
	Node* parent = NULL;
	Node* LeftChild = NULL;
	Node* RightChild = NULL;
};

struct twoTrees {											// мы вернем эту структуру с функции split
	Node* root1;
	Node* root2;
};

struct BinarySearchTree{
	Node* root;
	int counter = 0;

	BinarySearchTree() {
		root = NULL;
	}

	bool insert(const Data& data);								// 2 функции для добавления в дерево
	Node* addNode(const Data& value,Node* node,Node* p);

	int size();													// функция для определения размера дерева

	int height();												// 2 функции для определения высоты дерева
	int heightTree(Node* node);	

	bool find(const Data& value);								// 2 функции для поиска элемента в дереве
	Node* findNode(const Data& value, Node* node);

	bool erase(const Data& value);								// функция для удаления элемента в дереве

	Node* minimum(Node* node);									// функция для поиска минимального элемента в дереве
	Node* maximum(Node* node);									// функция для поиска максимального элемента в дереве

	void print();												// 2 функции для вывода элементов в дереве
	void printTree(Node* node);

	int count = 0;												// поиск элементов на промежутке
	int findInRange(const Data& value1, const Data& value2);
	int findInRangeTree(Node* node, const Data& value1, const Data& value2);


	void merge(BinarySearchTree tree1, BinarySearchTree tree2);	// объединения двух деревьев
	void addElementsTree(Node* node, vector<Data>* v);			// добавление всех элементов в дереве в вектор
	void binaryAddition(vector <Data>* v);						// 2 функции добавления элементов из вектора в новое дерево
	void arrayToBST(vector <Data> v, int l, int r);

	void eraseRange(const Data& minObject, const Data& maxObject);	// 2 функции удаления элементов на промежутке
	void eraseInRangeTree(Node* node, const Data& value1, const Data& value2);

	void distributeElements(const Data& object, Node* node, vector <Data>* vecLess, vector <Data>* vecMore); // вспомогательная функция для split
};

twoTrees split(BinarySearchTree tree1, const Data& object);		// разделить дерево 
Node* insertAfterSplit(const Data& value, Node* node, Node* p);
