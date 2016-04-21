current: SentenceTest

SentenceTest.o: SentenceTest.cpp
	g++ -c -std=c++11 SentenceTest.cpp

SentenceTest: SentenceTest.o Sentence.o
	g++ -o SentenceTest SentenceTest.o Sentence.o

Sentence.o: Sentence.cpp Sentence.h
	g++ -c -std=c++11 Sentence.cpp

clean:
	rm *.o