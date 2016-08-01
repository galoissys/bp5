/*********************************************************/
/*  lrnproc.c                                            */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  �w�K�@                                               */
/*                                                       */
/*********************************************************/
#include "lrnproc.h"

int lrnproc(){
	
	// �\���̂̃������m��
	
	// �w�K�f�[�^�\����
	Lrndata *plrndata;
	plrndata = (Lrndata *)malloc(sizeof(Lrndata));
	//initldata(plrndata);
	
	// �j���[�����̒��ԑw�y�яo�͑w�̏d�ݍ\����
	Whdata *pwhdata;
	Wodata *pwodata;
	pwhdata = (Whdata *)malloc(sizeof(Whdata));
	pwodata = (Wodata *)malloc(sizeof(Wodata));
	
	// �o�͍\����
	Hd_output *phdo;
	Output *po;
	phdo = (Hd_output *)malloc(sizeof(Hd_output));
	po = (Output *)malloc(sizeof(Output));
	
	
	// �w�K�f�[�^���Z�b�g
	setldata(plrndata);
	// debug_info
	getldata(plrndata);
	
	
	// �d�݂Ƃ������l�̏�����
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
	
	/* �w�K */
	while(err > LIMIT){
		err = 0.0;
		for(j=0; j < R_MAX; ++j){
			// �������̌v�Z 
			o = forward(j, plrndata, pwhdata, pwodata, phdo, po);
			
			// �o�͑w�d�ݒ���
			olearn(j, plrndata, pwodata, phdo, po);
			
			// ���ԑw�d�ݒ���
			hlearn(j, plrndata, pwhdata, pwodata, phdo, po);
			
			// �덷�̐ώZ
			/* ldata[j][C_MAX]�͋��t�f�[�^�B��Z���邱�ƂŒl���{�Ƃ��ώZ����B */
			err += (o - plrndata->ldata[j][C_MAX]) * (o - plrndata->ldata[j][C_MAX]);
		}
		++count;
		// fprintf(stderr, "%d\t%lf\n", count, err);
		printf("%d\t%lf\n", count, err);
	} /* �w�K�I�� */
	
	// �j���[�������ԑw�y�яo�͑w�̏d�݂Ƃ������l�̍ŏI���ʊm�F
	get_wh(pwhdata);
	get_wo(pwodata);
	
	for(i=0; i < R_MAX; ++i){
		printf("%d ", i);
		for(j=0; j < C_MAX; ++j){
			// �w�K�f�[�^�o��
			printf("%lf ", plrndata->ldata[i][j]);
		}
		o = forward(i, plrndata, pwhdata, pwodata, phdo, po);
		// �w�K��̌��ʏo��
		printf("%lf\n", o);
	}
	
	// ���������
	free(plrndata);
	free(pwhdata);
	free(pwodata);
	free(phdo);
	free(po);
	
	return 0;
}


