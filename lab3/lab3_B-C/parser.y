
%{
#define YYERROR_VERBOSE
#define YYDEBUG 1
#include <stdio.h>
#include "global.h"
extern int yyerror(char const *msg);
extern int yylex();
int power(int op2, unsigned int op1);
%}

%debug
%printer {fprintf(yyoutput, "%d", $$);} <>

%token DIV MOD DONE ID NUM
%right '^'
%left '*' '/' '%'
%left '+' '-'
%left '<' '>'
%left '&'
%left '|'
%right '?'
%right '='

%%

list :    	 assignment	';'	list
			| expr ';'						{printf("=%d\n",$1);} list
			| /* Empty */
			;

assignment :  id '=' expr 				{symtable[$1].value=$3; printf("%s = %d\n",symtable[$1].lexeme,$3);}
			  ;

expr :	 	  expr '+' term				{$$ = $1 + $3; printf("+\n");}
			| expr '-' term				{$$ = $1 - $3; printf("-\n");}
			| expr '&' term 			{$$ = $1 & $3; printf("&\n");}
			| expr '|' term				{$$ = $1 | $3; printf("|\n");}
			| expr '>' term				{$$ = $1 >> $3; printf(">\n");}
			| expr '<' term				{$$ = $1 << $3; printf("<\n");}
			| expr '?' expr ':' expr %prec '?'	{$$ = $1 ? $3 : $4;}
			| term						
			;

term :		  term '*' factor		{$$ = $1 * $3; printf("*\n");}
			| term '/' factor		{$$ = $1 / $3; printf("/\n");}
			| term '%' factor		{$$ = $1 % $3; printf("%%\n");} 
			| factor
			;
				
factor : 	  factor '^' expo 		{$$ = power($1,$3);printf("^\n");}
			| expo	
			;

expo :	      '(' expr ')'			{$$ = $2;}
			| id					{$$ = symtable[$1].value; printf("%d\n",symtable[$1].value);}
			| NUM					{$$ = $1; printf("%d\n", $1);}
			;		

id : 		 ID						{$$ = $1; printf("%s\n",symtable[$1].lexeme);}
			;


%%

int yyerror(char const *msg) {
    error(msg);
    return 0;
}

void parse(){
	yyparse();
}

int yylex(){
	return lexan();
}

int power(int op2, unsigned int op1) 
{ 
    if (op1 == 0) 
        return 1; 
    else if (op1%2 == 0) 
        return power(op2, op1/2)*power(op2, op1/2); 
    else
        return op2*power(op2, op1/2)*power(op2, op1/2); 
} 
