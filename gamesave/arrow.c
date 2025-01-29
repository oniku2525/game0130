#include <stdio.h>
#include <ncurses.h>
#include "arrow.h"
#include "attack.h"

//矢を生成する関数
void arrow_gene(struct g_arrow *Arrow, int x, int y)
{
	for (int i = 0; i<5; i++) {
		//もしi番目がゼロだったら
		//矢iを生成する
		//１が代入されていたら使用中
		if (Arrow[i].arrow_flag == 0) {
			Arrow[i].arrow_flag = 1; //使用中です
			Arrow[i].arrow_x = x+6; //プレイヤーの正面
			Arrow[i].arrow_y = y;
			//矢の初期位置
			attack(Arrow[i].arrow_x, Arrow[i].arrow_y);
			break;
		}
	}
}

//矢を動かす関数
void arrow_move(struct g_arrow *Arrow, int w) //配列、ｙ、幅
{
	for (int i = 0; i < 5; i++) {
		//配列のそれぞれの要素が、もし
		//使われていたら、ｘ座標をプラスする
		if (Arrow[i].arrow_flag == 1) {
			//進める
			Arrow[i].arrow_x++;
			//矢を描く
			attack(Arrow[i].arrow_x, Arrow[i].arrow_y);
		}
		if (Arrow[i].arrow_x > w) {
			//もし画面外に出たらフラグを下げる。
			Arrow[i].arrow_flag = 0;
		}
	}
}


