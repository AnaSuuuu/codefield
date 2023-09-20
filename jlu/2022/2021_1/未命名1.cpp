#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
 int x,y,z;
 char ch;
 while(scanf("%d%c%d=",&x,&ch,&y)){
  if((y==0&ch=='%')||(y==0&ch=='/'))
  {
   printf("Runtime Error");
  }
  else
  {
   printf("%d%c%d=%d",&x,&ch,&y,&z);
  } 
 }
 return 0;
}
