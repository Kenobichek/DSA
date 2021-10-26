#include <fstream>
#include <vector>
#include <algorithm>
#include "testBST.h"
#include "PrefixTree.h"

using namespace std;

bool testPrefixtree() {
	vector <string> v;

	ifstream f("words.txt");
	Trie myTree;
	while (!f.eof()) {
		string a;
		f >> a;
		myTree.insert(a);
	}
	cout << "input: \n\n";
	string input;
	cin >> input;
	
	v = myTree.findByPrefix(input);

	//sort(v.begin(), v.end());

	cout << endl << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;

	return true;
}