#include "user.h"
#include "stat.h"
#include "types.h"
int main( int argc, char *argv[]) {
 
 char b[10][100];
 char buf[500];
 int i,handle;
 int c=0;
 int n,j;
 int l=0;
 int state=0;
 
 printf(1,"The Count is %d",argc); 
 
 if (argc > 1) {
     for(i = 1; i < argc; i++) {
     if ((handle = open(argv[i], 0)) < 0) {
         printf(1,"head: cannot open %s\n", argv[i]);
         exit();
     }
     printf(1,"File Opened\n");
     for(i=0; i<10; i++){
     if((n = read(handle,buf,sizeof(buf))) > 0) {
     //    for(i=0; i<10; i++){
        while(l<10) {  
           for(i=0;i<n;i++) {
              if(buf[i]=='\n') {
                   l++;
                   for(j=state;j<i;j++) {
                       printf(1,"%c",buf[j]);
                   }
                   state=i;
                   printf(1,"%d",l);
                 printf(1,"\n----------\n");
               }
            } 
        }   
            //printf(1,"\n----------------------\n");
      }          
   }
     close(handle);
  }
  } else { 
 
 printf(1,"Enter your Input that you may want to print!\n");
 //while(c < 10) {
 for(i=0;i<10;i++) {
 n = read(0,b[i],sizeof(b[i]));
// printf(1,"%d\n",n);
 c++;
 }
 //printf(1,"%s",b[1]);
 for(i=0;i<10;i++) {
 printf(1,"%s",b[i]);
// printf(1,"\n----------------------\n");
 }
}
exit();
}
