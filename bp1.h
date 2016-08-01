/*********************************************************/
/*  bp1.h                                                */
/*                                                       */
/*  ŠK‘wŒ^ƒjƒ…[ƒƒlƒbƒgƒvƒƒOƒ‰ƒ€                       */
/*  Back Propagation                                     */
/*                                                       */
/*********************************************************/
#ifndef _BP1_H_
#define _BP1_H_

#include "lrndata.h"
#include "wdata.h"

#define ALPHA 10   /* ŠwKŒW” */

typedef struct{
	double hi[HD_NUM];
} Hd_output;

typedef struct{
	double output;
} Output;

/*  forwardŠÖ”                                */
double forward(int r_cnt, Lrndata *lrndata, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);

/*  olearnŠÖ”                                */
void olearn(int r_cnt, Lrndata *lrndata, Wodata *wodata, Hd_output *hdo, Output *o);

/*  hlearnŠÖ”                                */
void hlearn(int r_cnt, Lrndata *lrndata, Whdata *whdata, Wodata *wodata, Hd_output *hdo, Output *o);


#endif

