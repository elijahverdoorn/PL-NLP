#include "Word.h"

Word::Word() {
	word = "example";
}

Word::Word(std::string w) {
	word = w;
}

void Word::printWord() {
	cout << "Word: " << word << endl;
}

void Word::printWordType() {
	cout << "Word: " << word << " Type: " << type << endl;
}

string Word::returnWordType() {
	return "Word: " + word + " Type: " + WordTypeToString[type];
}

string Word::getType() {
  int numTypes = 7;
  string typeLabels [numTypes] = {"adjective", "adverb", "article", "conjunction", "noun", "subject", "verb"};
  string typeFiles [numTypes] = {"adjectives.txt", "adverbs.txt", "articles.txt", "conjunctions.txt", "nouns.txt", "subject.txt", "verbs.txt"};
  for (int i = 0; i < numTypes; i++) {
    ifstream in(typeFiles[i].c_str());
    string databaseWord;
    while (in>>databaseWord) {   
      if (strcmp(word.c_str(), databaseWord.c_str()) == 0 ) {
	in.close();
	return typeLabels[i];
      }
    }
    in.close();
  }
  return "invalid";
}