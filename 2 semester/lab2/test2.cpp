#include <time.h>
#include <unordered_map>
#include "MyHeading2.h"
#include "Generating.h"
#include "test.h"

using namespace std;

bool test2HashTable()
{
    
    srand(time(NULL));

    const int iters = 10000;
    const int keysAmount = iters * 1;

    // generate random keys:

    string* keysToInsert = new string[iters];
    string* keysToErase = new string[iters];
    string* keysToFind = new string[iters];

   
    for (int i = 0; i < iters; i++)
    {
        keysToInsert[i] = generateRandString();
        keysToErase[i] = generateRandString();
        keysToFind[i] = generateRandString();
    }

    // test my HashTable:
    HashTable2 hashTable;

    clock_t myStart = clock();
    for (int i = 0; i < iters; i++)
    {
        hashTable.insert(&keysToInsert[i], Data2());
    }

    long long myInsertSize = hashTable.size();

    for (int i = 0; i < iters; i++)
    {
        hashTable.erase(&keysToErase[i]);
    }

    long long myEraseSize = hashTable.size();
    int myFoundAmount = 0;
    for (int i = 0; i < iters; i++)
    {
        if (hashTable.find(&keysToFind[i]) != NULL)
        {
            myFoundAmount++;
        }
    }

    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;

    // test STL hash table:
    unordered_map<string, Data2> unorderedMap;

    clock_t stlStart = clock();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.insert({ keysToInsert[i], Data2() });
    }

    long long stlInsertSize = unorderedMap.size();
    for (int i = 0; i < iters; i++)
    {
        unorderedMap.erase(keysToErase[i]);
    }
    long long stlEraseSize = unorderedMap.size();
    int stlFoundAmount = 0;
    for (int i = 0; i < iters; i++)
    {
        if (unorderedMap.find(keysToFind[i]) != unorderedMap.end())
        {
            stlFoundAmount++;
        }
    }
    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;

    cout << "My HashTable:" << endl;
    cout << "Time: " << myTime << ", size: " << myInsertSize << " - " << myEraseSize << ", found amount: " << myFoundAmount << endl;
    cout << "STL unordered_map:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlInsertSize << " - " << stlEraseSize << ", found amount: " << stlFoundAmount << endl << endl;

    delete[] keysToInsert;
    delete[] keysToErase;
    delete[] keysToFind;

    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount == stlFoundAmount)
    {
        cout << "The lab is completed\n\n\n\n";
        return true;
    }

    cerr << ":(\n" << endl;
    
    return false;
    return 0;
}