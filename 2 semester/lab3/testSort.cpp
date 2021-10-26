#include <iostream>
#include <algorithm>
#include <ctime>
#include "tests.h"
#include "sort.h"

using namespace std;

void testSortPriorityQueue() {
    const int iters = 100000;

    
    Data* myArray1 = new Data[iters];   // будемо сортувати купою Heapsort
    Data* myArray2 = new Data[iters];   // будемо сортувати бібліотечним STL std::sort()
    Data* myArray3 = new Data[iters];   // будемо сортувати ставкою

    for (int i = 0; i < iters; i++) {
        int randData1 = rand() % 2000 - 1000;
        int randData2 = rand() % 2000 - 1000;
        int randData3 = rand() % 2000 - 1000;
        int randData4 = rand() % 2000 - 1000;

        myArray1[i] = {randData1, randData2, randData3, randData4};
        myArray2[i] = {randData1, randData2, randData3, randData4};
        myArray3[i] = { randData1, randData2, randData3, randData4 };
    }
   
    

    clock_t timeStart = clock();
    Heapsort(myArray1, iters);
    clock_t timeEnd = clock();

    float time1 = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;


    timeStart = clock();
    sort(myArray2, myArray2 + iters);
    timeEnd = clock();

    float time2 = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;


    timeStart = clock();
    InsertionSort(myArray3, iters);
    timeEnd = clock();

    float time3 = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;

    for (int i = 0; i < iters; i++) {
        if (!(myArray1[i] == myArray2[i] && myArray1[i] == myArray3[i])) {
            cout << "Arrays are different\n";
            break;
        }
    }

    cout << "Heapsort time:" << endl;
    cout << "Time: " << time1 << endl;
    cout << "STL sort time:" << endl;
    cout << "Time: " << time2 << endl;
    cout << "Insertion sort time:" << endl;
    cout << "Time: " << time3 << endl << endl << endl;

    delete[] myArray1;
    delete[] myArray2;
    delete[] myArray3;
}