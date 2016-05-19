#include "../include/Word.h"
#include "../include/VerbPhrase.h"

VerbPhrase::VerbPhrase()
{

}

VerbPhrase::VerbPhrase(std::vector<Word> v) : Phrase(v)
{
	terminal = false;
}

void VerbPhrase::setPhraseType()
{
	phraseType = verbPhrase;
}