#include <stdlib.h>
#include <stdio.h>

#include "includes.h"

void error (char* s)
{
     fprintf(stderr, "%s\n", s);
     exit(1);
}

void verify (char prog[])
{
     if (prog[2] != '\001' || prog[3] != '\353')
          error("Not a valid Plan 9 binary. Exiting...");
}
