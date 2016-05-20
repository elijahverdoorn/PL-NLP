#ifndef _PREPOSITION_
#define _PREPOSITION_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Phrase.h"

class Preposition: public Phrase
{

public:
	//constructors
	Preposition();
	Preposition(std::vector<std::string> v);
private:
	void setPhraseType();
};

#endif
