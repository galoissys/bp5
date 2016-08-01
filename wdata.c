/*********************************************************/
/*  wdata.c                                              */
/*                                                       */
/*                                                       */
/*********************************************************/
#include "wdata.h"

/*  中間層ニューロン 関数                                */
void init_wh(Whdata *whdata){
	
	int i, j;
	
	srand((unsigned)time(NULL));    /* time関数を用いた乱数初期化の定番式 */

	for(i=0; i < HD_NUM; ++i){
		for(j=0; j < WH_MAX + 1; ++j){
			whdata->wh[i][j] = drnd();
		}
	}
	
}


void get_wh(Whdata *whdata){
	
	int i=0, j=0;
	
	printf("*** Weight Data of Hidden Layer ***\n");
	
	for(i=0; i < HD_NUM; ++i){
		for(j=0; j < WH_MAX + 1; ++j){
			printf("wh[%d][%d] = %lf\n", i, j, whdata->wh[i][j]);
		}
	}
	
}


/*  出力層ニューロン 関数                                */
void init_wo(Wodata *wodata){
	
	int i;
	
	srand((unsigned)time(NULL));    /* time関数を用いた乱数初期化の定番式 */
	
	for(i=0; i < HD_NUM +1; ++i){
		wodata->wo[i] = drnd();
	}
	
}


void get_wo(Wodata *wodata){
	
	int i=0;
	
	printf("*** Weight Data of Output Layer ***\n");
	
	for(i=0; i < HD_NUM + 1; ++i){
		printf("wo[%d] = %lf\n", i, wodata->wo[i]);
	}
	
}


double drnd(void){
	
	double rndno;
	
	while((rndno = (double)rand() / RAND_MAX) == 1.0);
	rndno = rndno * 2 - 1; /* -1から1の間の乱数を生成 */
	return rndno;
}



