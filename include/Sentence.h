#ifndef _SENTENCE_
#define _SENTENCE_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Word.h"
#include "Phrase.h"
#include "NounPhrase.h"
#include "VerbPhrase.h"

class Sentence : public Phrase
{
	VerbPhrase *myVerbPhrase;
	NounPhrase *myNounPhrase;

public:
	Sentence();
	Sentence(std::vector<Word> v;);
private:
	void setPhraseType();

};

#endif
