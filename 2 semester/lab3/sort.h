#pragma once
#include "Data.h"

void Heapsort(Data*& arr, int N);
void InsertionSort(Data*& arr, int N);
int getParent(int index);
int getLeftChild(int index);
int getRightChild(int index);