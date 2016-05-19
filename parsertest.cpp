#include <iostream>
#include <vector>
#include "Phrase.h"
#include "NounPhrase.h"
#include "Noun.h"
#include "VerbPhrase.h"
#include "Verb.h"
#include "Adjective.h"

using namespace std;

PhraseType isPhrase(Phrase phrase)
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

PhraseType isPhrase(Phrase first, Phrase second)
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

Phrase buildPhrase(PhraseType type, Phrase phrase)
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
	return returner;
}

Phrase* buildPhrase(PhraseType type, Phrase phrase1, Phrase phrase2)
{
	std::vector<Phrase> v;
	v.reserve(phrase1.getWords().size() + phrase2.getWords().size());
	v.insert(v.end(), phrase1.getWords.begin(), phrase1.getWords().end());
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
	return returner;
}

vector<Phrase> parse(vector<Phrase> &v, int pos = 0)
{
	printState(v);
	if(v[pos].getPhraseType() != sentence)
	{
		if(v[pos].isTerminal())
		{
			PhraseType ptype = isPhrase(v[pos]);
			if(ptype != none)
			{
				vector<Phrase> newPhrase;
				for(int i = 0; i < pos; i++)
				{
					newPhrase.push_back(v[i]);
				}
				newPhrase.push_back(buildPhrase(ptype, v[pos]));
				for(int i = pos + 1; i < v.size(); i++)
				{
					newPhrase.push_back(v[i]);
				}
				parse(newPhrase, 0);
			} else {
				ptype = isPhrase(v[pos], v[pos + 1]);
				if(ptype != none)
				{
					vector<Phrase> newPhrase;
					for (int i = 0; i < pos; i++)
					{
						newPhrase.push_back(v[i]);
					}
					newPhrase.push_back(buildPhrase(ptype, v[pos], v[pos + 1]));
					for (int i = pos + 2; i < v.size(); i++)
					{
						newPhrase.push_back(v[i]);
					}
					parse(newPhrase, 0);
				} else {
					parse(v, pos + 1);
				}
			}
		}
	}
	return v;
}

void printState(std::vector<Phrase> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].getPhraseType();
	}
	cout << endl;
}

int main ()
{
	//vector<Phrase> testPhrase = {     }
	//parse(testPhrase);
	return 0;

}
