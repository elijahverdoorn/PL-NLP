#include "../include/NounPhrase.h"

NounPhrase::NounPhrase()
{
	terminal = false;
}

NounPhrase::NounPhrase(std::vector<std::string> v) : Phrase(v)
{
	terminal = false;
	setPhraseType();
}

void NounPhrase::setPhraseType()
{
	phraseType = nounPhrase;
}