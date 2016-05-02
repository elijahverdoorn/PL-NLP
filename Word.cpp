#include "Word.h"

Word::Word() 
{
	word = "example";
}

Word::Word(std::string w) 
{
	word = w;
  	wordType = setType();
}

std::string Word::getSource()
{
	return word;
}

void Word::printWord() 
{
	std::cout << "Word: " << word << std::endl;
}

void Word::printWordType() 
{
	std::cout << "Word: " << word << " Type: " << wordType << std::endl;
}

std::string Word::getType() 
{
	return wordType;
}

std::string Word::setType()
{
	int numTypes = 7;
	std::string typeLabels[numTypes] = {"adjective", "adverb", "article", "conjunction", "noun", "subject", "verb"};
	std::string typeFiles[numTypes] = {"adjectives.txt", "adverbs.txt", "articles.txt", "conjunctions.txt", "nouns.txt", "subject.txt", "verbs.txt"};

	for (int i = 0; i < numTypes; i++)
	{
		std::ifstream in(typeFiles[i].c_str());
		std::string databaseWord;
		while (in >> databaseWord)
		{   
			if (strcmp(word.c_str(), databaseWord.c_str()) == 0)
			{
				in.close();
				return typeLabels[i];
			}
		}
		in.close();
	}
	return "invalid";
}