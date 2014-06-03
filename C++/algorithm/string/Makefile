main:main.o qh_string.o
	g++ -o main qh_string.o main.o
qh_string.o:qh_string.cpp qh_string.h
	g++ -c qh_string.cpp
main.o:main.cpp qh_string.h
	g++ -c main.cpp
clean:
	rm main.o qh_string.o main
install:
	mv *.o ../extern/
