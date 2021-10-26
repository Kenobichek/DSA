#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void randomPermutation(int *a){
	for(int i = 1;i < 4002;i++){
		int j = rand() % i;
		swap(a[i],a[j]);
	}
}

int line(int *a,int N,int S){
	for(int i = 0;i < N;i++){
		if(a[i] == S) return i;
	}
	return -1;
}

int bin(int *a,int N,int Val){
	int l_border = 0;
	int r_border = N;
	int mid = (r_border + l_border) / 2;

	while(r_border - l_border > 1){
		if(a[mid] == Val){
			return mid;	
		} 
		else if(a[mid] > Val){
			r_border = mid;
			mid = (r_border + l_border) / 2;
		} 
		else if(a[mid] < Val){
			l_border = mid; 
			mid = (r_border + l_border) / 2;
		}
	}
	return -1;
}

int binrec(int *a,int l_border,int r_border,int Val){
	if(r_border >= l_border){
		int mid = (r_border + l_border) / 2;
		
		if(a[mid] > Val){
			return binrec(a,l_border,mid - 1,Val);
		}
	
   		if(a[mid] < Val){
			return binrec(a,mid + 1,r_border,Val);
		}
		else return mid;
	}
	return -1;
}

void bubble(int *a,int N){
	for(int obh = 0;obh < N;obh++){
		for(int i = 0;i < N - obh;i++){
			if(a[i] > a[i + 1]){
				int temp;
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
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
	
	for(int i = 0;i < 4002;i++){
	    mas[i] = rand() % 4000 - 2000;
	}
	
	//randomPermutation(mas); // перемешали массив
	
	bubble(mas,n); // алгоритм пузырьковой сортировки

	cout << "Введите элемент, индекс которого вы хотите найти: \n";
	int MyVar;
	cin >> MyVar;
	
	cout << "\nЛинейный поиск: \n";
	clock_t start1 = clock();
	float perc = 0;
	int it = 0;
	while(it < 100000){
		if(line(mas,n,rand() % 4000 - 2000) != -1) perc += 1;
		it++;
	}
	
	
	cout << "ID = " << line(mas,n,MyVar) << "\nВероятность: " << perc / 100000 << endl;
   	clock_t end1 = clock();
	float time1 = (float(end1 - start1)) / CLOCKS_PER_SEC;
	cout << "TIME: " << time1 << endl;
    
	clock_t start2 = clock();
 	cout << "\nБинарный поиск: \n";
	perc = 0;
	it = 0;
	while(it < 100000){
		if(bin(mas,n,rand() % 4000 - 2000) != -1) perc += 1;
		it++;
	}
 	
	cout << "ID = " << bin(mas,n,MyVar) << "\nВероятность: " << perc / 100000 << endl;
	clock_t end2 = clock();
	float time2 = (float(end2 - start2)) / CLOCKS_PER_SEC;
    cout << "TIME: " << time2 << endl;
    
    
 	clock_t start3 = clock();
 	cout << "\nБинарный поиск (рекурсия): \n";
	perc = 0;
	it = 0;
	while(it < 100000){
		if(binrec(mas,0,n,rand() % 4000 - 2000) != -1) perc += 1;
		it++;
	}

	cout << "ID = " << binrec(mas,0,n,MyVar) << "\nВероятность: " << perc / 100000 << endl;
	clock_t end3 = clock();
	float time3 = (float(end3 - start3)) / CLOCKS_PER_SEC;
    cout << "TIME: " << time3 << endl;
    
    cout << "\nМассив со случайными числами: \n";
	for(int i = 0;i < n;i++){
		cout << mas[i] << " ";
	}
	
	delete [] mas;
	return 0;
}
