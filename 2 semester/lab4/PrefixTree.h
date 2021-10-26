#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

struct TrieNode {
	unordered_map<char, TrieNode*> myMap;
	bool lastWord = false;
};

struct Trie {
	TrieNode* root = new TrieNode;

	void insert(const string& word);

	void print(TrieNode* node, string str, vector <string>* v);

	vector<string> findByPrefix(const string& s);
};