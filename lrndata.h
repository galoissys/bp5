/*********************************************************/
/*  lrndata.h                                            */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  �w�K�f�[�^�Z�b�g                                     */
/*                                                       */
/*********************************************************/
#ifndef _LRNDATA_H_
#define _LRNDATA_H_

#include <stdio.h>
#include <string.h>

/*  �w�K�f�[�^�Z�b�g �f�[�^�\��                          */
#define R_MAX 8
#define C_MAX 3

typedef struct{
	double ldata[R_MAX][C_MAX + 1];  // C_MAX + teacher_data(1)
} Lrndata;

/*  �w�K�f�[�^�Z�b�g �֐�                                */
void initldata(Lrndata *lrndata);
void setldata(Lrndata *lrndata);
void getldata(Lrndata *lrndata);


#endif

