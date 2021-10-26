#include <iostream>
using namespace std;

double funk(double x){
	return x * x * x - 2 * x * x + x - 1;
}

int main(){

	double max = -3200000;

	for(double i = -3;i <= 4;i += 0.5){
		double f = funk(i);
		if(f > max) max = f;
	}

	cout << max;

	return 0;
}

