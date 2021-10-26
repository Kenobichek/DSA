#include <iostream>
#include "MyHeading.h"
#include "Generating.h"
#include "test.h"
using namespace std;
int main() {

	//’еш-таблиц€ за методом ланцюжк≥в (€к ключ використовуЇмо тип даних long long)
	testHashTable();

	//’еш-таблиц€ за методом ланцюжк≥в (€к ключ використовуЇмо тип даних string)
	test2HashTable();

	//’еш-таблиц€ за в≥дкритоњ адресац≥њ
	test3HashTable();

	return 0;
}