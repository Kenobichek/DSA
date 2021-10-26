#include <iostream>
#include <stdlib.h>
#include "generate.h"
using namespace std;

long long generateRandLong() {
	long long numb = 0;
	for (int i = 0; i < 15; i++) {
		numb *= 10;
		long long temp = rand() % 10;
		if (i == 0 && temp == 0) {
			temp += 1;
		}
		numb += temp;
	}
	return numb;
}

long long generateNickname() {
	long long numb = 0;
	for (int i = 0; i < 5; i++) {
		numb *= 10;
		long long temp = rand() % 10;
		if (i == 0 && temp == 0) {
			temp += 1;
		}
		numb += temp;
	}
	return numb;
}

string generateRandString() {
	string str = "";
	for (int i = 0; i < 3; i++) {
		str += rand() % 26 + 97;
	}
	return str;
}