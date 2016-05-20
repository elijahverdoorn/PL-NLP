#include <iostream>
#include <vector>
#include <string>
#include "Phrase.h"
#include "NounPhrase.h"
#include "Noun.h"
#include "VerbPhrase.h"
#include "Verb.h"
#include "Adjective.h"
#include "Preposition.h"
#include "Adverb.h"
#include "AdverbialPhrase.h"
#include "Determiner.h"

using namespace std;

string endingPrint;

PhraseType isPhrase(Phrase phrase) // checks if the phrase makes up one of the phrases that can be parsed alone, and if so return that type
{
	switch(phrase.getPhraseType())
	{
		case noun:
			{return noun;}
			break;
		case verb:
			{return verb;}
			break;
		case adverb:
			{return adverb;}
			break;
		default:
			break;
	}
	return none;
}

PhraseType isPhrase(Phrase first, Phrase second) // as above, but for more than 1 argument
{
	if (first.getPhraseType() == nounPhrase && second.getPhraseType() == verbPhrase)
	{
		return sentence;
	}
	if (first.getPhraseType() == adjective && second.getPhraseType() == nounPhrase)
	{
		return nounPhrase;
	}
	if (first.getPhraseType() == verb && second.getPhraseType() == nounPhrase)
	{
		return verbPhrase;
	}	
	if (first.getPhraseType() == determiner && second.getPhraseType() == nounPhrase)
	{
		return nounPhrase;
	}
	if (first.getPhraseType() == preposition && second.getPhraseType() == nounPhrase) 
	{
		return adverbialPhrase;
	}
	if (first.getPhraseType() == nounPhrase && second.getPhraseType() == preposition)
	{
		return adverbialPhrase;
	}
	if (first.getPhraseType() == verbPhrase && second.getPhraseType() == adverbialPhrase) 
	{
		return verbPhrase;
	}
	if (first.getPhraseType() == adverbialPhrase && second.getPhraseType() == verbPhrase)
	{
		return verbPhrase;
	}

	return none;
}

Phrase buildPhrase(PhraseType type, Phrase phrase) // creates the phrase for a single element phrase. input the type of phrase desired, and the prhase itself.
{
	Phrase* returner;
	switch (type)
	{
		case noun:
			returner = new NounPhrase(phrase.getWords());
			break;
		case verb:
			returner = new VerbPhrase(phrase.getWords());
			break;
		case adverb:
			returner = new AdverbialPhrase(phrase.getWords());
		default:
			break;
	}
	return *returner;
}

Phrase buildPhrase(PhraseType type, Phrase phrase1, Phrase phrase2) // as above, but the output contains the two phrases that are input
{
	//cout << "building phrase" << endl;

	std::vector<string> v;
	for (unsigned int i = 0; i < phrase1.getWords().size(); ++i)
	{
		v.push_back(phrase1.getWords()[i]);
	}

	for (unsigned int i = 0; i < phrase2.getWords().size(); ++i)
	{
		v.push_back(phrase2.getWords()[i]);
	}

	Phrase* returner;

	switch (type)
	{
		case nounPhrase:
			returner = new NounPhrase(v);
			break;
		case verbPhrase:
			returner = new VerbPhrase(v);
			break;
		case adverbialPhrase:
			returner = new AdverbialPhrase(v);
			break;
		default:
			break;
	}
	return *returner;
}

void printState(std::vector<Phrase> v) // Print the current state of the paramter to the terminal
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		//cout << v[i].getPhraseType();
		switch (v[i].getPhraseType())
		{
			case 0:
				cout << "nounPhrase ";
				break;
			case 1:
				cout << "verbPhrase ";
				break;
			case 2:
				cout << "verb ";
				break;
			case 3:
				cout << "noun ";
				break;
			case 4:
				cout << "adjective ";
				break;
			case 5:
				cout << "determiner ";
				break;
			case 6:
				cout << "adverb ";
				break;
			case 7:
				cout << "adverbialPhrase ";
				break;
			case 8:
				cout << "preposition ";
				break;
			case 9:
				cout << "sentence ";
				break;
			case 10:
				cout << "none ";
				break;
			default:
				cout << "ERROR ";
				break;
		}
	}
	cout << endl;
}


string getState(std::vector<Phrase> v) // Print the current state of the paramter to the terminal
{
	string returner;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		//cout << v[i].getPhraseType();
		switch (v[i].getPhraseType())
		{
			case 0:
				returner.append("nounPhrase");
				break;
			case 1:
				returner.append("verbPhrase");
				break;
			case 2:
				returner.append("verb");
				break;
			case 3:
				returner.append("noun");
				break;
			case 4:
				returner.append("adjective");
				break;
			case 5:
				returner.append("determiner");
				break;
			case 6:
				returner.append("adverb");
				break;
			case 7:
				returner.append("adverbialPhrase");
				break;
			case 8:
				returner.append("preposition");
				break;
			case 9:
				returner.append("sentence");
				break;
			case 10:
				returner.append("none");
				break;
			default:
				returner.append("ERROR");
				break;
		}
	}
	return returner;
}

vector<Phrase> parse(vector<Phrase> v, unsigned int pos = 0) // workhorse parsing function, written recursively
{
	if (pos < v.size())
	{
		//printState(v); // let the user know where we are, for debugging
		if(v[pos].getPhraseType() != sentence)
		{
			//if(!v[pos].isTerminal()) // is this a final state?
			//{
				PhraseType ptype = isPhrase(v[pos]);
				if(ptype != none) // so long as the phrase is not none
				{
					vector<Phrase> newPhrase;
					for(unsigned int i = 0; i < pos; i++)
					{
						newPhrase.push_back(v[i]);
					}
					newPhrase.push_back(buildPhrase(ptype, v[pos])); // build a phrase, then add it in it's place to the larger structure
					for(unsigned int i = pos + 1; i < v.size(); i++)
					{
						newPhrase.push_back(v[i]);
					}
					printState(newPhrase);
					parse(newPhrase, 0); // parse the result, starting over at the beginning of the structure
				} else {
					ptype = isPhrase(v[pos], v[pos + 1]);
					if(ptype != none)
					{
						vector<Phrase> newPhrase;
						for (unsigned int i = 0; i < pos; i++)
						{
							newPhrase.push_back(v[i]);
							//cout << "current i (1st loop):" << i << endl;
						}
						newPhrase.push_back(buildPhrase(ptype, v[pos], v[pos + 1])); // build a phrase, and add it in it's place to the larger structure
						for (unsigned int i = pos + 2; i < v.size(); i++)
						{
							newPhrase.push_back(v[i]);
							//cout << "current i (2nd loop):" << i << endl;
						}
						if (newPhrase.size() != 1)
						{
							printState(newPhrase);
							parse(newPhrase, 0); // parse the new structure, starting at the beginning
						} else {
							endingPrint = getState(newPhrase);
							return newPhrase;
						}
					} else {
						parse(v, pos + 1); // parse the next element of the structure
					}
				}
			//}
			//parse(v, pos + 1);
		}
	}
	return v;
}

// interacion function that gets input from the user and returns it as a vector of phrases.
// Also acts as a tokenizer
std::vector<Phrase> getInput()
{
	cout << "Enter a Phrase:" << endl; // prompt

	string userInput;
	getline(cin, userInput);
	char* unTokenized  = new char [userInput.length() + 1];
	strcpy(unTokenized, userInput.c_str());
	char* tokens = strtok(unTokenized, " ");
	
	vector<string> tokenized; // start with strings
	while(tokens != NULL)
	{
		tokenized.push_back(string(tokens));
		tokens = strtok(NULL, " ");
	}

	vector<Phrase> phrases; // and finally make the words into phrases
	for (unsigned int i = 0; i < tokenized.size(); ++i)
	{
		Phrase p(tokenized[i]);
		//cout << p.getPhraseType() << endl;
		phrases.push_back(p);
	}
	return phrases;
}


int main ()
{
	vector<Phrase> testPhrase = getInput();
	std::vector<Phrase> v = parse(testPhrase);
	cout << "Finished parsing \" ";
	for (unsigned int i = 0; i < v.size(); i++)
	{
		for(unsigned int j = 0; j < v[i].getWords().size(); j++)
		{
			cout << v[i].getWords()[j] << " ";
		}
	}
	cout << "\"" << " Which becomes \"" << endingPrint << "\" when parsed." << endl;
	return 0;

}
