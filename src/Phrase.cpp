#include "Phrase.h"

Phrase::Phrase()
{

}

Phrase::Phrase(std::vector<std::string> v)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		words.push_back(v[i]); // copy the vector into the current words
	}
	terminal = false; // set this to false, we will set it to true in subclasses if they are terminals
}

Phrase::Phrase(std::string w)
{
	words.push_back(w);
	terminal = false;
	// here we assign the phrase type to the phrase
	phraseType = checkFiles(w);
}

std::vector<std::string> Phrase::getWords()
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

PhraseType Phrase::checkFiles(std::string word)
{
	std::string returner;
	int numTypes = 7;
	std::string typeLabels[numTypes] = {"adjective", "adverb", "article", "conjunction", "noun", "subject", "verb"};
	std::string typeFiles[numTypes] = {"../res/adjectives.txt", "../res/adverbs.txt", "../res/articles.txt", "../res/conjunctions.txt", "../res/nouns.txt", "subject.txt", "verbs.txt"};

	for (int i = 0; i < numTypes; i++)
	{
		std::ifstream in(typeFiles[i].c_str());
		std::string databaseWord;
		while (in >> databaseWord)
		{   
			if (strcmp(word.c_str(), databaseWord.c_str()) == 0)
			{
				in.close();
				returner = typeLabels[i];
			}
		}
		in.close();
	}

	if (strcmp(returner.c_str(), "adjective"))
	{
		return adjective;
	}
	
	if (strcmp(returner.c_str(), "noun"))
	{
		return noun;
	}
	
	if (strcmp(returner.c_str(), "verb"))
	{
		return verb;
	}
	//TODO: make this not shit
	return none;
}