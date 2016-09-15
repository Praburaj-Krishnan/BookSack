#include "../headers/TrieChildNode.h"
#include <QtCore>
#include <iostream>

TrieChildNode::TrieChildNode()	{
	//This is the constructor and is just used to set null to rootnode
	rootNode = NULL;
}

TrieChildNode::~TrieChildNode()	{
	//This deallocates all the memory of the List
	TListNode * temp = NULL;
	while(rootNode != NULL)	{	//This deletes the dynamic memory
		temp = rootNode;
		rootNode = rootNode->next;
		delete temp;
	}
}

//This is used to insert a node into the list.
bool TrieChildNode::insertNode(short int tIndex, TrieNode * linkFeild)	{
	//We try to insert it in order so that searching wont be a pain.
	TListNode * xNode = initNode();
	if(xNode == NULL)	{
		return false;
	}
	xNode->index = tIndex;
	xNode->link = linkFeild;
	//Now we move through the list and insert it in the required location
	TListNode * temp = NULL, * ptr = rootNode;
	//Inserting for first time needs this test
	if(ptr == NULL)	{
		rootNode = xNode;
		return true;
	}
	while(ptr != NULL)	{
		if(ptr->index > tIndex)	{
			//Seems we have found the place to insert the node
			//We check if this is the first node we are dealing with
			if(temp == NULL)	{	//This is the first node
				xNode->next = rootNode;
				rootNode = xNode;
			} else {
				xNode->next = temp->next;
				temp->next = xNode;
			}
			return true;
		} else {
			temp = ptr;
			ptr = ptr->next;
		}
	}
	//Seems we have to add it to the end of the list
	temp->next = xNode;
	return true;
}

//This is used to delete a index from the LinkList
bool TrieChildNode::deleteNode(short int tIndex)	{
	//We Search efficiently until index is greater than tIndex to conclude that the link is in or not
	TListNode * ptr = rootNode, * temp = NULL;
	if(ptr == NULL)	{
		return false;
	}
	do
	{
		//We start.
		if(ptr->index == tIndex)	{
			//This is the first element. Have to change the rootNode
			if(temp == NULL)	{
				temp = rootNode;
				rootNode = rootNode->next;
				delete temp;
			} else {
				//This is a regular condition
				temp->next = ptr->next;
				delete ptr;
			}
			return true;
		} else if (ptr->index > tIndex)	{
			return false;
		} else {
			temp = ptr;
			ptr = ptr->next;
		}
	} while (ptr->next != NULL);
	//There is a possibility that the last element may be the link
	if(ptr->index == tIndex)	{
		//This is the last element scenario
		temp->next = NULL;
		delete ptr;
		return true;
	}
	return false;
}

//This just returns if it is empty or not based on rootNode == NULL
bool TrieChildNode::isEmpty(void)	{
	return (rootNode == NULL);
}

//This uses new to create a node and inits it then returns it
TListNode * TrieChildNode::initNode(void)	{
	TListNode * temp = new TListNode;
	temp->index = 0;
	temp->link = NULL;
	temp->next = NULL;
	return temp;
}

//This is for easy array like access
TrieNode * TrieChildNode::operator[](short int tIndex)	{
	//This returns the TrieNOde * if found else NULL. So have to check properly
	//This is a redundant test
	if(tIndex < 0 || tIndex > 50)	{
		return NULL;
	}
	TListNode * ptr = rootNode;
	//Now we loop through
	while(ptr != NULL)	{
		if(ptr->index == tIndex)	{
			return ptr->link;
		} else if(ptr->index > tIndex)	{
			break;
		}
		ptr = ptr->next;
	}
	return NULL;
	
}