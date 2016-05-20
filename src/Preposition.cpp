#include "../include/Preposition.h"

Preposition::Preposition()
{

}

Preposition::Preposition(std::vector<std::string> v) : Phrase(v)
{
	terminal = true;
}

void Preposition::setPhraseType()
{
	phraseType = prep;
}
						       
