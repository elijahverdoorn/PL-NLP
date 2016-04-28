#include "Sentence.h"
#include "Word.h"

Sentence::Sentence()
{
	//nothing to do here
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
	char * unTokenized = new char [source.length() + 1];
	std::strcpy(unTokenized, source.c_str());
	char * tokens = std::strtok(unTokenized, " ");

	while(tokens != NULL)
	{
		tokenized.push_back(std::string(tokens));
		tokens = strtok(NULL, " ");
	}
	
	// parse the word, then add it to the vector of parsed words for this sentence.
	for(int i = 0; i < tokenized.size(); i++)
	{
		Word w(tokenized[i]);
		parsedWords.push_back(w);
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

Word Sentence::getWordAt(int index)
{
	return parsedWords[index];
}

// void Sentence::setWords(Word* words)
// {
// 	parsedWords = new vector<Word>();
// 	for(int i = 0; words[i] != NULL; i++)
// 	{
// 		parsedWords.push_back(words[i]);
// 	}
// }

void Sentence::printParsedSentence()
{
	for(int i = 0; i < parsedWords.size(); i++)
	{
		std::cout << parsedWords[i].getType() << " ";
	}
	std::cout << std::endl;
}
