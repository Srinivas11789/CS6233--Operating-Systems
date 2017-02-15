#include "user.h"
#include "stat.h"
#include "types.h"
int main( int argc, char *argv[]) {
 
// char b[10][100];
 char buf[2000];
 int i,handle;
 int n,j,k;
 int l=0;
 int state=0;
 int lines;
 n=0;
 
 if (argc > 1) {
   lines = atoi(argv[1]);
   printf(1,"The program will print %d lines\n",lines);
 } else {
    printf(1,"Enter the Number of lines to be printed !");
    exit();
 }

 if (argc > 2) {
     for(i = 2; i < argc; i++) {
     if ((handle = open(argv[i], 0)) < 0) {
         printf(1,"head: cannot open %s\n", argv[i]);
         exit();
     }
     printf(1,"File Opened\n");
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
      }          
     close(handle);
  } else { 
 
printf(1,"Enter your Input that you may want to print!\n");

/*
for(i=0;i<lines;i++) {
n = read(0,b[i],sizeof(b[i]));
}
for(i=0;i<lines;i++) {
printf(1,"%s",b[i]);
}
*/


/*
for(i=0;i<lines;i++) {
for(j=0;j<sizeof(b[i]);j++) {
if (b[i][j] == '\n') {
for(k=state;k<j;k++) {
if(l<lines) {
printf(1,"%c",b[i][k]);
}
}
l++;
state = j;
}
}
}
*/




     if((n = read(0,buf,sizeof(buf))) > 0) {
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
  
}

exit();
}
