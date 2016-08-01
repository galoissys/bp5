/*********************************************************/
/*  wdata.h                                              */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  ニューロン 重みとしきい値データ                      */
/*                                                       */
/*********************************************************/
#ifndef _WDATA_H_
#define _WDATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*  中間層ニューロン 重みとしきい値 データ構造           */
#define HD_NUM 3
#define WH_MAX 3

typedef struct{
	double wh[HD_NUM][WH_MAX + 1];
} Whdata;

/*  中間層ニューロン 関数                                */
void init_wh(Whdata *whdata);
void get_wh(Whdata *whdata);


/*  出力層ニューロン 重みとしきい値 データ構造           */

typedef struct{
	double wo[HD_NUM + 1];
} Wodata;

/*  出力層ニューロン 関数                                */
void init_wo(Wodata *wodata);
void get_wo(Wodata *wodata);


/* 乱数生成 */
double drnd(void);


#endif

