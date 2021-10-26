#pragma once
#include <iostream>

struct Data {
	int interest;			// інтерес до завдання від 1 до 10
	int utility;			// користь від завдання від 1 до 10
	int complexity;			// скільки днів потрібно для виконання завдання
	int deadline;			// днів до встановленого терміну
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