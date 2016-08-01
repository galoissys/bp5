/*********************************************************/
/*  bp1.h                                                */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  Back Propagation                                     */
/*                                                       */
/*********************************************************/
#ifndef _BP1_H_
#define _BP1_H_

#include "lrndata.h"
#include "wdata.h"

#define ALPHA 10   /* �w�K�W�� */

typedef struct{
	double hi[HD_NUM];
} Hd_output;

typedef struct{
	double output;
} Output;

/*  forward�֐�                                */
double forward(int r_cnt, Lrndata *lrndata, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);

/*  olearn�֐�                                */
void olearn(int r_cnt, Lrndata *lrndata, Wodata *wodata, Hd_output *hdo, Output *o);

/*  hlearn�֐�                                */
void hlearn(int r_cnt, Lrndata *lrndata, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);


#endif

