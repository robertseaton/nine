#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "includes.h"

static char *bindir;

/* return the directory that contains the main binary at run time */
static char* get_runtime_bindir (const char* argv)
{
     char* p, *bindir;
     int size;

     for (size = 256; ; size *= 2) {
          int ret;
          bindir = malloc(size);
          ret = readlink("/proc/self/exe", bindir, size);
          if (ret == -1)
               break;
          if (ret != size) {
               p = memrchr(bindir, '/', ret);
               if (!p)
                    p++;
               *p = 0;
               return bindir;
          }
          free(bindir);
     }
     free(bindir);
}

/* initialize the argv0 path */
void nine_init_argv0_path (const char* argv0)
{
     const char* basename;
     char* libdir;

     if (!(basename = strchr(argv0, '/')))
          basename = argv0;
     else
          basename++;

     bindir = get_runtime_bindir(argv0);
}
