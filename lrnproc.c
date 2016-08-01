/*********************************************************/
/*  lrnproc.c                                            */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  学習機                                               */
/*                                                       */
/*********************************************************/
#include "lrnproc.h"

int lrnproc(){
	
	// 構造体のメモリ確保
	
	// 学習データ構造体
	Lrndata *plrndata;
	plrndata = (Lrndata *)malloc(sizeof(Lrndata));
	//initldata(plrndata);
	
	// ニューロンの中間層及び出力層の重み構造体
	Whdata *pwhdata;
	Wodata *pwodata;
	pwhdata = (Whdata *)malloc(sizeof(Whdata));
	pwodata = (Wodata *)malloc(sizeof(Wodata));
	
	// 出力構造体
	Hd_output *phdo;
	Output *po;
	phdo = (Hd_output *)malloc(sizeof(Hd_output));
	po = (Output *)malloc(sizeof(Output));
	
	
	// 学習データをセット
	setldata(plrndata);
	// debug_info
	getldata(plrndata);
	
	
	// 重みとしきい値の初期化
	init_wh(pwhdata);
	init_wo(pwodata);
	// debug_info
	get_wh(pwhdata);
	get_wo(pwodata);
	
	sleep(5);
	
	
	double err = 100;
	int count = 0;
	
	int i=0, j=0;
	double o;
	
	/* 学習 */
	while(err > LIMIT){
		err = 0.0;
		for(j=0; j < R_MAX; ++j){
			// 順方向の計算 
			o = forward(j, plrndata, pwhdata, pwodata, phdo, po);
			
			// 出力層重み調整
			olearn(j, plrndata, pwodata, phdo, po);
			
			// 中間層重み調整
			hlearn(j, plrndata, pwhdata, pwodata, phdo, po);
			
			// 誤差の積算
			/* ldata[j][C_MAX]は教師データ。乗算することで値を＋とし積算する。 */
			err += (o - plrndata->ldata[j][C_MAX]) * (o - plrndata->ldata[j][C_MAX]);
		}
		++count;
		// fprintf(stderr, "%d\t%lf\n", count, err);
		printf("%d\t%lf\n", count, err);
	} /* 学習終了 */
	
	// ニューロン中間層及び出力層の重みとしきい値の最終結果確認
	get_wh(pwhdata);
	get_wo(pwodata);
	
	for(i=0; i < R_MAX; ++i){
		printf("%d ", i);
		for(j=0; j < C_MAX; ++j){
			// 学習データ出力
			printf("%lf ", plrndata->ldata[i][j]);
		}
		o = forward(i, plrndata, pwhdata, pwodata, phdo, po);
		// 学習後の結果出力
		printf("%lf\n", o);
	}
	
	// メモリ解放
	free(plrndata);
	free(pwhdata);
	free(pwodata);
	free(phdo);
	free(po);
	
	return 0;
}


