#include <iostream>

using namespace std;

int main(){

	int dob = 1;

	for(int i = 10; i <= 99; i++) {
		if(i % 2 != 0 && i % 13 == 0) {
			dob *= i;
		}
	}

	cout << dob;

	return 0;
}

