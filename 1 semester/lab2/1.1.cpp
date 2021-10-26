#include<iostream>
#include<math.h>
#include <time.h> 
using namespace std;

bool isPrime(int x){
	if(x == 1 || x < 0 || x == 0) return false;
	for(int i = 2;i <= floor(sqrt(x));i++){
		if(x % i == 0) return false;
	}
	return true;
}

int main(){
	int ind1,ind2;
	//cout << "vvedite pervyy indeks: \n";
	//cin >> ind1;
	//cout << "vvedite druhyy indeks: \n";
	//cin >> ind2;
	clock_t start = clock();
	int kol = 0;
	for(int i = 2;i < 10000000;i++){
		if(isPrime(i)){
			if(kol <= 100){
				cout << i << " ";
				kol++;
			}
		} 
	}
	
	clock_t end = clock();
	
    float time = (float(end - start)) / CLOCKS_PER_SEC;
    cout << "TIME: " << time << endl;
	
	return 0;
}
