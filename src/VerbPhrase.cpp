#include "../include/VerbPhrase.h"

VerbPhrase::VerbPhrase()
{

}

VerbPhrase::VerbPhrase(std::vector<std::string> v) : Phrase(v)
{
	terminal = false;
}

void VerbPhrase::setPhraseType()
{
	phraseType = verbPhrase;
}