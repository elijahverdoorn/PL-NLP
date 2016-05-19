#ifndef _ADJECTIVE_
#define _ADJECTIVE_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Phrase.h"

class Adjective: public Phrase
{

public:
	//constructors
	Adjective();
	Adjective(std::vector<std::string> v);

private:
	void setPhraseType();
};

#endif