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
#include "Sentence.h"

using namespace std;

PhraseType isPhrase(Phrase phrase) // checks if the phrase is a known type and returns that type.
{
	//return phrase.getPhraseType();
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
			break; /*
		case prep:
			{return prep;}
			break;
		case det:
			{return det;}
			break; */
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
	if (first.getPhraseType() == det && second.getPhraseType() == nounPhrase)
	{
		return nounPhrase;
	}
	if (first.getPhraseType() == prep && second.getPhraseType() == nounPhrase) 
	{
		return adverbialPhrase;
	}
	if (first.getPhraseType() == nounPhrase && second.getPhraseType() == prep)
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
			break;
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


	//cout << "copying complete" << endl;

	Phrase* returner;

	switch (type)
	{
		case sentence:
			returner = new Sentence(v);
			break;
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

vector<Phrase> parse(vector<Phrase> v, unsigned int pos = 0) // workhorse parsing function, written recursively
{
	//cout << "current position: " << pos << endl;
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
				printState(v); // let the user know where we are, for debugging
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
					printState(v); // let the user know where we are, for debugging
					parse(newPhrase, 0); // parse the new structure, starting at the beginning
				} else {
					parse(v, pos + 1); // parse the next element of the structure
				}
			}
		//}
		//parse(v, pos + 1);
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
	cout << "userInput: " + userInput << endl;
	return phrases;
}


int main ()
{
	vector<Phrase> testPhrase = getInput();
	parse(testPhrase);
	return 0;

}
