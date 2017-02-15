#include "user.h"
#include "stat.h"
#include "types.h"
/*
void head(int handle, char *name) {
    
   if(!name) {
      for(i=0; i<10; i++) {
         print(1,"%s\n",handle)
      }
   }
   else {
      for(i=0; i<10; i++) {
         print(1,"%s\n",handle)
      }
   }
}
*/

char buf[512];

int main(int argc, char *argv[])
{
  int handle,i;
  char buf[500];
  if (argc >= 1) {
  for(i = 1; i < argc; i++) {
     if ((handle = open(argv[i], 0)) < 0) {
         printf(1,"head: cannot open %s\n", argv[i]);
         exit();
     }
     //head(handle,argv[i])
     printf(1,"File Opened\n");
     close(handle);
  }
  } else {
     int n;
     printf(1,"Enter 10 Lines that you may want to print!\n");
     n = fgets(buf, sizeof buf, stdin);
     printf(1,"%s",n);
   //  scanf(1,"%s\n", handle2[i]);
   //    gets(handle2[i])
   //    scanf(1,"%s\n", buf[i]);
     int i,n,c=0;
     //while((n = fgets(buf, sizeof buf, stdin))) > 0){
     //for(i=0; i<n; i++){
     // while(c < 10) {
     // printf(1,"%s",buf[i]);
     // if(buf[i] == '\n') {
     //   c++;
     // }
     // }
     // }
     //for(i=0; i<10; i++) {
     //printf(1,"%s\n", handle2[i]);
     }

     //head(handle2[])
  }
  exit();
 
}
