OBJECTS = lexer.o parser.tab.o symbol.o init.o error.o main.o
SOURCES = lexer.c parser.y symbol.c init.c error.c main.c
EXE = infix2postfix
CFLAGS += -Wall -g

$(EXE):	$(OBJECTS)
	gcc $(CFLAGS) -o $(EXE) $(OBJECTS)

main.o: 	main.c global.h
	gcc $(CFLAGS) -c main.c

lexer.o: 	lexer.c global.h parser.tab.h
	gcc $(CFLAGS) -c lexer.c

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

symbol.o: 	symbol.c global.h
	gcc $(CFLAGS) -c symbol.c

init.o: 	init.c global.h
	gcc $(CFLAGS) -c init.c

error.o: 	error.c global.h
	gcc $(CFLAGS) -c error.c

clean:
	rm -f $(EXE) $(OBJECTS) 29.tar.gz 29.zip *~ parser.tab.*

archives: clean
	cd ..; rm 29.tar 29.zip 29/29.tar 29/29.zip; tar -cvf 29.tar 29; gzip -9 29.tar; zip -r 29.zip 29; mv 29.zip 29/29.zip; mv 29.tar.gz 29/29.tar.gz
