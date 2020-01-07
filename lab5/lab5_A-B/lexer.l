
%{
#include <stdio.h>
#include <string.h>
#include "global.hpp"
//int yylval = NONE;
int lineno = 1;
int token_value = NONE;
int lookup_helper(char* s);
%}



%option noyywrap nounput noinput

%%

[ \t]+			{ /* Ignore Whitspace */}
[0-9]+			{ token_value = atoi(yytext); yylval = token_value; return NUM;}
[a-zA-Z_][a-zA-z0-9_]*  { token_value = lookup_helper(yytext); yylval = token_value; return ID;}

"("	{return '(';}
")"	{return ')';}
"+"	{return '+';}
"-"	{return '-';}
"*"	{return '*';}
"/"	{return '/';}
"%"	{return '%';}
"\n"	{lineno++;}
"&"	{return '&';}
"|"	{return '|';}
"<"	{return '<';}
">"	{return '>';}
"?"	{return '?';}
":"	{return ':';}
";"	{return ';';}
"="	{return '=';}
%%

int lexan(){
	return yylex();
}

int lookup_helper(char *s){
	int id_number = lookup(s);
	if(id_number == -1){
		return insert(yytext,ID);
	}
	else{
		return id_number;
	}
}

/*
int yyerror(char const *msg){
	error(msg);
	return 0;
}
*/
