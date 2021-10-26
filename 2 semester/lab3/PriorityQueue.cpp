#include "PriorityQueue.h"
#include <iostream>
using namespace std;

int PriorityQueue::getParent(int index) {
	if (index == 0) {
		return -1;
	}
	return ((index - 1) / 2);
	//return (int(floor((index * 1.0 - 1) / 2)));
}

int PriorityQueue::getLeftChild(int index) {
	return 2 * index + 1;
}

int PriorityQueue::getRightChild(int index) {
	return 2 * index + 2;
}

void PriorityQueue::push(Data Data) {
	if (realsize == capacity) {
		capacity *= 2;
		binaryTree* old = innerArray;

		innerArray = new binaryTree[capacity];

		for (int i = 0; i < realsize; i++) {
			innerArray[i] = old[i];
		}

		delete[] old;
	}
	
	innerArray[realsize].Data = Data;
	innerArray[realsize].Parent = getParent(realsize);
	innerArray[realsize].LeftChild = getLeftChild(realsize);
	innerArray[realsize].RightChild = getRightChild(realsize);
	siftUp(realsize);
	realsize++;
}

Data PriorityQueue::top() {
	if (empty() != 0) {
		return innerArray[0].Data;
	}
	return {0,0,0,0};
}

Data PriorityQueue::pop() {
	if (empty()) {
		Data deleted = innerArray[0].Data;
		realsize--;
		swap(innerArray[0].Data, innerArray[realsize].Data);
		siftDown(0);
		return deleted;
	}
	return {0,0,0,0};
}

int PriorityQueue::size() {
	return realsize;
}

bool PriorityQueue::empty() {
	return (size() > 0);
}

void PriorityQueue::print() {
	for (int i = 0; i < realsize; i++) {
		cout << "index: " << i << " " << "Data { " << innerArray[i].Data.interest << " " << innerArray[i].Data.utility << " " << innerArray[i].Data.complexity << " " << innerArray[i].Data.deadline << " }"<< endl;
	}
}

void PriorityQueue::siftUp(int index) {
	int idParent = innerArray[index].Parent;
	while (index != 0 && innerArray[index].Data > innerArray[idParent].Data) {
		swap(innerArray[index].Data, innerArray[idParent].Data);
		index = idParent;
		idParent = innerArray[index].Parent;
	}
}

void PriorityQueue::siftDown(int index) {
	
	int left = getLeftChild(index);
	int right = getRightChild(index);
	int idSwap = index;

	if (left < realsize && innerArray[left].Data > innerArray[idSwap].Data) {
		idSwap = left;
	}

	if (right < realsize && innerArray[right].Data > innerArray[idSwap].Data) {
		idSwap = right;
	}

	if (idSwap != index) {
		swap(innerArray[index].Data, innerArray[idSwap].Data);
		siftDown(idSwap);
	}
}
