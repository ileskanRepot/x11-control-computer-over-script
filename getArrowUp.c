
#include<stdio.h>
#include<stdlib.h>
#define clear() printf("\033[H\033[J")

int main(void){
  int c;
  /* use system call to make terminal send all keystrokes directly to stdin */
  system ("/bin/stty raw");
  while((c=getchar())!= 3) {
		printf("\033[H\033[J%d",c);
  }
  /* use system call to set terminal behaviour to more normal behaviour */
  system ("/bin/stty cooked");
	printf("\n");
  return 0;
}
