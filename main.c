#include<stdio.h>
#include <X11/Xlib.h>
#include <stdlib.h>
#define clear() printf("\033[H\033[J")

int main(void){
	Display *display;
	Window root;
	unsigned int x, y;

	display = XOpenDisplay(NULL);

	if(display == 0) {
			printf("Could not open default display\n");
			return 1;
	}

	int c;
	system ("/bin/stty raw");
	while((c=getchar())!= 3) {
		printf("\033[H\033[J%d",c);
	}
	system ("/bin/stty cooked");
	printf("\n");
	return 0;
}
