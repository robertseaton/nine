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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "includes.h"

void print_version ()
{
     printf("nine v0.01 by Robert Seaton\n");
}

void print_usage ()
{
     print_version();
     printf("usage: nine PROGRAM [ARGUMENTS...]  run the specified program\n");
     printf("       nine -h, --help              print this message then exit\n");
     printf("       nine -v, --version           print version information then exit\n");
}

void parse_args (int argc, char* argv[])
{
     if (argc == 1 || strstr(argv[1], "-h") != NULL)
          print_usage();
     else if (strstr(argv[1], "-v") != NULL)
          print_version();
     else
          execute(argc, argv);
}

int main (int argc, char* argv[])
{
     parse_args(argc, argv);
}
