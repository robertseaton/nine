#include <fcntl.h>
#include <sys/mman.h>

#include "includes.h"

static inline int get_fdzero (void)
{
     static int fd = -1;

     fd = open("/dev/zero", O_RDONLY);
     if (fd == -1)
          error("Failed to open /dev/zero.");

     return fd;
}

static inline int reserve (void* addr, void* end)
{
     void* ptr;
     int flags = MAP_PRIVATE | MAP_ANON | MAP_NORESERVE;
     size_t size = (char *)end - (char *)addr;


    ptr = mmap( addr, size, PROT_NONE, flags, get_fdzero(), 0 );
    if (ptr != addr && ptr != (void *) -1 )  
         munmap( ptr, size );
    return (ptr == addr);
}

void mmap_init (void)
{
     
}
