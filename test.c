#include <X11/Xlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int speed = 5;
	Window root_window;
	int root_x, root_y;
	unsigned int mask;

	Display *display = XOpenDisplay(NULL);

	if (display == 0)
	{
		printf("Could not open default display\n");
		return 1;
	}

	/*int c;
	system("/bin/stty raw");
	char tmp[3] = "   ";
	char esc = 0;
		while ((c = getchar()) != 3)
	{
		tmp[0] = tmp[1];
		tmp[1] = tmp[2];
		tmp[2] = c;
			if (esc == 0)
		{

			if (c == '\033')
			{
				esc = 1;
				continue;
			}
			printf(" C: %d",c);
	switch (c)
	{
	case 65:
		XWarpPointer(display, None, root_window, None, None, None, None, 0, -speed);
		printf("YLOS");
		break;
	case 66:
		XWarpPointer(display, None, root_window, None, None, None, None, 0, speed);
		printf("ALAS");
		break;
	case 67:
		XWarpPointer(display, None, root_window, None, None, None, None, speed, 0);
		printf("OIKEE");
		break;
	case 68:
		XWarpPointer(display, None, root_window, None, None, None, None, -speed, 0);
		printf("VASEN");
		break;
	default:
		printf("Näppäin");
	}
	}
		else
		{
			esc = 0;
		}*/

	//	XWarpPointer(display, None, root_window, None, None, None, None, 0, -speed);
	//	XFlush(display);

	int c;
	system("/bin/stty raw");
	//	char tmp[3] = "   ";
	char esc = 0;
	printf("TOKA\n");
	while ((c = getchar()) != 3)
	{
		if (esc == 2)
		{
			esc = 0;
			switch (c)
			{
			case 65:
				XWarpPointer(display, None, root_window, None, None, None, None, 0, -speed);
				XFlush(display);
				printf("YLOS");
				break;
			case 66:
				XWarpPointer(display, None, root_window, None, None, None, None, 0, speed);
				XFlush(display);
				printf("ALAS");
				break;
			case 67:
				XWarpPointer(display, None, root_window, None, None, None, None, speed, 0);
				XFlush(display);
				printf("OIKEE");
				break;
			case 68:
				XWarpPointer(display, None, root_window, None, None, None, None, -speed, 0);
				XFlush(display);
				printf("VASEN");
				break;
			}
		}
		else if (c == 27)
		{
			esc = 1;
		}
		else if (esc == 1 && c == 79)
		{
			esc = 2;
		}
		else
		{
			esc = 0;
			printf("KIRJAIN");
		}
		//	printf("C: %d\n", c);
		//	XWarpPointer(display, None, root_window, None, None, None, None, -speed, 0);
		//	XFlush(display);

		//	sleep(1);
	}
	XCloseDisplay(display);

	system("/bin/stty cooked");
	printf("\n");

	return 0;
}
