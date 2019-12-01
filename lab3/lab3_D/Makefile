OBJECTS = lexer.o parser.tab.o symbol.o init.o error.o main.o
SOURCES = lexer.cpp parser.y symbol.cpp init.cpp error.cpp main.cpp
EXE = infix2postfix
CFLAGS += -Wall -g

$(EXE):	$(OBJECTS)
	g++ $(CFLAGS) -o $(EXE) $(OBJECTS)

main.o: 	main.cpp global.hpp
	g++ $(CFLAGS) -c main.cpp

lexer.o: 	lexer.cpp global.hpp parser.tab.hpp
	g++ $(CFLAGS) -c lexer.cpp

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d --debug --verbose parser.ypp

symbol.o: 	symbol.cpp global.hpp
	g++ $(CFLAGS) -c symbol.cpp

init.o: 	init.cpp global.hpp
	g++ $(CFLAGS) -c init.cpp

error.o: 	error.cpp global.hpp
	g++ $(CFLAGS) -c error.cpp

clean:
	rm -f $(EXE) $(OBJECTS) 29.tar.gz 29.zip *~ parser.tab.*

archives: clean
	cd ..; rm 29.tar 29.zip 29/29.tar 29/29.zip; tar -cvf 29.tar 29; gzip -9 29.tar; zip -r 29.zip 29; mv 29.zip 29/29.zip; mv 29.tar.gz 29/29.tar.gz
