#ifndef _NOUN_
#define _NOUN_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Word.h"
#include "Phrase.h"

class Noun: public Phrase
{

public:
	//constructors
	Noun();
	Noun(std::vector<Word> v);
private:
	void setPhraseType();
};

#endif