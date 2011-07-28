#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "includes.h"

void print_usage ()
{
     printf("nine v0.01 by Robert Seaton\n");
     printf("usage: nine [flags] program\n");
     printf("flags:\n");
     printf("-h, --help: print this message then exit\n");
     printf("-v, --version: print version information then exit\n");
}

void print_version ()
{
     printf("nine v0.01 by Robert Seaton\n");
}

void parse_args (int argc, char* argv[])
{
     if (strstr(argv[1], "-v") != NULL)
          print_version();
     else if (strstr(argv[1], "-h") != NULL || argc != 2)
          print_usage();
     else
          execute(argv[1]);
}

int main (int argc, char* argv[])
{
     parse_args(argc, argv); 
}
