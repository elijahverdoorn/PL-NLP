#ifndef _SENTENCE_
#define _SENTENCE_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>

class Sentence
{
	std::string source;
	std::vector<std::string> tokenized;

public:
	//constructors
	Sentence();
	Sentence(std::string s);
	
	//methods
	void setSource(std::string s);
	std::string getSource();
	std::vector<std::string> getTokenized();
	void printTokens();

private:
	void updateVector();

};

#endif