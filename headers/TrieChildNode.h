#ifndef TRIEChILDNODE_H
#define TRIECHILDNODE_H

struct TrieNode;

struct TListNode	{
	short int index;
	TrieNode * link;
	TListNode * next;
};

class TrieChildNode 	{
	//This is a special link list for using on hte link part of a TrieNode
	TListNode * rootNode;
	TListNode * initNode(void);
public:
	TrieChildNode();	//This is a constructor
	~TrieChildNode();	//This is the destructor
	bool insertNode(short int tIndex, TrieNode * linkFeild);	//This is used to insert nodes in the list
	bool deleteNode(short int tIndex);	//This is used to remove the Node
	bool isEmpty(void);	//This tells whether the list is empty or not
	TrieNode * operator[](short int tIndex);	//This is used for array like access :D
};

#endif