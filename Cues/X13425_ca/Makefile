OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

tar: program.exe CuaIOParInt.hh CuaIOParInt.cc program.cc Makefile
	tar -cvf entrega.tar program.exe CuaIOParInt.hh CuaIOParInt.cc program.cc Makefile

program.exe: program.o CuaIOParInt.o ParInt.o
	g++ -o program.exe program.o CuaIOParInt.o ParInt.o

ParInt.o:  ParInt.cc ParInt.hh 
	g++ -c ParInt.cc $(OPCIONS)

CuaIOParInt.o:  CuaIOParInt.cc CuaIOParInt.hh
	g++ -c CuaIOParInt.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
