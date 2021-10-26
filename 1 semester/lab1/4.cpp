#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n
	int mas[n];
	for(int i = 0; i < n; i++){
		cin >> mas[i];
		if(i > 0){
			if(mas[i] >= mas[i - 1]){
			 	cout << "NO";
			 	return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}

