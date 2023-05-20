/***********************************************************
  > File Name: PT100.h
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年04月24日 星期一 09时44分27秒
  > Modified Time:2023年04月25日 星期二 15时58分22秒
 *******************************************************/

#ifndef __PT100_H
#define __PT100_H


#ifdef   PT100_C
#define  Ex_PT100  extern
#else
#define  Ex_PT100
#endif

#include <stdio.h>

#define  SearchTable  (1) //查表法
#define  Fiting       (2) //excel数据拟合
#define  Newton       (3) //牛顿-拉弗森迭代逼近

#define  PT100_Sw   Newton 

#define CalNum    (50)     //牛顿法最大迭代次数
#define Accuracy  (0.01)  //温度求解精度
#define UpLimit   (850)
#define UpLimitR  (390.481)
#define DnLimit   (-200)
#define DnLimitR  (18.52)

#define A  (3.9083e-3)
#define B  (-5.775e-7)
#define C  (-4.183e-12)
#define R0 (100)

/*
 * -200℃~0℃:
 *  Rt = R0*[1 + A*t + B*t^2 +C*(t-100)*t^3]
 *  Rt' = R0*(A + 2*B*t -300*C*t^2 + 4*C*t^3)
 *  0℃~850℃:
 *  Rt = R0*(1 + A*t + B*t^2)
 *  Rt' = R0*(A + 2*B*t)
*/


/**
 * @brief 从温度获取阻值
 * @param[in]  temp		温度值
 * @param[out] resist	阻值
 * @retval  是否成功 0-->successful
 */
Ex_PT100 unsigned char GetRfromTemp(float temp, float* resist);



/**
 * @brief 从阻值获取温度
 * @param[in]  resist	阻值
 * @param[out] temp		温度值
 * @param[out] pCalNum	牛顿法迭代次数
 * @retval  是否成功 0-->successful
 */
Ex_PT100 unsigned char GetTempfromR(float resist, float *temp, unsigned short *pCalNum);


#endif
