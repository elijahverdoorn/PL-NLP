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
	
	// parse the word, then add it to the vector of parsed words for this sentence.
	for(int i = 0; i <= tokenized.size(); i++)
	{
		parsedWords.push_back(new Word(tokenized[i]));
	}
}

void Sentence::printTokens()
{
	for(int i = 0; i < tokenized.size(); i++)
	{
		std::cout << tokenized[i] << std::endl;
	}
}

std::vector<Word> Sentence::getWords()
{
	return parsedWords;
}

Word Sentence getWordAt(int index)
{
	return parsedWords[i];
}

void Sentence::setWords(Word* words)
{
	parsedWords = new vector<Word>(words);
}

void Sentence::printParsedSentence()
{
	for(int i = 0; i <= parsedWords.size(); i++)
	{
		std::cout << parsedWords[i].returnWordType();
	}
	std::cout << std::endl;
}
