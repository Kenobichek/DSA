#include <iostream>
#include <stdlib.h>
#include "MyHeading.h"
long double loadFactor = 8.5;
long long capacity = 8;

using namespace std;

long long HashTable::hash(long long key) {
	long long a = 8;
	long long b = 9;
	long long p = 9149658775000477;
	return (((a * key + b) % p) % capacity);
}


void HashTable::reasize() {
	DoublyLinkedList* OldbucketsArray = bucketsArray;
	long long pastSize = capacity;
	long long key = 0;
	Data value;

	capacity *= 2;
	bucketsArray = new DoublyLinkedList[capacity];

	quantityTable = 0;

	for (int i = 0; i < pastSize; i++) {
		Node* currentNode = OldbucketsArray[i].head;
		while (currentNode != NULL) {
			insert(currentNode->data.key, currentNode->data.value);
			currentNode = currentNode->next;
		}
	}
	delete[] OldbucketsArray;
}


void HashTable::insert(long long key, Data Data) {
	if (float(size()) / capacity >= loadFactor) {
		reasize();
	}

	long long id = hash(key);

	Node* p = bucketsArray[id].find(key);
	if (p == NULL) {
		bucketsArray[id].insert({ Data,key });
		quantityTable++;
	}
	else {
		bucketsArray[id].replace(p, { Data,key });
	}
}

Node* HashTable::find(long long key) {
	long long id = hash(key);
	return bucketsArray[id].find(key);
}

void HashTable::erase(long long key) {
	long long id = hash(key);
	Node* p = bucketsArray[id].find(key);
	if (p != NULL) {
		bucketsArray[id].erase(key);
		quantityTable--;
	}
	else {
		//cout << "there are no values ​​under this key\n";
	}
}

long long HashTable::size() {
	return quantityTable;
}