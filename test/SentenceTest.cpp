#include <iostream>
#include <string>
#include <vector>
#include "Sentence.h"

int main(int argc, char const *argv[])
{
	std::cout << "Enter a Sentence:" << std::endl;	

	std::string userInput;
	std::getline(std::cin, userInput);

	Sentence mySentence (userInput);
	//mySentence.printTokens();
	
	mySentence.printParsedSentence();
	return 0;
}
