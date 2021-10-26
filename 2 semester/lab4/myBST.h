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

struct twoTrees {											// �� ������ ��� ��������� � ������� split
	Node* root1;
	Node* root2;
};

struct BinarySearchTree{
	Node* root;
	int counter = 0;

	BinarySearchTree() {
		root = NULL;
	}

	bool insert(const Data& data);								// 2 ������� ��� ���������� � ������
	Node* addNode(const Data& value,Node* node,Node* p);

	int size();													// ������� ��� ����������� ������� ������

	int height();												// 2 ������� ��� ����������� ������ ������
	int heightTree(Node* node);	

	bool find(const Data& value);								// 2 ������� ��� ������ �������� � ������
	Node* findNode(const Data& value, Node* node);

	bool erase(const Data& value);								// ������� ��� �������� �������� � ������

	Node* minimum(Node* node);									// ������� ��� ������ ������������ �������� � ������
	Node* maximum(Node* node);									// ������� ��� ������ ������������� �������� � ������

	void print();												// 2 ������� ��� ������ ��������� � ������
	void printTree(Node* node);

	int count = 0;												// ����� ��������� �� ����������
	int findInRange(const Data& value1, const Data& value2);
	int findInRangeTree(Node* node, const Data& value1, const Data& value2);


	void merge(BinarySearchTree tree1, BinarySearchTree tree2);	// ����������� ���� ��������
	void addElementsTree(Node* node, vector<Data>* v);			// ���������� ���� ��������� � ������ � ������
	void binaryAddition(vector <Data>* v);						// 2 ������� ���������� ��������� �� ������� � ����� ������
	void arrayToBST(vector <Data> v, int l, int r);

	void eraseRange(const Data& minObject, const Data& maxObject);	// 2 ������� �������� ��������� �� ����������
	void eraseInRangeTree(Node* node, const Data& value1, const Data& value2);

	void distributeElements(const Data& object, Node* node, vector <Data>* vecLess, vector <Data>* vecMore); // ��������������� ������� ��� split
};

twoTrees split(BinarySearchTree tree1, const Data& object);		// ��������� ������ 
Node* insertAfterSplit(const Data& value, Node* node, Node* p);
