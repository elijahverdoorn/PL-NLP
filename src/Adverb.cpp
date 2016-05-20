#include "../include/Adverb.h"

Adverb::Adverb()
{

}

Adverb::Adverb(std::vector<std::string> v) : Phrase(v)
{
	terminal = true;
}

void Adverb::setPhraseType()
{
	phraseType = noun;
}
