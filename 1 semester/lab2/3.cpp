#include<iostream>
#include<math.h>
using namespace std;

int rec(int x){
	if(x == 0){
		return 0;
	}
	else {
		int m = x % 10;
		int n1 = rec(x / 10);
		return max(m,n1);
   }
}

int main(){
	cout << "vvedite lyuboye chislo: \n";
	int n;
	cin >> n;
	cout << "maksimal'naya tsifra: \n";
	cout << rec(n);
}

