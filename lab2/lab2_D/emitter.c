/* emitter.c */

#include "global.h"

int power(int op2, unsigned int op1) 
{ 
    if (op1 == 0) 
        return 1; 
    else if (op1%2 == 0) 
        return power(op2, op1/2)*power(op2, op1/2); 
    else
        return op2*power(op2, op1/2)*power(op2, op1/2); 
} 
  

int calc(int token_type){
    int op1 = pop();
    int op2 = pop();
    switch(token_type){
        case '+' :
            return op1+op2;
        case '-' :
            return op1-op2;
        case '*' : 
            return op1*op2;
        case '/' : 
            return op1/op2;
        case '^' : 
            return power(op2,op1); /* op2^(op1) då op1 är expontenten då den poppas först */
        default:
            printf("[Unknown token %d, with value %d]\n", token_type, token_value);
            return 0;
    }
}

void emit (int token_type, int token_value)  /*  generates output  */
{
    switch(token_type) {
        case '+' : case '-' : case '*' : case '/' : case '^' : 
            printf("%c\n",token_type); push(NUM,calc(token_type)); break;
        case NUM : 
            printf("%d\n",token_value); push(token_type, token_value);break;
        case ID : 
            printf("%s\n",symtable[token_value].lexeme); push(token_type,token_value);break;
        case '=' :
            printf("%c\n",token_type);
            int op1 = pop();
            int op2 = pop();
            symtable[op2].value = op1;
            printf("result: %d\n",op1);break;
            
    default:     
        printf("[Unknown token %d, with value %d]\n", token_type, token_value);
    }
}
