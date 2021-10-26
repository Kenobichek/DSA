#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void randomPermutation(int *a,int N){
	for(int i = 1;i < N;i++){
		int j = rand() % i;
		swap(a[i],a[j]);
	}
}

bool MySort(int A,int B){
	int tempA = A,tempB = B;
	int sumA = 0,sumB = 0;
	while(tempA != 0){
		sumA += tempA % 10;
		tempA /= 10;
	}
	
	while(tempB != 0){
		sumB += tempB % 10;
		tempB /= 10;
	}
	
	if(sumA % 10 == sumB % 10){
		if(A > B) return true; 
		else return false;
	}
	
	else if(sumA % 10 > sumB % 10){
		return true;
	} 	
	
	else {
		return false;
	}
}

void SelectionSort(int *a,int N){
	for(int i = 0;i < N;i++){
		int mn = a[i];
		int ind = i;
		for(int j = i + 1;j < N;j++){
			if(MySort(a[i],a[j]) && MySort(a[j],mn) == false){
				mn = a[j]; // находим самый минимальный после a[i]
				ind = j;  // и его индекс
			}
		}
		swap(a[i],a[ind]);
	}
}

void InsertionSort(int *a,int N){
	for(int i = 1;i < N;i++){
		for(int j = i;j > 0 && MySort(a[j - 1],a[j]);j--){
			swap(a[j],a[j - 1]);
		}
	}
}

int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	
	int n;
	cout << "Введите размер масива: \n";
	cin >> n;
	
	int *mas = new int[4002]; 
	
	for(int i = 0;i < n;i++){
		mas[i] = i + 1;
	}
	cout << endl;
	randomPermutation(mas,n); // перемешали массив

	cout << "\nКаким алгоритмом вы хотите отсортировать массив (выбором/вставкой): \n";
	cout << "Выбором(1)\nВставкой(2)\n\n";
	int ch;
	do{
		cout << "Введите пожалуйста число 1 или 2\n";
		cin >> ch;
		if(ch == 1) {
			clock_t start1 = clock();
			SelectionSort(mas,n);
		  	clock_t end1 = clock();
			float time1 = (float(end1 - start1)) / CLOCKS_PER_SEC;
			cout << "TIME1: " << time1 << endl;
			cout << "\nОтсортированный Массив:\n";
			for(int i = 0;i < n;i++){
				cout << mas[i] << " ";
			}
		}
		
		if(ch == 2){
			clock_t start2 = clock();
			InsertionSort(mas,n);
		  	clock_t end2 = clock();
			float time2 = (float(end2 - start2)) / CLOCKS_PER_SEC;
			cout << "TIME2: " << time2 << endl;
			cout << "\nОтсортированный Массив:\n";
			for(int i = 0;i < n;i++){
				cout << mas[i] << " ";
			}
		}
	}while(ch != 1 && ch != 2);

	delete [] mas;
	return 0;
}
