#ifndef _NOUNPHRASE_
#define _NOUNPHRASE_

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

class NounPhrase: public Phrase
{
	//these define the grammar. If the Phrase doesn't meet one of these recipes, it is not a NP... But it might be another type of phrase!
	//TODO: we need some kind of implementation of a function that chops the sentence up into phrases, then populates these fields with their words.
	//case 1
	Adjective *adjective;
	NounPhrase *myNounPhrase;
	//case 2
	Noun *noun;

public:
	//constructors
	NounPhrase();
	NounPhrase(std::vector<std::string> v);
private:
	void setPhraseType();
};

#endif
