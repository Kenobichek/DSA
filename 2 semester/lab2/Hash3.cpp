#include <iostream>
#include <stdlib.h>
#include "MyHeading3.h"
long double loadFactor3 = 0.5;
long long capacity3 = 8;
long long m1 = 9;
using namespace std;

long long HashTable3::hash(long long key) {
	return (key % capacity3);
}

long long HashTable3::h1(long long key) {
	return (key % capacity3);
}

long long HashTable3::h2(long long key) {
	return ((2 * (key % 10)) + 1);
	//1 + (k mod(m - 1))
}

void HashTable3::reasize() {
	long long pastSize = capacity3;
	capacity3 *= 2;

	HashNode3* newArr = new HashNode3[capacity3];
	swap(newArr, bucketsArray3);
	//quantityTable3 = 0;

	for (int i = 0; i < pastSize; i++) {
		bucketsArray3[i] = newArr[i];
	}

	delete[] newArr;
}


bool HashTable3::insert(long long key, Data3 Data) {
	//cout << "h1 " << h1 << " h2 " << h2 << endl;
	//cout << "o\n";
	if (float(size()) / capacity3 >= loadFactor3) {
		//cout << "UGU\n";
		reasize();
	}

	long long i = 0;
	long long hi = (h1(key) + i * h2(key)) % capacity3;

	HashNode3* ID = find(key);
	//long long id = hash(key);
	//cout << id << " " ;
	if (ID == NULL) {
		//cout << "TUT\n";
		//cout << bucketsArray3[id].value.available << "\n\n";
		if (bucketsArray3[hi].value.available == availble::empty || bucketsArray3[hi].value.available == availble::deleted) {
			//cout << "A\n";
			bucketsArray3[hi].value = Data;
			bucketsArray3[hi].value.available = availble::filled;
			bucketsArray3[hi].key = key;
			quantityTable3++;
			//cout << "size: " << size() << endl;
			return 0;
		}
		else {
			while (1) {
				//cout << "A\n";
				i++;
				hi = (h1(key) + i * h2(key)) % capacity3;
				//cout << hi << " ";
				if (bucketsArray3[hi].value.available == availble::empty || bucketsArray3[hi].value.available == availble::deleted) {
					bucketsArray3[hi].value = Data;
					bucketsArray3[hi].value.available = availble::filled;
					bucketsArray3[hi].key = key;
					quantityTable3++;
					//cout << "size: " << size() << endl;
					return 0;
				}
			}
		}
	}
	else {
		ID->value = Data;
		ID->value.available = availble::filled;
		//bucketsArray3[ID].value = Data;
		//bucketsArray3[ID].value.available = 1;
		return 0;
	}
	return 0;
}

HashNode3* HashTable3::find(long long key) {
	//cout << "FIND\n";
	long long i = 0;
	long long hi = (h1(key) + i * h2(key)) % capacity3;
	long long h0 = hi;
	//cout << "hi " << hi << " capacity " << capacity3 << endl;
	//cout << bucketsArray3[hi].key << " " << bucketsArray3[hi].value.teachersName << endl;
	//long long ID = id;
	if (bucketsArray3[hi].key == key && bucketsArray3[hi].value.available == availble::filled) {
		return &bucketsArray3[hi];
	}

	if (bucketsArray3[hi].key == key && bucketsArray3[hi].value.available == availble::deleted) {
		return NULL;
	}

	//else if
	while (1) {
		//cout << "A\n";
		i++;
		hi = (h1(key) + i * h2(key)) % capacity3;
		//cout << bucketsArray3[hi].key << " " << bucketsArray3[hi].value.teachersName << endl;
		if (h0 == hi) {
			//cout << "MB\n";
			return NULL;
		}

		if (bucketsArray3[hi].key == key && bucketsArray3[hi].value.available == availble::filled) {
			return &bucketsArray3[hi];
		}

		if (bucketsArray3[hi].key == key && bucketsArray3[hi].value.available == availble::deleted) {
			return NULL;
		}
	}
	//return id;
}

void HashTable3::erase(long long key) {
	//long long id = hash(key);
	HashNode3* id = find(key);
	if (id != NULL) {
		id->value.available = availble::deleted;
		id->key = 0;
		//bucketsArray3[id].value.available = 0;
		//bucketsArray3[id].key = 0;
		quantityTable3--;
	}
}


long long HashTable3::size() {
	return quantityTable3;
}

void HashTable3::print() {
	for (int i = 0; i < capacity3; i++) {
		cout << bucketsArray3[i].value.available << " " << bucketsArray3[i].value.teachersName << endl;
	}
}