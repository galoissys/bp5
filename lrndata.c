/*********************************************************/
/*  lrndata.c                                            */
/*                                                       */
/*********************************************************/
#include "lrndata.h"

void initldata(Lrndata *lrndata){
	
	int i=0, j=0;
	
	memset(lrndata, 0, sizeof(Lrndata));
	
	for(i=0; i < R_MAX; ++i){
		for(j=0; j < C_MAX + 1; ++j){
			lrndata->ldata[i][j] = 0.0;
		}
	}
	
	
}


void setldata(Lrndata *lrndata){
	
	int i=0, j=0;
	
	for(i=0; i < R_MAX; ++i){
		for(j=0; j < C_MAX + 1; ++j){
			scanf("%lf", &lrndata->ldata[i][j]);
		}
	}
	
}


void getldata(Lrndata *lrndata){
	
	int i=0, j=0;
	
	printf("*** Learnning Data Set ***\n");
	
	for(i=0; i < R_MAX; ++i){
		printf("%d ", i+1);
		for(j=0; j < C_MAX + 1; ++j){
			printf("%lf\t", lrndata->ldata[i][j]);
		}
		printf("\n");
	}
	
}



