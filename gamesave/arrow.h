#ifndef ARROW_H
#define ARROW_H
//矢の構造体
struct g_arrow {
	int	arrow_x;
	int	arrow_y;
	int	arrow_flag;
};

//プロトタイプ
//矢を生成する関数
void arrow_gene(struct g_arrow *Arrow, int x, int y);

//矢を動かす関数
void arrow_move(struct g_arrow *Arrow, int w);

#endif
