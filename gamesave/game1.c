#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "back.c"
#include "mymove.c"
#include "gravity.c"
#include "enemy.c"
#include "e_attack.c"
#include "display.c"
#include "cloud1.c"
#include "cloud2.c"
#include "judgment.c"
#include "arrow.h"
#include "attack.h"
#include <unistd.h>


int main(void)
{
	struct g_arrow Arrow[5];
	for (int i = 0; i < 5; i++) {
		Arrow[i].arrow_flag = 0;
	}

    int     x, y, w, h, ex, ey, ax, ay;
    int     flag = 0; //"最後に動いた向き"をキープする
    int     count = 0;
    int		jumpflag = 0; //ジャンプを続行させるかどうかのフラグ
    char    enter;

    int		judge = 0;
    int		dis_num = 50;
    int		enex;

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    timeout(0);
    start_color();	

    getmaxyx(stdscr, h, w);
    x = w/10;
    y = h/4;

    ex = w-10;
    ey = y/3;
    int e_flag = 1;

    while (1)
    {
        erase();
        back(w, h);
	cloud1(10, 3);
	cloud2(20, 4);
	
	display(w/3*2, h/2+10, dis_num/10, dis_num%10);
	
	enemy(ex, ey);
	if (ey+7 != h/3*2) ey++;

//	judge = judgment(ex, ey, ax, ay); //当たり判定
	if (judge == 1) {
		dis_num--;		//あたったらdisplay変更
		judge = 0;	//初期値に戻す
	}

	gravity(&y, &h, jumpflag);

	arrow_move(Arrow, w);

	if (enex >= 0) {	//敵の攻撃
		enex--;
		e_attack(enex, ey);
	}

	flag = mymove(&x, &y, flag, &jumpflag, &h, enter);

	if (enter == 'j') {
		arrow_gene(Arrow, x, y);
	}
        refresh();

        enter = getch(); //入力
	if (jumpflag == 1) {	//ジャンプフラグが立っていたらジャンプ続行
	       	y--;	//ジャンプ
                count++;
	}
        if (count >= 10) { //カウントが１０以上だったら
		count = 0;
		jumpflag = 0;
	}
	if (e_flag == 1) {
	//敵の攻撃
	enex = ex;
	e_attack(enex, ey);
	e_flag = 0;
	}

        if (enter == 'q') break;
        usleep(40000);

    }

    printf("%d\n", h);
    endwin();
    return (0);
}

//メモ
/*
地面についてるときだけジャンプ
加速度をつけたい

ミス：重力がy--、ジャンプがy++で、
スペースを押してもジャンプしなかった理由が
相殺されていたため。
,
ヘッダファイルとファイルを同時にincludeしていた

リプレイ機能をつける。

どこに矢印を投げると、勝ちやすいか
ニューラルネットワークを使って設計する。
'*/
