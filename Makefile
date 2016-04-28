current: SentenceTest

all: Word.cpp Sentence.cpp

SentenceTest.o: SentenceTest.cpp
	g++ -c -std=c++11 SentenceTest.cpp

SentenceTest: SentenceTest.o Sentence.o Word.o
	g++ -o SentenceTest SentenceTest.o Sentence.o Word.o

Sentence.o: Sentence.cpp Sentence.h Word.h Word.o
	g++ -c -std=c++11 Sentence.cpp

Word.o: Word.cpp Word.h
	g++ -c -std=c++11 Word.cpp
	
clean:
	rm *.o