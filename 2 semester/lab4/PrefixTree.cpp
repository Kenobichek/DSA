#include "PrefixTree.h"
using namespace std;

void Trie::insert(const string& s) {
	TrieNode* node = root;
	
	if (node == NULL) {
		return;
	}

	for (auto x : s) {
		if (node->myMap.count(x) == 0) {
			node->myMap[x] = new TrieNode;
		}
		node = node->myMap[x];
	}
	node->lastWord = true;
}

vector<string> Trie::findByPrefix(const string& s) {
	TrieNode* node = root;

	vector <string> prefixWords;
	for (auto x : s) {
		if (node != NULL) {
			node = node->myMap[x];
		}
		else {
			return prefixWords;
		}
	}
	
	string str = s;
	if (node != NULL) {
		print(node, s, &prefixWords);
	}

	return  prefixWords;
}

void Trie::print(TrieNode* node, string str, vector <string>* v) {
	unordered_map<char, TrieNode*> ::iterator it;
	for (it = node->myMap.begin(); it != node->myMap.end(); it++) {
		v->push_back(str + it->first);
		print(it->second, str + it->first,v);

	}
}
