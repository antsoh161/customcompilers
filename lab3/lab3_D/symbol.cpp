/* symbol.c */

#include "global.hpp"
#include "parser.tab.hpp"

#define MAX_SYMBOLS 100  /* size of symbol table */

struct symentry symtable[MAX_SYMBOLS];
struct symentry stack[MAX_SYMBOLS];
int nr_symbols = 0;    /* number of symbols in symtable  */
int top_of_stack = -1; /* tom stack */

int lookup(char *s)         /* returns position of entry for s, or -1 if not found */
{
    for (int p = nr_symbols - 1; p >= 0; --p)
        if (strcmp(symtable[p].lexeme, s) == 0)
            return p;
    return -1;
}

void push(int token_type, int value){
    struct symentry entry;
    entry.token_type = token_type;
    entry.value = value;
    top_of_stack++;
    stack[top_of_stack] = entry;
}

int pop(int from_symtable){
    struct symentry entry;
    if(top_of_stack > -1){
       entry = stack[top_of_stack];
       top_of_stack--;
       if(entry.token_type == ID && from_symtable == 1){    /* Om entry:et är en identifierare, ta dess värde */ 
            return symtable[entry.value].value;
       }
       else{    
             return entry.value;
       }
    }
    else{
        error("trying to pop from empty stack\n");
        return 0;
    }
}



int insert(char *s, int token_type)    /*  returns position of entry for s */
{
    if (nr_symbols >= MAX_SYMBOLS)
        error("Symbol table full");
    symtable[nr_symbols].token_type = token_type;
    symtable[nr_symbols].lexeme = strdup(s);
    symtable[nr_symbols].value = 0;
    return nr_symbols++;
}
