// Including Header Files
#include "user.h"
#include "stat.h"
#include "types.h"

// Buffer Declaration to store the data being read
char buf[2000];

/*
 * Function:  head 
 * --------------------
 * Arguments: 
 *     File Handle (Handle for Files and Zero for Pipeline)
 *     Number of Lines
 *     File Names
 * 
 * Prints "n" lines of data read from a file :
 * n: number of lines that should be printed
 *
 * returns: pushes the selected number of lines to stdout
 *           prints error if n is 0
 */

void head(int handle, int lines, char *name) { 
     int k,l,n;
     l=n=0;
     while((n = read(handle,buf,sizeof(buf))) > 0) {
        for(k=0;k<n;k++) {
          printf(1,"%c",buf[k]);
           if(buf[k]=='\n') {
                 l++;
                 if(l == lines) {
                      break;
                 }
           }
        }
        if(l == lines) {
           break;
        }

     }
     if(n < 0){
       printf(1, "head: read error\n");
       exit();
     }
}

/*
 * Function: Number 
 * --------------------
 * The Number Function: Converts the Number of lines argument to integer
 * (Handles the '-' sign present in the argument)
 * 
 * Arguments:
 *   a[] : Character array of the argument string
 *
 * returns: 
 *  Number of lines - integet type
 *  Default number of lines - 10 (In case of improper or no argument)
 * 
 */

int number(char a[]) {
  int n;
  if(a[0] == '-') {
     n=atoi(a+1);
  } else {
     n = 10;
  }
return n;
}


/*
 * Function:  MAIN 
 * --------------------
 * The MAIN Function: Inputs the data and call the HEAD Function
 *
 * Arguments:
 *  n: number of lines that should be printed
 *
 * returns: 
 *  pushes the selected number of lines to stdout through HEAD Call
 *  prints error and usage help when there are no arguments
 * 
 */

int main( int argc, char *argv[]) {
 
  int i,handle;
  int lines;

/*
// Argument: N number of lines missing - Error Condition

   if (argc <= 1) {
       printf(1,"Usage: head [LINES]... [FILE]..\n");
       printf(1,"Help: head 3 FILE --> Prints 3 lines from FILE\n");
       exit();
   }
*/

// Argument: Number of Lines Only

   if(argc <= 2){
     lines = number(argv[1]);
     head(0, lines, "");
     exit();
   }

// Argument: Number of Lines + File Names

    if (argc > 2) {
      lines = number(argv[1]);
      for(i = 2; i < argc; i++) {
        if ((handle = open(argv[i], 0)) < 0) {
          printf(1,"head: cannot open %s\n", argv[i]);
          exit();
        }
        head(handle, lines, argv[i]);
        close(handle);
      }          
   }   
  exit();
}
