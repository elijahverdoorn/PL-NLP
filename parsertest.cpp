#include <iostream>
#include <vector>
#include <string>
#include "Phrase.h"
#include "NounPhrase.h"
#include "Noun.h"
#include "VerbPhrase.h"
#include "Verb.h"
#include "Adjective.h"

using namespace std;

PhraseType isPhrase(Phrase phrase) // checks if the phrase is a known type and returns that type.
{
	switch(phrase.getPhraseType())
	{
		case noun:
			{return noun;}
			break;
		case verb:
			{return verb;}
			break;
		default:
			break;
	}
	return none;
}

PhraseType isPhrase(Phrase first, Phrase second) // as above, but for more than 1 argument
{
	if (first.getPhraseType() == adjective && second.getPhraseType() == nounPhrase)
	{
		return nounPhrase;
	}
	if (first.getPhraseType() == verb && second.getPhraseType() == nounPhrase)
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
			returner = new Noun(phrase.getWords());
			break;
		case verb:
			returner = new Verb(phrase.getWords());
			break;
		default:
			break;
	}
	return *returner;
}

Phrase buildPhrase(PhraseType type, Phrase phrase1, Phrase phrase2) // as above, but the output contains the two phrases that are input
{
	std::vector<string> v;
	v.reserve(phrase1.getWords().size() + phrase2.getWords().size());
	v.insert(v.end(), phrase1.getWords().begin(), phrase1.getWords().end());
	v.insert(v.end(), phrase2.getWords().begin(), phrase2.getWords().end()); // v contains the words in the 2 phrases, in the right order

	Phrase* returner;

	switch (type)
	{
		case nounPhrase:
			returner = new NounPhrase(v);
			break;
		case verbPhrase:
			returner = new VerbPhrase(v);
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
				cout << "sentence ";
				break;
			case 6:
				cout << "none ";
				break;
			default:
				cout << "ERROR: bad phrase type";
				break;
		}
	}
	cout << endl;
}

vector<Phrase> parse(vector<Phrase> v, unsigned int pos = 0) // workhorse parsing function, written recursively
{

	//TODO: There's a segfault in here somewhere. find and fix it.

	printState(v); // let the user know where we are, for debugging
	if(v[pos].getPhraseType() != sentence)
	{
		if(!v[pos].isTerminal()) // is this a final state?
		{
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
				parse(newPhrase, 0); // parse the result, starting over at the beginning of the structure
			} else {
				ptype = isPhrase(v[pos], v[pos + 1]);
				if(ptype != none)
				{
					vector<Phrase> newPhrase;
					for (unsigned int i = 0; i < pos; i++)
					{
						newPhrase.push_back(v[i]);
					}
					newPhrase.push_back(buildPhrase(ptype, v[pos], v[pos + 1])); // build a phrase, and add it in it's place to the larger structure
					for (unsigned int i = pos + 2; i < v.size(); i++)
					{
						newPhrase.push_back(v[i]);
					}
					parse(newPhrase, 0); // parse the new structure, starting at the beginning
				} else {
					parse(v, pos + 1); // parse the next element of the structure
				}
			}
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
		cout << p.getPhraseType() << endl;
		phrases.push_back(p);
	}
	return phrases;
}


int main ()
{
	vector<Phrase> testPhrase = getInput();
	parse(testPhrase);
	return 0;

}