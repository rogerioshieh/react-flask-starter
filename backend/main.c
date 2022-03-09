/*****************************************************************************
/* This script was adapted from https://askubuntu.com/a/1188063
/*****************************************************************************
*
* bla.c 2019.11.11 Smythies
*       attempt to invoke OOM by asking for a rediculous amount of memory
*       see: https://askubuntu.com/questions/1188024/how-to-test-oom-killer-from-command-line
*       still do it slowly, in chunks, so it can be monitored.
*       However simplify the original testm.c, for this example.
*
* testm.cpp 2013.01.06 Smythies
*           added a couple more sleeps, in attempts to observe stuff on linux.
*
* testm.cpp 2010.12.14 Smythies
*           attempt to compile on Ubuntu Linux.
*
* testm.cpp 2009:03:18 Smythies
*           This is not the first edit, but I am just adding the history header.
*           How much memory can this one program ask for and sucessfully get?
*           Done in two calls, to more accurately simulate the program I and wondering about.
*           This edit is a simple change to print the total.
*           the sleep calls have changed (again) for MS C version 2008.
*           Now they are more like they used to be (getting annoying).
*                                                                     Smythies
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define CR 13

int main(){
   char *fptr;
   long i, k;

   i = 50000000000L;

   do{
      if(( fptr = (char *)malloc(i)) == NULL){
         i = i - 1000;
      }
   }
   while (( fptr == NULL) && (i > 0));

   sleep(4);  /* for time to observe */
   for(k = 0; k < i; k++){   /* so that the memory really gets allocated and not just reserved */
      fptr[k] = (char) (k & 255);
   } /* endfor */
   sleep(60);  /* O.K. now you have 1 minute */
   free(fptr); /* clean up, if we get here */
   return(0);
}