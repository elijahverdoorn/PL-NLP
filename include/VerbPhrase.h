#ifndef _VERBPHRASE_
#define _VERBPHRASE_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Phrase.h"
#include "Verb.h"
#include "NounPhrase.h"

class VerbPhrase: public Phrase
{
	//these define the grammar. If the Phrase doesn't meet one of these recipes, it is not a NP... But it might be another type of phrase!
	//TODO: we need some kind of implementation of a function that chops the sentence up into phrases, then populates these fields with their words.
	//case 1
	VerbPhrase *myVerbPhrase;
	//case 2
	Verb *myVerb;
	NounPhrase *myNounPhrase;

public:
	//constructors
	VerbPhrase();
	VerbPhrase(std::vector<std::string> v);
private:
	void setPhraseType();
};

#endif