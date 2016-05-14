#include <iostream>
#include <vector>
using namespace std;
#include "Phrase.h"
#include "NounPhrase.h"
#include "Noun.h"
#include "VerbPhrase.h"
#include "Verb.h"
#include "Adjective.h"

bool isPhrase(Phrase phrase)
{
	switch(phrase.getPhraseType()) {
		case PhraseType.noun:
		case PhraseType.verb:
			return true;
			break;
	}
	return false;
}



bool isPhrase(Phrase first, Phrase second)
{
	if (first.getPhraseType()==PhraseType.adjective && second.getPhraseType()==PhraseType.nounPhrase ) 
	{
		return true;
	}
	if (first.getPhraseType()==PhraseType.verb && second.getPhraseType()==PhraseType.nounPhrase )
	{
		return true;
	}
	return false;
}


vector<Phrase> buildPhrase(  , pos) {

}



vector<Phrase> parse(vector<Phrase>& v, int pos = 0)
{
	if(v[pos].getPhraseType() != PhraseType.sentence)
	{
		if(v[pos].isTerminal())
		{
			if(isPhrase(v[pos]))
			{
				vector<Phrase> newPhrase;
				for(int i = 0; i < pos; i++)
				{
					newPhrase.push_back(v[i]);
				}
				newPhrase.push_back( buildPhrase(v[pos]));
				for(int i = pos + 1; i < v.size(); i++)
				{
					newPhrase.push_back(v[i]);
				}
				parse(newPhrase, 0);
				} else if(isPhrase(v[pos], v[pos+1])) {
					vector<Phrase> newPhrase;
					for (int i = 0; i < pos; i++)
					{
						newPhrase.push_back(v[i]);
					}
					newPhrase.push_back( buildPhrase(v[pos], v[pos+1]));
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

int main ()
{
  //vector<Phrase> testPhrase = {     }
  parse( testPhrase );


}
