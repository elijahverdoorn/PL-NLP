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
	std::vector<Word> words;
	PhraseType phraseType;
	bool terminal;

	//constructors
	Phrase();
	Phrase(std::vector<Word> v);

	std::vector<Word> getWords();
	PhraseType getPhraseType();
	bool isTerminal();
private:

};

#endif