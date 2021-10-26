#pragma once
#include <iostream>
#include "generate.h"

using namespace std;

struct Data {
	long long nickname;			// нікнейм п'яти цифровий
	int rank;					// ранг від 0 до 100 
	int amountOfExperience;		// кількість досвіду від 0 до 10000
	int sizeDonut;				// розмір донату від 0 до 10000
	Data() {
		nickname = generateNickname();
		rank = rand() % 100;
		amountOfExperience = rand() % 10000;
		sizeDonut = rand() % 10000;
	}

	Data(long long tmpNickname, int tmpRank, int tmpAmountOfExperience, int tmpSizeDonut) {
		nickname = tmpNickname;
		rank = tmpRank;
		amountOfExperience = tmpAmountOfExperience;
		sizeDonut = tmpSizeDonut;
	}
};

bool operator<(const Data& first, const Data& second);
bool operator>(const Data& first, const Data& second);
bool operator<=(const Data& first, const Data& second);
bool operator>=(const Data& first, const Data& second);
bool operator==(const Data& first, const Data& second);