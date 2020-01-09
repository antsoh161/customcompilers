#include <stdio.h>
#include <iostream>
#include "global.hpp"

int calc(int type, int op1, int op2){
	//printf("Calculating %d %c %d\n",op1,type,op2);
	switch(type){
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '/':
			return op1/op2;
		case '*':
			return op1*op2;
		case '%':
			return op1%op2;
		case '<':
			return op1<op2;
		case '>':
			return op1>op2;
		case '&':
			return op1&op2;
		case '|':
			return op1|op2;
		default:
			return 0; 
	}
}


int treeExec(TreeNode *p){
	if(p == 0){
		return -1;
	}

	int nr_args = 0;
	for(int i = 0; i < 3; i++){
		if(p->args[i] != 0)
			nr_args++;
	}

	switch(p->type){
		case LIST:
			treeExec(p->args[0]);
			if(nr_args>1)
				treeExec(p->args[1]); //Om andra noden existerar
		case NUM:
			return p->leaf_value;
		case ID:
			return symtable[p->leaf_value].value;
		/* Operatorer som använder calc() */
		case '+': case '-': case '/': case '*': case '%':
		case '>': case '<': case '&': case '|':
			return calc(p->type,treeExec(p->args[0]),treeExec(p->args[1]));
		case '=':{
			int equalto = treeExec(p->args[1]);
			printf("\tSetting %s = %d\n", symtable[p->args[0]->leaf_value].lexeme, equalto);
			symtable[p->args[0]->leaf_value].value = equalto;
			break;
		}
		case IF:
			if(treeExec(p->args[0])){ //Om påståendet är sant, exekvera if-blocket
				treeExec(p->args[1]);
			}
			else if(nr_args > 1)	//Om else-satsen existerar
				treeExec(p->args[2]);
			break;
		case ELSE: case BLOCK:
			if(nr_args > 1)
				treeExec(p->args[0]); //Else-satsen block och vi kommer endast hit genom ovanstående else if sats
		case WHILE:
			while(treeExec(p->args[0])){
				treeExec(p->args[1]); // Medans villkoret är sant, exekvera blocket
			}
			break;
		case PRINT:
			printf("%d\n",treeExec(p->args[0]));
			break;
		case READ:{
			int n;
			printf("Enter value for variable %s\n",symtable[p->args[0]->leaf_value].lexeme);
			std::cin >> n;
			symtable[p->args[0]->leaf_value].value = n;
			break;
		}
	}
	return 0;
}
