#include "../include/Word.h"
#include "../include/NounPhrase.h"

NounPhrase::NounPhrase()
{

}

NounPhrase::NounPhrase(std::vector<Word> v) : Phrase(v)
{
	terminal = false;
}

void NounPhrase::setPhraseType()
{
	phraseType = nounPhrase;
}