#include <stdio.h>
#include <ncurses.h>
#include "cat.c"
#include "catback.c"


int mymove(int *x, int *y, int flag, int *jumpflag, int *h, char enter)
{
	if (enter == 'd') {
		(*x)++;
		cat(*x, *y);
		flag = 0;
	}

	if (enter == 'a') {
		(*x)--;
		catback(*x, *y);
		flag = 1;
	}

	if (enter != 'a' && enter !='b') {

		if (flag == 0) cat(*x, *y);
		if (flag == 1) catback(*x, *y);
		else cat(*x, *y);
	}

	if (enter == ' ') {
		if ((*y)+6 == (*h)/3*2) {
			*jumpflag = 1;
		}
	}

	return (flag);
}

