#include <iostream>
#include <vector>

#include "AVL.h"

using namespace std;

bool testAVL() {
    const int iters = 8000;
    const int keysAmount = iters * 2;
    const int itersToRangeQueries = 1000;

    vector<Data> data(keysAmount);

    vector<Data> dataToInsert(iters);
    vector<Data> dataToErase(iters);
    vector<Data> dataToFind(iters);
    vector<pair<Data, Data>> dataToRangeQueries;

    for (int i = 0; i < iters; i++)
    {
        dataToInsert[i] = data[generateRandLong() % keysAmount];
        dataToFind[i] = data[generateRandLong() % keysAmount];
    }

    for (int i = 0; i < itersToRangeQueries; i++)
    {
        Data minData = Data();
        Data maxData = Data();

        if (maxData < minData)
        {
            swap(minData, maxData);
        }
        dataToRangeQueries.push_back({ minData, maxData });
    }

    AVLTree myTree;

    clock_t myStart = clock();

    for (int i = 0; i < iters; i++){
        myTree.insert(dataToInsert[i]);
    }

    clock_t myEnd = clock();

    float InsertTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;

    cout << "Time Insert AVL: "  << InsertTime << endl ;

    myStart = clock();
    for (int i = 0; i < iters; i++)
    {
        if (myTree.find(dataToFind[i]))
        {
            //myFoundAmount++;
        }
    }

    myEnd = clock();

    float FindTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;

    cout << "Time Find AVL: " << FindTime << endl << endl;

	/*for (int i = 0; i < 1000; i++) {
		myTree.insert(Data());
	}*/
	//myTree.insert({0,30,0,0});
	//myTree.insert({ 0,40,0,0 });
	//myTree.insert({ 0,50,0,0 });

	//myTree.print();
	return true;
}