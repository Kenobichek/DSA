#pragma once

bool random();

struct stipend {
	int size;
	int number;
	bool availability;
};


struct DynamicArray {
	int capacity = 1;
	int realsize = 0;
	const int alpha = 2;
	stipend* innerArray = new stipend[capacity];

	void push_back(stipend data);		// 2.1.1
	stipend pop_back();					// 2.1.2
	stipend get(int n);					// 2.1.3
	int size();							// 2.1.4
	void print();						// 2.1.5
	void push_front(stipend data);		// 2.2.1
	stipend pop_front();				// 2.2.2
};