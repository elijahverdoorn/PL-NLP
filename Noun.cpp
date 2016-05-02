#include "Word.h"
#include "Noun.h"

Noun::Noun()
{

}

Noun::Noun(std::vector<Word> v) : Phrase(v)
{
	terminal = true;
}

void Noun::setPhraseType()
{
	phraseType = noun;
}
