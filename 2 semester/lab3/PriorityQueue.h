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
	
	//методи переміщення по бінарному дереву
	int getParent(int index);		
	int getLeftChild(int index);
	int getRightChild(int index);


	//методи для роботи пріоритетної черги
	void push(Data Data);
	Data top();
	Data pop();
	int size();
	bool empty();
	void print();


	//методи для підтримки властивості незростаючої(max - heap) купи
	void siftUp(int index);
	void siftDown(int index);
};