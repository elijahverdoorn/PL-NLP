#include "../include/Word.h"
#include "../include/Verb.h"

Verb::Verb()
{

}

Verb::Verb(std::vector<Word> v) : Phrase(v)
{
	terminal = true;
}

void Verb::setPhraseType()
{
	phraseType = verb;
}
