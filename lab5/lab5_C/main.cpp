 /* main.c */

#include "global.hpp"

int main(void)
{   
    printf("Type your code in c++ and execute your program with the 'exec' command\n");
    init();
    yydebug = !!getenv("YYDEBUG");
    parse();
    exit(0);    /*  successful termination  */
}
