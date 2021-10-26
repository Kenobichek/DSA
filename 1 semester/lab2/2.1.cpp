#include<iostream>
#include<math.h>

using namespace std;

int perevod(int x){
	int i = 0,otv = 0;
	while(x > 0){
		int var = x % 4;
		otv += (var * pow(7,i));
		i++;
		x /= 4;
	}
	return otv;
}

int main(){
	cout << "vvedite desyatirichnoye chislo: \n";
	int n;
	cin >> n;
	cout << "\nchetverichnoye chislo: \n";
	cout << perevod(n);
	return 0;
}
// iz 10 v 4
