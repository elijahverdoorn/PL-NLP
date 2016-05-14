#ifndef _PHRASE_
#define _PHRASE_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Word.h"

enum PhraseType {
	nounPhrase,
	verbPhrase,
	verb,
	noun,
	adjective
};

class Phrase
{
public:
	std::vector<Word> words; // the words that make up this phrase
	PhraseType phraseType; // see above
	bool terminal; // is this the end of a branch of the tree?

	//constructors
	Phrase();
	Phrase(std::vector<Word> v);

	std::vector<Word> getWords(); // return the words that are in this phrase
	PhraseType getPhraseType(); // return the phrase type 
	bool isTerminal(); // return the value in terminal
private:

};
#endif