/* global.h */

#include <stdio.h>  /* include declarations for i/o routines */
#include <ctype.h>  /* ... and for character test routines */
#include <stdlib.h> /* ... and for some standard routines, such as exit */
#include <string.h> /* ... and for string routines */
#include "parser.tab.hpp"
#define MAX_ID_LENGTH  128  /* for the buffer size */
#define MAX_ARGS 3

#define NONE   -1
#define EOS    '\0'

/*
#define NUM    256
#define DIV    257
#define MOD    258
#define ID     259
#define DONE   260
*/

extern int token_value;   /*  value of token attribute */  
extern int lineno;

struct symentry {  /*  form of symbol table entry  */
    char *lexeme; 
    int  token_type;    
    int value;		/*	för att lagra värden */
};

struct TreeNode{
	int type;
	int leaf_value;
	TreeNode* args[MAX_ARGS];
};

typedef struct TreeNode TreeNode;

extern TreeNode* mkleaf(int type, int value);
extern TreeNode* mknode(int type, TreeNode* a0 = 0, TreeNode* a1 = 0, TreeNode* a2 = 0);


extern struct symentry symtable[];  /* symbol table  */

extern void init();  /*  loads keywords into symtable  */
extern void error(const char* message);  /*  generates all error messages  */
extern int lexan();  /*  lexical analyzer  */
extern void parse();  /*  parses and translates expression list  */
extern int insert(char *s, int token_type);    /*  returns position of entry for s */
extern int lookup(char *s);         /* returns position of entry for s, or -1 if not found */
extern void emit (int token_type, int token_value);  /*  generates output  */
extern void push(int token_type, int value);
extern int pop();
