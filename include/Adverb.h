#ifndef _ADVERB_
#define _ADVERB_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Phrase.h"

class Adverb: public Phrase
{

public:
	// constructors
	Adverb();
	Adverb(std::vector<std::string> v);
private:
	void setPhraseType();
};

#endif
