/*********************************************************/
/*  wdata.h                                              */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  �j���[���� �d�݂Ƃ������l�f�[�^                      */
/*                                                       */
/*********************************************************/
#ifndef _WDATA_H_
#define _WDATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*  ���ԑw�j���[���� �d�݂Ƃ������l �f�[�^�\��           */
#define HD_NUM 3
#define WH_MAX 3

typedef struct{
	double wh[HD_NUM][WH_MAX + 1];
} Whdata;

/*  ���ԑw�j���[���� �֐�                                */
void init_wh(Whdata *whdata);
void get_wh(Whdata *whdata);


/*  �o�͑w�j���[���� �d�݂Ƃ������l �f�[�^�\��           */

typedef struct{
	double wo[HD_NUM + 1];
} Wodata;

/*  �o�͑w�j���[���� �֐�                                */
void init_wo(Wodata *wodata);
void get_wo(Wodata *wodata);


/* �������� */
double drnd(void);


#endif

