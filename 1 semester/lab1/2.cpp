#include <iostream>
#include <math.h>

using namespace std;

int main(){

	float a,b;

	cin >> a >> b;
	
	if (a == 0 && b == 0) cout << "The equation has many roots!!!";

	else if(a == 0) cout << "There are no roots!!!";

	else cout << -b / a;

	return 0;
}


