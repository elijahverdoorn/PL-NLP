#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

string getType(string word) {
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

int main() {
  cout << getType("brother") << endl;
  cout << getType("asdf") << endl;
  return 0;
}
