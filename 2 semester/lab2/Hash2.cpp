#include <iostream>
#include <stdlib.h>
#include "MyHeading2.h"
long double loadFactor2 = 1.5;
long long capacity2 = 8;

using namespace std;

long long HashTable2::hash(string* key) {
	string tmp = *key;
	return ((int(tmp[0]) * 89) % capacity2);
	//return 0;
}

void HashTable2::reasize() {
	DoublyLinkedList2* OldbucketsArray = bucketsArray2;
	long long pastSize = capacity2;
	string key = "";
	Data2 value;

	capacity2 *= 2;
	bucketsArray2 = new DoublyLinkedList2[capacity2];

	quantityTable2 = 0;

	for (int i = 0; i < pastSize; i++) {
		Node2* currentNode = OldbucketsArray[i].head;
		while (currentNode != NULL) {
			insert(&currentNode->data.key, currentNode->data.value);
			currentNode = currentNode->next;
		}
	}
	delete[] OldbucketsArray;
}


void HashTable2::insert(string* key, Data2 Data) {
	if (float(size()) / capacity2 >= loadFactor2) {
		reasize();
	}

	long long id = hash(key);

	Node2* p = bucketsArray2[id].find(key);
	if (p == NULL) {
		bucketsArray2[id].insert({ Data,*key});
		quantityTable2++;
	}
	else {
		bucketsArray2[id].replace(p, { Data,*key });
	}
}

Node2* HashTable2::find(string* key) {
	long long id = hash(key);
	return bucketsArray2[id].find(key);
}

void HashTable2::erase(string* key) {
	long long id = hash(key);
	Node2* p = bucketsArray2[id].find(key);
	if (p != NULL) {
		bucketsArray2[id].erase(key);
		quantityTable2--;
	}
	else {
		//cout << "there are no values ​​under this key\n";
	}
}

long long HashTable2::size() {
	return quantityTable2;
}