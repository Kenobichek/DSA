#include "sort.h"
#include <iostream>

using namespace std;

int getParent(int index) {
	if (index == 0) {
		return -1;
	}
	return ((index - 1) / 2);
}

int getLeftChild(int index) {
	return 2 * index + 1;
}

int getRightChild(int index) {
	return 2 * index + 2;
}

void siftDown(int index,int realsize, Data*&arr) {
	int left = getLeftChild(index);
	int right = getRightChild(index);
	int idSwap = index;

	if (left < realsize && arr[left] > arr[idSwap]) {
		idSwap = left;
	}

	if (right < realsize && arr[right] > arr[idSwap]) {
		idSwap = right;
	}

	if (idSwap != index) {
		swap(arr[index], arr[idSwap]);
		siftDown(idSwap, realsize, arr);
	}
}

void Heapsort(Data *&arr, int N) {
	for (int i = N / 2 - 1; i >= 0; i--) {
		siftDown(i,N,arr);
	}

	for(int i = N - 1; i >= 0;i--){
		swap(arr[0], arr[i]);
		siftDown(0, i, arr);
	}
}

bool MySort(Data A, Data B) {
	if (A > B) {
		return true;
	}

	else {
		return false;
	}
}

void InsertionSort(Data*& arr, int N) {
	for (int i = 1; i < N; i++) {
		for (int j = i; j > 0 && MySort(arr[j - 1], arr[j]); j--) {
			swap(arr[j], arr[j - 1]);
		}
	}
}
