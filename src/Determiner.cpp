#include "../include/Determiner.h"

Det::Det()
{

}

Det::Det(std::vector<std::string> v) : Phrase(v)
{
	terminal = true;
}

void Det::setPhraseType()
{
	phraseType = det;
}
