#ifndef TRIEHANDLER_H
#define TRIEHANDLER_H

#include "../headers/LinkedList.h"
#include "../headers/TrieChildNode.h"
#include <iostream>

using namespace std;

struct TrieNode	{
	char singleChar;
	bool isWordEnd;
	string fullName;
	TrieChildNode childNodesList;
};

struct SearchStringHolder	{
	string searchString;
	unsigned int counter;
};

class TrieHandler {
	/*
	 * @Desc : This class is used to simulate the Trie Data structure
	 */
	//The Attributes
protected:
	TrieNode rootNode;	//This is the root Node.
	int childNodeCount;	//This contains the count of the degree of the tree
	int tCount, dCount;
	const char BEGIN;
	//Some private methods
	TrieNode * initNode(char nodeData, bool tIsWordEnd, string fileName);	//This creates a new node and initialises everything.
	bool delChildNodes(TrieNode * child);	//Recursive Deleter
	//void addWordToList(LinkList & suggestList, TrieNode * currentLevel);
	bool checkForWords(TrieNode * currentLevel , SearchStringHolder remainingSearchStr ,LinkList &suggestList,string accum);
	bool insertIntoTrie(string word, string fileName);
public:
	TrieHandler(int tChildNodeCount, char beginChar = 'a');
	~TrieHandler();
	bool insertWord(string word);
	bool getRecommendation(string searchString, LinkList &suggestList);
	bool deleteEntireTrie();	//Deletes everything
	void getTCount(int & , int &);	//TEST FUNCTION
};

#endif
