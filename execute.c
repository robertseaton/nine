/* Copyright (c) 2011, Robert Seaton
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice, this
 *     list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * * */

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>

#include "includes.h"

void execute (int argc, char* argv[])
{
     struct plan9_exec header;
     long buf[8];
     int fd = open(argv[1], O_RDONLY);
     void* fpos;

     read(fd, buf, 8 * sizeof(long));
     header.magic = ntohl(buf[0]);
     header.text = ntohl(buf[1]);
     header.data = ntohl(buf[2]);
     header.bss = ntohl(buf[3]);
     header.syms = ntohl(buf[4]);
     header.entry = ntohl(buf[5]);
     header.spsz = ntohl(buf[6]);
     header.pcsz = ntohl(buf[7]);

     verify(header.magic);

     /* map TEXT segment in */
     fpos = mmap(STR_ADDR, TXT_ADDR(header), PROT_READ | PROT_EXEC, 
                 MAP_PRIVATE | MAP_FIXED | MAP_EXECUTABLE, fd, 0);
     if (fpos == -1) 
          error("Error: kernels after 2.6.26 prevent non-root applications from mmaping adresses below 4096, either run the effected program as root or remove this limitation via sysctl -w vm.mmap_min_addr=\"0\"");
     /* map DATA section + bss segment at next page aligned address */
     fpos = mmap(STR_ADDR + page_align(TXT_ADDR(header)), header.data + header.bss, PROT_READ | PROT_WRITE, 
                 MAP_PRIVATE | MAP_FIXED, fd, 0);

     void (*init_func)(void);
     init_func = header.entry;
     init_func();
     
}
