#pragma once
#include <stdlib.h>
#include "Data.h"

struct binaryTree {
	Data Data;
	int Parent = -1;
	int LeftChild = -1;
	int RightChild = -1;
};

struct PriorityQueue {
	int capacity;
	int realsize;
	binaryTree* innerArray;

	PriorityQueue() {
		capacity = 1;
		realsize = 0;
		innerArray = new binaryTree[capacity];
	}

	~PriorityQueue() {
		delete[] innerArray;
	}
	
	//������ ���������� �� �������� ������
	int getParent(int index);		
	int getLeftChild(int index);
	int getRightChild(int index);


	//������ ��� ������ ���������� �����
	void push(Data Data);
	Data top();
	Data pop();
	int size();
	bool empty();
	void print();


	//������ ��� �������� ���������� �����������(max - heap) ����
	void siftUp(int index);
	void siftDown(int index);
};