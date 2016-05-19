#include "../include/Adjective.h"

Adjective::Adjective()
{

}

Adjective::Adjective(std::vector<std::string> v) : Phrase(v)
{
	terminal = true;
}

void Adjective::setPhraseType()
{
	phraseType = adjective;
}
