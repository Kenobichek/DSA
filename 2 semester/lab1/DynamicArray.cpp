#include <iostream>
#include "dynamArrayFunk.h"

using namespace std;

struct stipend;

int capacity = 1;
int realsize = 0;
const int alpha = 2;
stipend* innerArray = new stipend[capacity];

bool random() {
	return rand() % 2 == 0 ? true : false;
}

void DynamicArray::push_back(stipend data) {
	if (realsize == capacity) {
		capacity *= alpha;
		stipend* newArr = new stipend[capacity];

		for (int i = 0; i < realsize; i++) {
			newArr[i] = innerArray[i];
		}

		delete[] innerArray;
		innerArray = newArr;
	}
	innerArray[realsize] = data;
	realsize++;
}

stipend DynamicArray::pop_back() {
	stipend deleted = innerArray[realsize - 1];
	realsize--;
	return deleted;
}

stipend DynamicArray::get(int n) {
	if (n > size() || n <= 0) {
		cout << "element outside the array\n";
	}
	else {
		return innerArray[n - 1];
	}
}

int DynamicArray::size() {
	return realsize;
}

void DynamicArray::print() {
	for (int i = 0; i < realsize; i++) {
		cout << innerArray[i].size << " " << innerArray[i].number << " " << innerArray[i].availability << endl;
	}
}

void DynamicArray::push_front(stipend data) {
	if (realsize == capacity) {
		capacity *= alpha;

		stipend* newArr = new stipend[capacity];

		for (int i = 1; i <= realsize; i++) {
			newArr[i] = innerArray[i - 1];
		}

		newArr[0] = data;
		delete[] innerArray;
		innerArray = newArr;
	}
	else {
		for (int i = realsize; i > 0; i--) {
			innerArray[i] = innerArray[i - 1];
		}
		innerArray[0] = data;
	}
	realsize++;
}

stipend DynamicArray::pop_front() {
	stipend deleted = innerArray[0];
	realsize--;
	for (int i = 0; i < realsize; i++) {
		innerArray[i] = innerArray[i + 1];
	}
	//realsize--;
	return deleted;
}