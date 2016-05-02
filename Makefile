current: SentenceTest

SentenceTest.o: SentenceTest.cpp
	g++ -c -std=c++11 SentenceTest.cpp

SentenceTest: SentenceTest.o Sentence.o Word.o Phrase.o Verb.o Adjective.o Verb.o
	g++ -o SentenceTest SentenceTest.o Sentence.o Word.o Phrase.o Noun.o Adjective.o Verb.o

Sentence.o: Sentence.cpp Sentence.h Word.h Word.o
	g++ -c -std=c++11 Sentence.cpp

Word.o: Word.cpp Word.h
	g++ -c -std=c++11 Word.cpp
	
Phrase.o: Phrase.h Phrase.cpp
	g++ -c -std=c++11 Phrase.cpp

Noun.o: Phrase.h Phrase.cpp Noun.h Noun.cpp
	g++ -c -std=c++11 Noun.cpp

Adjective.o: Phrase.h Phrase.cpp Adjective.h Adjective.cpp
	g++ -c -std=c++11 Adjective.cpp

Verb.o: Phrase.h Phrase.cpp Verb.h Verb.cpp
	g++ -c -std=c++11 Verb.cpp

clean:
	rm *.o