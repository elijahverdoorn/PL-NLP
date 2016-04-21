#include "Sentence.h"

Sentence::Sentence()
{

}
Sentence::Sentence(std::string s)
{
	source = s;
	updateVector();
}

void Sentence::setSource(std::string s)
{
	source = s;
	updateVector();
}

std::string Sentence::getSource()
{
	return source;
}

std::vector<std::string> Sentence::getTokenized()
{
	return tokenized;
}

void Sentence::updateVector()
{
	// tokenized = new std::Vector<std::string>();
	char * unTokenized = new char [source.length() + 1];
	std::strcpy(unTokenized, source.c_str());
	char * tokens = std::strtok(unTokenized, " ");

	while(tokens != NULL)
	{
		tokenized.push_back(std::string(tokens));
		tokens = strtok(NULL, " ");
	}

}