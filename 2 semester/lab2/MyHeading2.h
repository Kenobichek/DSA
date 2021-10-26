#pragma once
#include <iostream>
#include "Generating.h"
static long long quantityTable2 = 0;
const int m = 8;
using namespace std;

struct Data2 {
	char teachersName;
	int pairNumber;
	int numberParticipants;
	Data2() {
		teachersName = randomLetter();
		pairNumber = rand() % 10;
		numberParticipants = rand() % 10;
	}
	Data2(char x, int a, int b) {
		teachersName = x;
		pairNumber = a;
		numberParticipants = b;
	}
};

struct HashNode2 {
	Data2 value = { '0', 0, 0 };
	string key;
};

struct Node2 {
	HashNode2 data;
	Node2* next = NULL;
	Node2* parent = NULL;
};

struct DoublyLinkedList2 {
	Node2* head = NULL;
	Node2* tail = NULL;
	int quantity = 0;

	void insert(HashNode2 Data);
	HashNode2 erase(string* key);
	Node2* find(string* key);
	int size();
	void print();
	void replace(Node2* p, HashNode2 Data);
};

struct HashTable2 {
	DoublyLinkedList2* bucketsArray2 = new DoublyLinkedList2[m];
	void reasize();
	long long hash(string* key);
	void insert(string* key, Data2 Data);
	Node2* find(string* key);
	void erase(string* key);
	long long size();
};