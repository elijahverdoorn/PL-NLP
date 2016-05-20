#include "../include/VerbPhrase.h"

VerbPhrase::VerbPhrase()
{
	terminal = false;
}

VerbPhrase::VerbPhrase(std::vector<std::string> v) : Phrase(v)
{
	terminal = false;
	setPhraseType();
}

void VerbPhrase::setPhraseType()
{
	phraseType = verbPhrase;
}