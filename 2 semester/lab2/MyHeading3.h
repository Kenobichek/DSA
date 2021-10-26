#pragma once
#include <iostream>
#include "Generating.h"
static long long quantityTable3 = 0;
const int m = 8;
using namespace std;

enum availble {
	empty,
	deleted,
	filled
};

struct Data3 {
	char teachersName;
	int pairNumber;
	int numberParticipants;
	availble available = availble::empty;
	Data3() {
		teachersName = randomLetter();
		pairNumber = rand() % 10;
		numberParticipants = rand() % 10;
		availble available = availble::empty;
	}
	Data3(char x, int a, int b) {
		teachersName = x;
		pairNumber = a;
		numberParticipants = b;
		availble available = availble::empty;
	}
};

struct HashNode3 {
	Data3 value = { '0', 0, 0 };
	long long key = 0;
};

struct HashTable3 {
	HashNode3* bucketsArray3 = new HashNode3[m];
	void reasize();
	long long hash(long long key);
	long long h1(long long key);
	long long h2(long long key);
	bool insert(long long key, Data3 Data);
	HashNode3* find(long long key);
	void erase(long long key);
	long long size();
	void print();
};
