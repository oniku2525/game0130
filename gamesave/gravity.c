#include <stdio.h>
#include <ncurses.h>

void gravity(int *y, int *h, int jumpflag)
{
	if ((*y)+6 != (*h)/3*2) {
		if (jumpflag == 0) {
			(*y)++;
		}
	}
}

