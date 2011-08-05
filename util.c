#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "includes.h"

void error (char* s)
{
     fprintf(stderr, "%s\n", s);
     exit(1);
}

void verify (long magic)
{
     if (magic != A_MAGIC &&
          magic != I_MAGIC &&
          magic != J_MAGIC &&
          magic != K_MAGIC &&
          magic != V_MAGIC &&
          magic != X_MAGIC &&
          magic != M_MAGIC &&
          magic != D_MAGIC &&
          magic != E_MAGIC &&
          magic != Q_MAGIC &&
          magic != N_MAGIC &&
          magic != L_MAGIC &&
          magic != P_MAGIC &&
          magic != U_MAGIC)
          error("Error: not a Plan 9 binary.");
     else if (magic != I_MAGIC)
          error("Error: wrong architecture, must be i386.");
}

void* page_align (void* addr)
{
     int i = 0;
     int sz = getpagesize();
     while ((void*)(i * sz) < addr)
          i++;
     
     return (i * sz);
}
