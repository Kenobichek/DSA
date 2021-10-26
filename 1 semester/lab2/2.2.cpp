#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int perevod(int x){
	int i = 0,otv = 0;
	while(x > 0){
		int var = x % 10;
		otv += (var * pow(7,i));
		i++;
		x /= 10;
	}
	return otv;
}

int main(){
	int n;
	cout << "vvedite chetverichnoye chislo: \n";
	cin >> n;
	cout << "\ndesyatirichnoye chislo: \n";
	cout << perevod(n) << endl;

	return 0;
}
// iz 4 v 10
