#include "../headers/LinkedList.h"

using namespace std;

LinkList::LinkList()  {
	p = NULL;
	eltCount = 0;
}

LinkList::~LinkList() {
	if (p == NULL)
		return;

	Node* tmp;
	while(p != NULL)  {
		tmp = p->link ;
		delete p;
		p = tmp;
	}
}

bool LinkList::isEmpty()	{
	return (p == NULL);
}

void LinkList::clearAll()	{
	while(p != NULL)	{
		Node * temp = p;
		p = p->link;
		delete temp;
	}
	eltCount = 0;
}

// Adds a new node at the end of the linkedlist
bool LinkList::append(string tWord)  {
	Node * newNode = new Node;
	newNode->data = tWord;
	newNode->link = NULL;
	//This is causing qt to somehow crash. Limiting count and testing
	if(eltCount >= MAXELTS)	{
		return false;
	}
	if(p == NULL)  {
		p = newNode;  //Create First Node  
	} else {
		Node *tmp = p;//Traverse
		while(tmp->link != NULL) {
			tmp = tmp->link;
		}
		//add node to the end  
		tmp->link = newNode;
		eltCount++;
	}
	return true;
}

string LinkList::returnData()  {
	if(p == NULL)	{
		return string("");
	}
	//Changing this a bit so that Qt can digest the syntax
	Node * nTemp = p;
	string temp = p->data;
  	p = p->link;
  	delete nTemp;
  	return temp;
}

