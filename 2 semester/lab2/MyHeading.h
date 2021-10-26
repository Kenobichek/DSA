#pragma once
#include <iostream>
#include "Generating.h"
static long long quantityTable = 0;
const int m = 8;

struct Data {
	char teachersName;
	int pairNumber;
	int numberParticipants;
	Data() {
		teachersName = randomLetter();
		pairNumber = rand() % 10;
		numberParticipants = rand() % 10;
	}
	Data(char x, int a, int b) {
		teachersName = x;
		pairNumber = a;
		numberParticipants = b;
	}
};

struct HashNode {
	Data value = {'0', 0, 0};
	long long key;
};

struct Node {
	HashNode data = { { '0',0, 0 }, 0 };
	Node* next = NULL;
	Node* parent = NULL;
};

struct DoublyLinkedList {
	Node* head = NULL;
	Node* tail = NULL;
	int quantity = 0;

	void insert(HashNode Data);
	HashNode erase(long long key);
	Node* find(long long key);
	int size();
	void print();
	void replace(Node* p, HashNode Data);
};

struct HashTable {
	DoublyLinkedList* bucketsArray = new DoublyLinkedList[m];
	void reasize();
	long long hash(long long key);
	void insert(long long key, Data Data);
	Node* find(long long key);
	void erase(long long key);
	long long size();
};
