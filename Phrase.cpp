#include "Phrase.h"
#include "Word.h"

Phrase::Phrase()
{

}

Phrase::Phrase(std::vector<Word> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		words.push_back(v[i]); // copy the vector into the current words
	}
	terminal = false; // set this to false, we will set it to true in subclasses if they are terminals
}

std::vector<Word> Phrase::getWords()
{
	return words;
}

PhraseType Phrase::getPhraseType()
{
	return phraseType;
}

bool Phrase::isTerminal()
{
	return terminal;
}	