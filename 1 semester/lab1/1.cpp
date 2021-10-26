#include <iostream>
#include <math.h>

using namespace std;

int main(){
	float Px1, Py1, Px2, Py2;
	cin >> Px1 >> Py1 >> Px2 >> Py2;
	cout << sqrt(pow((Px2 - Px1),2) + pow((Py2 - Py1),2));
	return 0;
}
