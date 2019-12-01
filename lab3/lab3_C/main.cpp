 /* main.c */

#include "global.hpp"
#include "parser.tab.hpp"

int main(void)
{
    init();
    yydebug = !!getenv("YYDEBUG");
    parse();
    exit(0);    /*  successful termination  */
}
