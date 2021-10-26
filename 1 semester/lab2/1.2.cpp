#include<iostream>
#include<math.h>
#include <time.h> 
using namespace std;
bool resheto[10000000];

void ertsfn(){
  resheto[0] = 1;
  resheto[1] = 1;
  for(int i = 2;i <= floor(sqrt(10000000));i++){
  	if(resheto[i] == 0){
  		for(int j = i * i;j < 10000000;j += i){
  			resheto[j] = 1;	
		}	
	}
  }
}

int main(){
	int ind1,ind2;
	cout << "vvedite pervyy indeks: \n";
	cin >> ind1;
	cout << "vvedite druhyy indeks: \n";
	cin >> ind2;
	clock_t start = clock();
	ertsfn();
	int kol = 0,dob = 1;
	for(int i = 0;;i++){
		if(resheto[i] == 0) kol++;
		if(kol == ind1 && dob == 1) dob *= i;
		if(kol == ind2){
			dob *= i;
			break;
		} 
	}
	cout << "OTVET: " << dob << endl;
	
	clock_t end = clock();
	
    float time = (float(end - start)) / CLOCKS_PER_SEC;
    cout << "TIME: " << time << endl;
	
	return 0;
}
