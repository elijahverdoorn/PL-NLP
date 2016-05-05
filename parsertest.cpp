#include <iostream>
#include <vector>
using namespace std;
#include "Phrase.h"
#include "NounPhrase.h"
#include "Noun.h"
#include "VerbPhrase.h"
#include "Verb.h"
#include "Adjective.h"

vector<Phrase> parse (vector<Phrase>& v, int pos=0) {
  if (v[pos].getPhraseType() != PhraseType.sentence) {
    if (v[pos].isTerminal) {
      if (isPhrase(v[pos])) {
        buildPhrase(v[pos]);
      } else if (isPhrase(v[pos], v[pos+1])) {
	parse( buildPhrase(v[pos], v[pos+1]), 0);
      }
    } else parse(v, pos+1)
  } else return v;
}

int main () {
  //vector<Phrase> testPhrase = {     }
  parse( testPhrase );


}
