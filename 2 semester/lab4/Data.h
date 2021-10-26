#pragma once
#include <iostream>
#include "generate.h"

using namespace std;

struct Data {
	long long nickname;			// ������ �'��� ��������
	int rank;					// ���� �� 0 �� 100 
	int amountOfExperience;		// ������� ������ �� 0 �� 10000
	int sizeDonut;				// ����� ������ �� 0 �� 10000
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