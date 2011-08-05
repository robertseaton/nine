#ifndef INCLUDES_H

struct plan9_exec {
     long magic; /* magic number */
     long text; /* size of text segment */
     long data; /* size of initialized data */
     long bss; /* size of unititalized data */
     long syms; /* size of symbol table */
     long entry; /* entry point */
     long spsz; /* size of pc/sp offset table */
     long pcsz; /* size of pc/line number table */
};

#define HDR_MAGIC	0x00008000	/* header expansion */

#define _MAGIC(f, b)    ((f)|((((4*(b))+0)*(b))+7))
#define A_MAGIC         _MAGIC(0, 8)            /* 68020 */
#define I_MAGIC         _MAGIC(0, 11)           /* intel 386 */
#define J_MAGIC         _MAGIC(0, 12)           /* intel 960 (retired) */
#define K_MAGIC         _MAGIC(0, 13)           /* sparc */
#define V_MAGIC         _MAGIC(0, 16)           /* mips 3000 BE */
#define X_MAGIC         _MAGIC(0, 17)           /* att dsp 3210 (retired) */
#define M_MAGIC         _MAGIC(0, 18)           /* mips 4000 BE */
#define D_MAGIC         _MAGIC(0, 19)           /* amd 29000 (retired) */
#define E_MAGIC         _MAGIC(0, 20)           /* arm */
#define Q_MAGIC         _MAGIC(0, 21)           /* powerpc */
#define N_MAGIC         _MAGIC(0, 22)           /* mips 4000 LE */
#define L_MAGIC         _MAGIC(0, 23)           /* dec alpha */
#define P_MAGIC         _MAGIC(0, 24)           /* mips 3000 LE */
#define U_MAGIC         _MAGIC(0, 25)           /* sparc64 */

#define TOS_SIZE 14	/* Size of Top of Stack: 56 / 4 */
#define HDR_SIZE 0x20
#define STR_ADDR 0x1000	/* Start Address */
#define TXT_ADDR(x) HDR_SIZE + x.text /* TEXT Address */
#define DAT_ADDR(x) STR_ADDR + TXT_ADDR(x) /* DATA & BSS */

/* execute.c */
void execute (int, char* []);

/* util.c */
void verify (long);
void error (char*);
void* page_align(void*);

#define INCLUDES_H
#endif
