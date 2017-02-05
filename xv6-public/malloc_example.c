#include "user.h"
#include "stat.h"
#include "types.h"
int main(void) 
{
int i;
char *a;
a = (char *) malloc(11);
//a = malloc(1);
//b = "HelloWorld";
char *start; 
start = a;
printf(1,"Start Address is : %d\n",start);
char b[11] = "HelloWorld!"; 
for(i = 0; b[i] != '\0'; i++)
    {
        *a = b[i];
//        printf(1,"B copy:%c\n",b[i]);
//        printf(1,"Copied to A:%c",*a);
        printf(1,"Next Address is : %d\n",a);
        a++;
    }

    *a  = '\0';
for(a = start; *a != '\0'; a++) {
   printf(1,"The Data written is : %c\n",*a);
}
a = start;
printf(1,"The Data is : %s\n",a);
free(a);
printf(1,"The Data Fetch after Memory Freeing is : %s\n",*a);
printf(1,"The Address after Memory Freeing is : %d\n",a);
exit();
}
