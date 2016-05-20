#include "../include/AdverbialPhrase.h"

AdverbialPhrase::AdverbialPhrase()
{
	terminal = false;
}

AdverbialPhrase::AdverbialPhrase(std::vector<std::string> v) : Phrase(v)
{
	terminal = false;
	setPhraseType();
}

void AdverbialPhrase::setPhraseType()
{
	phraseType = adverbialPhrase;
}
