#ifndef _WORD_
#define _WORD_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <fstream>

class Word {
	std::string word;
	std::string wordType;

public:
	//constructors
	Word();
	Word(std::string w);

	//methods
	void printWord();
	std::string getSource();
	void printWordType();
	std::string getWordType();
	std::string getType();

private:
	std::string setType();
};

#endif
