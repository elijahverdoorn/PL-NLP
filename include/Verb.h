#ifndef _VERB_
#define _VERB_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Phrase.h"

class Verb: public Phrase
{

public:
	//constructors
	Verb();
	Verb(std::vector<std::string> v);

private:
	void setPhraseType();
};

#endif