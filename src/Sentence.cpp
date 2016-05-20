#include "../include/Sentence.h"

Sentence::Sentence()
{

}

Sentence::Sentence(std::vector<std::string> v) : Phrase(v)
{
	terminal = false;
	setPhraseType();
}

void Sentence::setPhraseType()
{
	phraseType = sentence;
}
