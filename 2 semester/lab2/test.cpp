#include <time.h>
#include <unordered_map>
#include "MyHeading.h"
#include "Generating.h"
#include "test.h"
using namespace std;

bool testHashTable()
{
    //srand(time(NULL));

    const int iters = 500000;
    const int keysAmount = iters * 1;

    // generate random keys:
    long long* keys = new long long[keysAmount];

    long long* keysToInsert = new long long[iters];
    long long* keysToErase = new long long[iters];
    long long* keysToFind = new long long[iters];

    for (int i = 0; i < keysAmount; i++)
    {
        keys[i] = generateRandLong();
    }
    for (int i = 0; i < iters; i++)
    {
        keysToInsert[i] = keys[generateRandLong() % keysAmount];
        keysToErase[i] = keys[generateRandLong() % keysAmount];
        keysToFind[i] = keys[generateRandLong() % keysAmount];
    }

    // test my HashTable:
    HashTable hashTable;

    clock_t myStart = clock();
    clock_t myStart1 = clock();
    for (int i = 0; i < iters; i++)
    {
        hashTable.insert(keysToInsert[i], Data());
    }
    clock_t myEnd1 = clock();

    long long myInsertSize = hashTable.size();

    clock_t myStart2 = clock();
    for (int i = 0; i < iters; i++)
    {
        hashTable.erase(keysToErase[i]);
    }
    clock_t myEnd2 = clock();

    long long myEraseSize = hashTable.size();
    int myFoundAmount = 0;

    clock_t myStart3 = clock();
    for (int i = 0; i < iters; i++)
    {
        if (hashTable.find(keysToFind[i]) != NULL)
        {
            myFoundAmount++;
        }
    }
    clock_t myEnd3 = clock();

    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;

    // test STL hash table:
    unordered_map<long long, Data> unorderedMap;

    clock_t stlStart = clock();
    clock_t myStart4 = clock();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.insert({ keysToInsert[i], Data() });
    }
    clock_t myEnd4 = clock();

    long long stlInsertSize = unorderedMap.size();
    clock_t myStart5 = clock();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.erase(keysToErase[i]);
    }
    clock_t myEnd5 = clock();

    long long stlEraseSize = unorderedMap.size();
    int stlFoundAmount = 0;
    clock_t myStart6 = clock();

    for (int i = 0; i < iters; i++)
    {
        if (unorderedMap.find(keysToFind[i]) != unorderedMap.end())
        {
            stlFoundAmount++;
        }
    }
    clock_t myEnd6 = clock();

    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;

    float myInsert = (float(myEnd1 - myStart1)) / CLOCKS_PER_SEC;
    float myErase = (float(myEnd2 - myStart2)) / CLOCKS_PER_SEC;
    float myFind = (float(myEnd3 - myStart3)) / CLOCKS_PER_SEC;

    float myInsert1 = (float(myEnd4 - myStart4)) / CLOCKS_PER_SEC;
    float myErase2 = (float(myEnd5 - myStart5)) / CLOCKS_PER_SEC;
    float myFind3 = (float(myEnd6 - myStart6)) / CLOCKS_PER_SEC;

    cout << "My HashTable:" << endl;
    cout << "Time: " << myTime << ", size: " << myInsertSize << " - " << myEraseSize << ", found amount: " << myFoundAmount << endl;
    cout << "INSERT: " << myInsert << endl;
    cout << "ERASE: " << myErase << endl;
    cout << "FIND: " << myFind << endl;

    cout << "\nSTL unordered_map:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlInsertSize << " - " << stlEraseSize << ", found amount: " << stlFoundAmount << endl << endl;
    cout << "INSERT: " << myInsert1 << endl;
    cout << "ERASE: " << myErase2 << endl;
    cout << "FIND: " << myFind3 << endl;
    delete[] keys;
    delete[] keysToInsert;
    delete[] keysToErase;
    delete[] keysToFind;

    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount == stlFoundAmount)
    {
        cout << "The lab is completed\n\n\n\n";
        return true;
    }

    cerr << ":(" << endl;

    return false;
}