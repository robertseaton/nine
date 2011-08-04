#ifndef INCLUDES_H


#define _MAGIC(f, b)    ((f)|((((4*(b))+0)*(b))+7))
#define	I_MAGIC		_MAGIC(0, 11)		/* intel 386 */

/* execute.c */
void nine_init (int, char* []);

/* util.c */
void verify (char[]);
void error (char*);

/* mmap.c */
void mmap_init(void);
#define INCLUDES_H
#endif
