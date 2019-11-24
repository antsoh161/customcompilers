/* example.y */

%{
#define YYERROR_VERBOSE
#include <stdio.h>
#include "global.h"
extern int yyerror(char const *msg);
extern int yylex();
%}

%token DIV MOD DONE ID NUM
%left '-' '+'
%left '*' '/'
%left '%'
%right '='

%%

list : 	  	  	  id '=' expr ';' 			{symtable[$1].value=$3; printf("\n%s = %d \n\n",symtable[$1].lexeme, $3);} list
	    		| expr ';'					{printf("\n=%d\n",$1);} list
				| /* Empty */
				;

/*assignment : 	  id '=' expr 				{$$ = symtable[$1].value; printf("\nfrom assignment: %s=%d\n",symtable[$1].lexeme, $3);} */
				;

id : 			  ID 						{$$ = $1; printf("from ID: %s\n", symtable[$1].lexeme);}
				;

expr :			  expr '+' term				{$$ = $1 + $3; printf("adding %d + %d\n",$1,$3);}
				| expr '-' term				{$$ = $1 - $3; printf("-\n");}
				| term						
				;

term :			  term '*' factor			{$$ = $1 * $3; printf("*\n");}
				| term '/' factor			{$$ = $1 / $3; printf("/\n");}
				| factor					{$$ = $1;}
				;

factor :		  '(' expr ')'				{$$ = $2;}
				| id						{$$ = symtable[$1].value;}
	 			| NUM						{$$ = $1; printf("%d\n", $1);}
				;



%%

int yyerror(char const *msg) {
    error(msg);
    return 0;
}

void parse(){
	yyparse();
}

yylex(){
	lexan();
}


