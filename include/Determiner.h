#ifndef _DET_
#define _DET_

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "Phrase.h"

class Det: public Phrase //determiner
{

public:
	//constructors
	Det();
	Det(std::vector<std::string> v);
private:
	void setPhraseType();
};

#endif
