#include "../include/NounPhrase.h"

NounPhrase::NounPhrase()
{

}

NounPhrase::NounPhrase(std::vector<std::string> v) : Phrase(v)
{
	terminal = false;
}

void NounPhrase::setPhraseType()
{
	phraseType = nounPhrase;
}