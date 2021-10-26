#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "testBST.h"
#include "Data.h"
#include "generate.h"
#include "myBST.h"

bool additionalTask() {

    srand(time(NULL));

	BinarySearchTree myTree1;
	BinarySearchTree myTree2;
    BinarySearchTree myTree3;

	const int iters = 10000;
    const int keysAmount = iters * 2;

    vector<Data> data(keysAmount);
    vector<Data> dataToInsert1(iters);
    vector<Data> dataToInsert2(iters);

    vector<pair<Data, Data>> dataToRangeQueries;

    for (int i = 0; i < iters; i++)
    {
        dataToInsert1[i] = data[generateRandLong() % keysAmount];
        dataToInsert2[i] = data[generateRandLong() % keysAmount];
    }

    for (int i = 0; i < iters; i++)
    {
        myTree1.insert(dataToInsert1[i]);
        myTree2.insert(dataToInsert2[i]);
    }

    clock_t mergeStart = clock();
    myTree3.merge(myTree1, myTree2);
    clock_t mergeEnd = clock();

    Data tmp1 = Data();
    Data tmp2 = Data();
    cout << "SIZE BEFORE ERASE RANGE: " << myTree3.size() << endl;
    cout << "SIZE BEFORE - FIND(ERASE RANGE): " << myTree3.size() - myTree3.findInRange(min(tmp1, tmp2), max(tmp1, tmp2)) << endl;
    
    clock_t eraseRangeStart = clock();
    myTree3.eraseRange(min(tmp1,tmp2), max(tmp1, tmp2));
    clock_t eraseRangeEnd = clock();

    cout << "SIZE AFTER ERASE RANGE: " << myTree3.size() << endl << endl;

    Data tmp3 = Data();

    clock_t clockSplitStart = clock();
    twoTrees tree2 = split(myTree3, tmp3);
    clock_t clockSplitEnd = clock();

    /*
    myTree3.print();
    cout << "\nroot1\n";
    myTree3.printTree(tree2.root1);
    cout << "root2\n";
    myTree3.printTree(tree2.root2);*/

    float mergeTime = (float(mergeEnd - mergeStart)) / CLOCKS_PER_SEC;
    float eraseRangeTime = (float(eraseRangeEnd - eraseRangeStart)) / CLOCKS_PER_SEC;
    float clockSplitTime = (float(clockSplitEnd - clockSplitStart)) / CLOCKS_PER_SEC;

    cout << "Merge: " << endl;
    cout << "Time: " << mergeTime << endl;
    cout << "EraseRange: " << endl;
    cout << "Time: " << eraseRangeTime << endl;
    cout << "Split: " << endl;
    cout << "Time: " << clockSplitTime << endl << endl << endl;

	return true;
}