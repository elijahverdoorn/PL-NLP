#ifndef _PHRASE_
#define _PHRASE_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <fstream>

enum PhraseType {
	nounPhrase, //0
	verbPhrase, //1
	verb, 		//2
	noun,		//3
	adjective,	//4
	sentence,	//5
	none 		//6, used to represent invalid inputs 
};

class Phrase
{
public:
	std::vector<std::string> words; // the words that make up this phrase
	PhraseType phraseType; // see above
	bool terminal; // is this the end of a branch of the tree?

	//constructors
	Phrase();
	Phrase(std::vector<std::string> v);
	Phrase(std::string w);

	std::vector<std::string> getWords(); // return the words that are in this phrase
	PhraseType getPhraseType(); // return the phrase type 
	bool isTerminal(); // return the value in terminal
private:
	PhraseType checkFiles(std::string word);
};
#endif
