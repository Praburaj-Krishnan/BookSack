#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

#define MAXELTS 50

struct Node	{
	std::string data;
	Node * link;
};

//QT optmization done.

class LinkList {
	  Node * p;
	  int eltCount;
public:
	  LinkList();
	  ~LinkList();
	  bool append (std::string tWord); 
	  std::string returnData();
	  void clearAll();
	  bool isEmpty();
};

#endif