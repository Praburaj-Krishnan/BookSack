#include "../headers/TrieHandler.h"

using namespace std;

TrieHandler::TrieHandler(int tChildNodeCount, char beginChar)	: BEGIN(beginChar) {
	//This is a constructor that inits the root node. All insertions are made from the root node.
	childNodeCount = tChildNodeCount;
	tCount = dCount = 0;
	/*-rootNode.childNodesList = new TrieNode * [childNodeCount];
	-for (int i = 0; i < childNodeCount; i++)	{
	-	rootNode.childNodesList[i] = NULL;
	-}*/
}

void TrieHandler::getTCount(int & t, int & d)	{
	t = tCount;
	d = dCount;
}

TrieNode * TrieHandler::initNode(char nodeData, bool tIsWordEnd, string fileName)	{
	//This function is used to initialize a node for usage
	//It creates one , gives the isWordEnd and singleChar values and generates a 2d pointer all pointing to NULL
	TrieNode * temp = new TrieNode;
	temp->singleChar = nodeData;
	temp->isWordEnd = tIsWordEnd;
	temp->fullName = fileName;
	tCount++;
	return temp;
}

TrieHandler::~TrieHandler()	{
	//We Will Fill this up later.
	deleteEntireTrie();
}

/*
 * @Title 	: Search Algorithm
 * @Desc 	: For searching in the filled trie structure we need the search string. The Linklist is to add the existing words to a suggestion list.
 *		  	  We DO NOT add a word if it is less than the length of the search String. If should be added only if the length is equal or greater.
 */
bool TrieHandler::getRecommendation(string searchString, LinkList &suggestList)	{
	//This function is used to create a suggestion list from the root Node
	SearchStringHolder searchStrHolder;
	//This is just to easily pass things around.
	searchStrHolder.searchString = searchString;
	searchStrHolder.counter = 0;
	//We use an accumulator to keep track of that is in the current subtree
	string accum = "";
	//This is just to check if a single charecter is the minimum
	if(searchString.length() < 1 )	{
		return false;
	}
	//We Check if there is a node with the starting letter in searchString
	if(rootNode.childNodesList[searchString[0] - BEGIN] == NULL)	{
		//We Didn't find anything of that name. The tree has nothing so we end the search here.
		return false;	
	} else {
		//Since we have a node we start the accum and go on searching...
		//accum = searchStrHolder.searchString[0];
		searchStrHolder.counter = 1;
		checkForWords(rootNode.childNodesList[searchString[0] - BEGIN], searchStrHolder, suggestList, accum);
	}
	return true;
}

bool TrieHandler::checkForWords(TrieNode * currentLevel,SearchStringHolder searchStrData ,LinkList &suggestList, string accum)	{
	/*
	 * @desc : this function is what actually adds and searches through the trie structure
	 *		   This recursively calls itself untill everything becomes null. This is not Tail recursive as it comes back the previous and goes forward with the next node
	 */
	//This is for the premature case
	if(searchStrData.counter < searchStrData.searchString.length())	{
		//We Still have not reached the part where the subtree accumulator is greater or equal to the given string.
		//Hence we keep moving on by increementing the required data.
		char temp = searchStrData.searchString[searchStrData.counter];
		accum += currentLevel->singleChar;	//This adds the next char to the accum.
		if(currentLevel->childNodesList[temp - BEGIN] == NULL)	{
			//Seems we dont have what the user is asking for in our DB. return false.
			return false;
		} else {
			//We have a go. so we advance forward.
			searchStrData.counter++;
			//We recursive call this function with the next set of params
			checkForWords(currentLevel->childNodesList[temp - BEGIN], searchStrData, suggestList, accum);
		}
	} else {
		accum += currentLevel->singleChar;
		//Now we have gone far enough. We can start adding words to the suggest list.
		if(currentLevel->isWordEnd)	{	//If this is a word end
			suggestList.append(accum);
		}
		for(int i = 0; i < childNodeCount; i++)	{
			if(currentLevel->childNodesList[i] != NULL)	{
				//Now we go a level deeper
				searchStrData.counter++;
				checkForWords(currentLevel->childNodesList[i], searchStrData, suggestList, accum);
			}
		}
	}
	return true;
}

bool TrieHandler::delChildNodes(TrieNode * child)	{
	//This is used to recursively delete all the child nodes
	//We return if either child or childNodesList 
	if(child == NULL)	{
		return true;
	}
	if(!child->childNodesList.isEmpty())	{
		//Since we have some thing or other we iterate through it and recursively call this function again.
		for(int i = 0; i < childNodeCount; i++)	{
			if(child->childNodesList[i] != NULL)	{
				delChildNodes(child->childNodesList[i]);
			}
		}
	}
	dCount++;
	delete child;
	return true;
}

bool TrieHandler::insertIntoTrie(string word, string fileName)	{
	//This inserts a word into Trie Structure.
	unsigned int i = 0;
	//Now we have to split the string into sections
	TrieNode * currentLevel = &rootNode;
	bool wordExists = true;
	while(i < word.length())	{
		char temp = tolower(word[i]);
		if(currentLevel->childNodesList[temp - BEGIN] == NULL)	{
			wordExists = false;
			currentLevel->childNodesList.insertNode((temp - BEGIN) , initNode(temp, ((i + 1) == word.length() ? true : false) ,
																	 		 ((i + 1) == word.length() ? fileName : "")));
		}
		currentLevel = currentLevel->childNodesList[temp - BEGIN];
		i++;
	}
	if(!wordExists)	{
		unsigned found = currentLevel->fullName.find(fileName);
		if(found == string::npos)	{
			currentLevel->fullName += (";" + fileName);
		}
	}
	return true;
}

bool TrieHandler::insertWord(string word)	{
	//This splits the string with delimiters ' ' , '-', '_'
	string accum = "";
	unsigned int i = 0;
	for(i = 0; i < word.length(); i++)	{
		if(word[i] == ' ' || word[i] == '_' || word[i] == '-')	{
			insertIntoTrie(accum, word);
			accum = "";
		} else {
			accum += word[i];
		}
	}
	if(word[i] != ' ' && word[i] != '_' && word[i] != '-')	{
		insertIntoTrie(accum, word);
	}
	return true;
}
bool TrieHandler::deleteEntireTrie()	{
	//This function deletes all the subnodes and everything.
	//Delete all child nodes first.
	for(int i = 0; i < childNodeCount; i++)	{
		if(rootNode.childNodesList[i] != NULL)	{
			delChildNodes(rootNode.childNodesList[i]);
		}
	}
	return true;
}