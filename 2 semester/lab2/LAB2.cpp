#include <iostream>
#include "MyHeading.h"
#include "Generating.h"
#include "test.h"
using namespace std;
int main() {

	//���-������� �� ������� �������� (�� ���� ������������� ��� ����� long long)
	testHashTable();

	//���-������� �� ������� �������� (�� ���� ������������� ��� ����� string)
	test2HashTable();

	//���-������� �� ������� ���������
	test3HashTable();

	return 0;
}