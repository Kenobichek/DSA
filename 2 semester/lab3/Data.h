#pragma once
#include <iostream>

struct Data {
	int interest;			// ������� �� �������� �� 1 �� 10
	int utility;			// ������� �� �������� �� 1 �� 10
	int complexity;			// ������ ��� ������� ��� ��������� ��������
	int deadline;			// ��� �� ������������� ������
	Data() {
		interest = rand() % 100;
		utility = rand() % 100;
		complexity = rand() % 100;
		deadline = rand() % 100;
	}

	Data(int tmpInterest, int tmpUtility, int tmpComplexity, int tmpDeadline) {
		interest = tmpInterest;
		utility = tmpUtility;
		complexity = tmpComplexity;
		deadline = tmpDeadline;
	}
};

bool operator<(const Data& first, const Data& second);
bool operator>(const Data& first, const Data& second);
bool operator==(const Data& first, const Data& second);
bool myCompare(Data x, Data y);