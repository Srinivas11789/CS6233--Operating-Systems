#include "user.h"
#include "stat.h"
#include "types.h"

char buf[2000];

void head(int handle, int lines, char *name) { 
     int j,k;
     int state=0;
     int l=0;
     int n=0;
     if((n = read(handle,buf,sizeof(buf))) > 0) {
        for(k=0;k<n;k++) {
           if(buf[k]=='\n') {
              for(j=state;j<k;j++) {
                  if(l<lines) {
                      printf(1,"%c",buf[j]);
                    }
              }
              l++;
              state=k;
            }
        }

     }
     if(n < 0){
       printf(1, "wc: read error\n");
       exit();
      }
}



int main( int argc, char *argv[]) {
 
  int i,handle;
  int lines;

   if (argc <= 1) {
       printf(1,"Usage: head [LINES]... [FILE]..\n");
       printf(1,"Help: head 3 FILE --> Prints 3 lines from FILE\n");
       exit();
   }

   if(argc == 2){
     lines = atoi(argv[1]);
     head(0, lines, "");
     exit();
   }

    if (argc > 2) {
      lines = atoi(argv[1]);
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
