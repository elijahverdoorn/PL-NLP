#ifndef _ADVERBIALPHRASE_
#define _ADVERBIALPHRASE_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Phrase.h"
#include "Adjective.h"
#include "Noun.h"
#include "Determiner.h"
#include "Preposition.h"
#include "Adverb.h"
#include "NounPhrase.h"

class AdverbialPhrase: public Phrase
{
	//case 1
	Preposition *preposition;
	NounPhrase *myNounPhrase;

	//case 3
	Adverb *adverb;

public:
	//constructors
	AdverbialPhrase();
	AdverbialPhrase(std::vector<std::string> v);
private:
	void setPhraseType();
};

#endif

