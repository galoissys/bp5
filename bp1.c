/*********************************************************/
/*  bp1.c                                                */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  Back Propagation                                     */
/*                                                       */
/*********************************************************/
#include "bp1.h"
#include <math.h>

double f(double u);

/*  forward関数                                */
double forward(int r_cnt, Lrndata *lrndata, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o){
	
	double u = 0;
	int i=0, j=0;
	
	for(i=0; i < HD_NUM; ++i){
		for(j=0; j < WH_MAX; ++j){
			u += lrndata->ldata[r_cnt][j] * whdata->wh[i][j];
			// printf("forward():wh in j = %d\n", j);
		}
		// printf("forward():wh out j = %d\n", j);
		u -= whdata->wh[i][j];
		hdo->hi[i] = f(u);
		u=0;
	}
	
	for(i=0; i < HD_NUM; ++i){
		u += hdo->hi[i] * wodata->wo[i];
		// printf("forward():wo in i = %d\n", i);
	}
	// printf("forward():wo out i = %d\n", i);
	u -= wodata->wo[i];
	o->output = f(u);
	
	return o->output;
}


double f(double u){
	// if(u >= 0) return 1.0;
	// else return 0.0;
	
	// シグモイド関数
	return 1.0 / (1.0 + exp(-u));
}


/*  olearn関数                                */
void olearn(int r_cnt, Lrndata *lrndata, Wodata *wodata, Hd_output *hdo, Output *o){
	
	int i=0;
	double d;  /* 重み計算に利用 */
	
	d = (lrndata->ldata[r_cnt][WH_MAX] - o->output) * o->output * (1 - o->output);  /* 誤差計算 */
	for(i=0; i < HD_NUM; ++i){
		wodata->wo[i] += ALPHA * hdo->hi[i] * d;  /* 重みの学習 */
	}
	wodata->wo[i] += ALPHA * (-1.0) * d;     /* しきい値の学習 */
	
}


/*  hlearn関数                                */
void hlearn(int r_cnt, Lrndata *lrndata, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o){
	
	int i=0, j=0;
	double d;
	double dj;  /* 中間層の重み計算に利用 */
	
	for(j=0; j < HD_NUM; ++j){
		d = (lrndata->ldata[r_cnt][WH_MAX] - o->output) * o->output * (1 - o->output);
		dj = wodata->wo[j] * d * hdo->hi[j] * (1 - hdo->hi[j]);
		for(i=0; i < WH_MAX; ++i){
			whdata->wh[j][i] += ALPHA * lrndata->ldata[r_cnt][i] * dj;
		}
		whdata->wh[j][i] += ALPHA * (-1.0) * dj;
	}
	
}



