
%{
#include <stdio.h>
#include <string.h>
#include "global.h"
int yylval = NONE;
int lineno = 1;
int token_value = NONE;
%}



%option noyywrap nounput noinput

%%

[ \t]+			{ /* Ignore Whitspace */}
[0-9]+			{ token_value = atoi(yytext); return NUM;}
[a-zA-Z_][a-zA-z0-9_]*  { token_value = insert(yytext,ID); return ID;}

"("	{return '(';}
")"	{return ')';}
"+"	{return '+';}
"-"	{return '-';}
"*"	{return '*';}
"/"	{return '/';}
"%"	{return '%';}
"\n"	{lineno++;}
";"	{return ';';}
%%

int lexan(){
	return yylex();
}

int yyerror(char const *msg){
	error(msg);
	return 0;
}
