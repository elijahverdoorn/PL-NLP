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
		case PhraseType.noun:
			return PhraseType.noun;
			break;
		case PhraseType.verb:
			return PhraseType.verb;
			break;
	}
	return PhraseType.none;
}

PhraseType isPhrase(Phrase first, Phrase second)
{
	if (first.getPhraseType() == PhraseType.adjective && second.getPhraseType() == PhraseType.nounPhrase)
	{
		return PhraseType.nounPhrase;
	}
	if (first.getPhraseType() == PhraseType.verb && second.getPhraseType() == PhraseType.nounPhrase)
	{
		return PhraseType.verbPhrase;
	}
	return PhraseType.none;
}

Phrase buildPhrase(PhraseType type, Phrase phrase)
{
	switch (type)
	{
		case PhraseType.noun:
			Noun(phrase.getWords()) returner;
			break;
		case PhraseType.verb:
			Verb(phrase.getWords()) returner;
			break;
		default:
			break;
	}
	return returner;
}

Phrase buildPhrase(PhraseType type, Phrase phrase1, Phrase phrase2)
{
	std::vector<Phrase> v;
	v.reserve(phrase1.getWords().size() + phrase2.getWords().size());
	v.insert(v.end(), phrase1.begin(), phrase1.end());
	v.insert(v.end(), phrase1.begin(), phrase1.end()); // v contains the words in the 2 phrases, in the right order

	switch (type)
	{
		case PhraseType.nounPhrase:
			NounPhrase(v) returner;
			break;
		case PhraseType.verbPhrase:
			VerbPhrase(v) returner;
			break;
		default:
			break;
	}
	return returner;
}

vector<Phrase> parse(vector<Phrase>& v, int pos = 0)
{
	printState(v);
	if(v[pos].getPhraseType() != PhraseType.sentence)
	{
		if(v[pos].isTerminal())
		{
			PhraseType ptype = isPhrase(v[pos]);
			if(ptype != PhraseType.none)
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
			} else if(ptype = isPhrase(v[pos], v[pos + 1]) != PhraseType.none) {
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
				}
		} else {
			parse(v, pos + 1);
		}
	} else {
		return v;
	}
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
	parse(testPhrase);

}
