#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <time.h> 
#include "dynamArrayFunk.h"
#include "linkedListFunk.h"
using namespace std;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	DoublyLinkedList stipendListSingly;
	for (int i = 0; i < 20; i++) {
		stipendListSingly.push_back({ rand() % 2000,i + 1,random() });
	}
	stipendListSingly.print();

	for (int i = 0; i < 21; i++) {
		stipendListSingly.pop_back();
	}

	stipendListSingly.print();
	DynamicArray* myArray = new DynamicArray();

	clock_t Start = clock();

	//додати 50000 елементів в кінець
	clock_t step1Start = clock();
	for (int i = 0; i < 50000; i++) {
		myArray->push_back({rand() % 2000, i + 1, random() });
	}
	clock_t step1End = clock();

	//додати 10000 елементів в початок
	clock_t step2Start = clock();
	for (int i = 0; i < 10000; i++) {
		myArray->push_front({rand() % 2000, i + 50000, random()});
	}
	clock_t step2End = clock();

	//зчитати 20000 елементів під випадковими індексами
	clock_t step3Start = clock();
	for (int i = 0; i < 20000; i++) {
		myArray->get(rand() % 60000 + 1);
	}
	clock_t step3End = clock();

	//видалити 5000 елементів з початку
	clock_t step4Start = clock();
	for (int i = 0; i < 5000; i++) {
		myArray->pop_front();
	}
	clock_t step4End = clock();

	//видалити 5000 елементів з кінця
	clock_t step5Start = clock();
	for (int i = 0; i < 5000; i++) {
		myArray->pop_back();
	}
	clock_t step5End = clock();

	clock_t End = clock();

	cout << "DYNAMIC ARRAY: \n";
	float step1Time = (float(step1End - step1Start)) / CLOCKS_PER_SEC;
	cout << "1 крок -> додати  50000 елементiв в кiнець   " << step1Time << endl;

	float step2Time = (float(step2End - step2Start)) / CLOCKS_PER_SEC;
	cout << "2 крок -> додати  10000 елементiв в початок  " << step2Time << endl;

	float step3Time = (float(step3End - step3Start)) / CLOCKS_PER_SEC;
	cout << "3 крок -> зчитати 20000 елементiв пiд випадковими iндексами " << step3Time << endl;

	float step4Time = (float(step4End - step4Start)) / CLOCKS_PER_SEC;
	cout << "4 крок -> видалити 5000 елементiв з початку " << step4Time << endl;

	float step5Time = (float(step5End - step5Start)) / CLOCKS_PER_SEC;
	cout << "5 крок -> видалити 5000 елементiв з кiнця   " << step5Time << endl;

	float time = (float(End - Start)) / CLOCKS_PER_SEC;
	cout << "TIME: " << time << endl;

	delete[] myArray;
	//-----------------------------------------------------------------------------------------------------------

	SinglyLinkedList stipendListSingly;

	Start = clock();

	//додати 50000 елементів в кінець
	step1Start = clock();
	for (int i = 0; i < 50000; i++) {
		stipendListSingly.push_back({rand() % 2000,i + 1,random()});
	}
	step1End = clock();


	//додати 10000 елементів в початок
	step2Start = clock();
	for (int i = 0; i < 10000; i++) {
		stipendListSingly.push_back({rand() % 2000,i + 50000,random()});
	}
	step2End = clock();


	//зчитати 20000 елементів під випадковими індексами
	step3Start = clock();
	for (int i = 0; i < 20000; i++) {
		stipendListSingly.get(rand() % 60000 + 1);
	}
	step3End = clock();


	//видалити 5000 елементів з початку
	step4Start = clock();
	for (int i = 0; i < 5000; i++) {
		stipendListSingly.pop_front();
	}
	step4End = clock();


	//видалити 5000 елементів з кінця
	step5Start = clock();
	for (int i = 0; i < 5000; i++) {
		stipendListSingly.pop_back();
	}
	step5End = clock();
	End = clock();

	cout << "\n\nSINGLY LINKED LIST: \n";
	step1Time = (float(step1End - step1Start)) / CLOCKS_PER_SEC;
	cout << "1 крок -> додати  50000 елементiв в кiнець   " << step1Time << endl;

	step2Time = (float(step2End - step2Start)) / CLOCKS_PER_SEC;
	cout << "2 крок -> додати  10000 елементiв в початок  " << step2Time << endl;

	step3Time = (float(step3End - step3Start)) / CLOCKS_PER_SEC;
	cout << "3 крок -> зчитати 20000 елементiв пiд випадковими iндексами " << step3Time << endl;

	step4Time = (float(step4End - step4Start)) / CLOCKS_PER_SEC;
	cout << "4 крок -> видалити 5000 елементiв з початку " << step4Time << endl;

	step5Time = (float(step5End - step5Start)) / CLOCKS_PER_SEC;
	cout << "5 крок -> видалити 5000 елементiв з кiнця   " << step5Time << endl;

	time = (float(End - Start)) / CLOCKS_PER_SEC;
	cout << "TIME: " << time << endl;

	//-----------------------------------------------------------------------------------------------------------

	DoublyLinkedList stipendListDoubly;

	Start = clock();

	//додати 50000 елементів в кінець
	step1Start = clock();
	for (int i = 0; i < 50000; i++) {
		stipendListDoubly.push_back({ rand() % 2000,i + 1,random() });
	}
	step1End = clock();


	//додати 10000 елементів в початок
	step2Start = clock();
	for (int i = 0; i < 10000; i++) {
		stipendListDoubly.push_back({ rand() % 2000,i + 50000,random() });
	}
	step2End = clock();


	//зчитати 20000 елементів під випадковими індексами
	step3Start = clock();
	for (int i = 0; i < 20000; i++) {
		stipendListDoubly.get(rand() % 60000 + 1);
	}
	step3End = clock();


	//видалити 5000 елементів з початку
	step4Start = clock();
	for (int i = 0; i < 5000; i++) {
		stipendListDoubly.pop_front();
	}
	step4End = clock();


	//видалити 5000 елементів з кінця
	step5Start = clock();
	for (int i = 0; i < 5000; i++) {
		stipendListDoubly.pop_back();
	}
	step5End = clock();
	End = clock();

	cout << "\n\nDOUBLY LINKED LIST: \n";
	step1Time = (float(step1End - step1Start)) / CLOCKS_PER_SEC;
	cout << "1 крок -> додати  50000 елементiв в кiнець   " << step1Time << endl;

	step2Time = (float(step2End - step2Start)) / CLOCKS_PER_SEC;
	cout << "2 крок -> додати  10000 елементiв в початок  " << step2Time << endl;

	step3Time = (float(step3End - step3Start)) / CLOCKS_PER_SEC;
	cout << "3 крок -> зчитати 20000 елементiв пiд випадковими iндексами " << step3Time << endl;

	step4Time = (float(step4End - step4Start)) / CLOCKS_PER_SEC;
	cout << "4 крок -> видалити 5000 елементiв з початку " << step4Time << endl;

	step5Time = (float(step5End - step5Start)) / CLOCKS_PER_SEC;
	cout << "5 крок -> видалити 5000 елементiв з кiнця   " << step5Time << endl;

	time = (float(End - Start)) / CLOCKS_PER_SEC;
	cout << "TIME: " << time << endl;
	
	return 0;
}