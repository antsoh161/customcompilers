 /* main.c */

#include "global.h"
#include "parser.tab.h"

int main(void)
{
    init();
    yydebug = !!getenv("YYDEBUG");
    parse();
    exit(0);    /*  successful termination  */
}
