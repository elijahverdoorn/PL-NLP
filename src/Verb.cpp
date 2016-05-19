#include "../include/Verb.h"

Verb::Verb()
{

}

Verb::Verb(std::vector<std::string> v) : Phrase(v)
{
	terminal = true;
}

void Verb::setPhraseType()
{
	phraseType = verb;
}
