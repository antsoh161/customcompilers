OBJ = parser.tab.o parser.tab.hpp lex.yy.c symbol.o init.o error.o main.o 
SRC = parser.tab.ypp lexer.l symbol.cpp init.cpp error.cpp main.cpp
EXE = infix2postfix
CFLAGS += -Wall -g


infix2postfix:	$(OBJ)
	g++ $(CFLAGS) -o $(EXE) $(OBJ) -lm

main.o: 	main.cpp global.hpp
	g++ $(CFLAGS) -c main.cpp

parsetree.o: parsetree.cpp
	g++ $(CFLAGS) -c parsetree.cpp

lex.yy.c: 	lexer.l global.hpp
	flex lexer.l

parser.tab.cpp parser.tab.hpp: parser.ypp parsetree.o
	bison -d --debug --verbose parser.ypp

symbol.o: 	symbol.cpp global.hpp
	g++ $(CFLAGS) -c symbol.cpp

init.o: 	init.cpp global.hpp
	g++ $(CFLAGS) -c init.cpp

error.o: 	error.cpp global.hpp
	g++ $(CFLAGS) -c error.cpp

clean: 
	rm -f $(EXE) $(OBJ) parser.tab.cpp tree.o 29.tar.gz 29.zip *~

archives: clean
	cd ..; rm 29.tar 29.zip 29/29.tar 29/29.zip; tar -cvf 29.tar 29; gzip -9 29.tar; zip -r 29.zip 29; mv 29.zip 29/29.zip; mv 29.tar.gz 29/29.tar.gz

