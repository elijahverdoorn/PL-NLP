#ifndef _WORD_
#define _WORD_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

enum WordType 
{
	DETERMINER, 
	VERB, 
	ADJECTIVE
};

string WordTypeToString[] =
{
    "Determiner",
    "Verb",
    "Adjective"
};

class Word {
	string word;
	WordType type;

public:
	//constructors
	Word();
	Word(string w);

	//methods
	void printWord();
	void printWordType();
	string returnWordType();
	string getType();
};

#endif