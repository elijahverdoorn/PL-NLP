#include "Word.h"
#include "Adjective.h"

Adjective::Adjective()
{

}

Adjective::Adjective(std::vector<Word> v) : Phrase(v)
{
	terminal = true;
}

void Adjective::setPhraseType()
{
	phraseType = adjective;
}
