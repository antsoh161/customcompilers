 /* main.c */

#include "global.hpp"

int main(void)
{
    init();
    yydebug = !!getenv("YYDEBUG");
    parse();
    exit(0);    /*  successful termination  */
}
