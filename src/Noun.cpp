#include "../include/Noun.h"

Noun::Noun()
{

}

Noun::Noun(std::vector<std::string> v) : Phrase(v)
{
	terminal = true;
}

void Noun::setPhraseType()
{
	phraseType = noun;
}
