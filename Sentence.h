#ifndef _SENTENCE_
#define _SENTENCE_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Word.h"

class Sentence
{
	std::string source;
	std::vector<std::string> tokenized;
	std::vector<Word> parsedWords;

public:
	//constructos
	Sentence();
	Sentence(std::string s);
	
	//methods
	void setSource(std::string s);
	std::string getSource();
	std::vector<std::string> getTokenized();
	void printTokens();
	std::vector<Word> getWords();
	Word getWordAt(int index);	
	void setWords(Word* words);	
	void printParsedSentence();

private:
	void updateVector();

};

#endif
