#ifndef _NOUN_
#define _NOUN_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Phrase.h"

class Noun: public Phrase
{

public:
	//constructors
	Noun();
	Noun(std::vector<std::string> v);
private:
	void setPhraseType();
};

#endif