/*********************************************************/
/*  lrndata.h                                            */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  学習データセット                                     */
/*                                                       */
/*********************************************************/
#ifndef _LRNDATA_H_
#define _LRNDATA_H_

#include <stdio.h>
#include <string.h>

/*  学習データセット データ構造                          */
#define R_MAX 8
#define C_MAX 3

typedef struct{
	double ldata[R_MAX][C_MAX + 1];  // C_MAX + teacher_data(1)
} Lrndata;

/*  学習データセット 関数                                */
void initldata(Lrndata *lrndata);
void setldata(Lrndata *lrndata);
void getldata(Lrndata *lrndata);


#endif

