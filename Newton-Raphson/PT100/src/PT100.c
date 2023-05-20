/***********************************************************
  > File Name: PT100.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年04月24日 星期一 09时44分20秒
  > Modified Time:2023年04月25日 星期二 12时35分55秒
 *******************************************************/

#define PT100_C

#include "PT100.h"
#include <math.h>


unsigned char GetRfromTemp(float temp, float* resist)
{
  unsigned char ret = 0;

  if(NULL == resist)
  {
    return 1;
  }
  if(temp >= -200 && temp < 0)
  {
    *resist = R0*(1 + A*temp + B*temp*temp + C*(temp-100)*temp*temp*temp);    
    ret = 0;
  }
  else if(temp >= 0 && temp <= 850)
  {
    *resist = R0*(1 + A*temp + B*temp*temp);
    ret = 0;
  }
  else
  {
    *resist = 0;
    ret = 1;
  }

  return ret;
}

#if (PT100_Sw == Newton)
unsigned char GetTempfromR(float resist, float *temp, unsigned short* pCalNum)
{
  unsigned char ret = 0;
  float fT, fT0;
  unsigned int i = 0;

  if(NULL == temp)
    return 1;

  /*0.判断阻值范围是否超限,并做区分*/
  if(resist <= DnLimitR)
  {//<DnLimit℃
    *temp = DnLimit; 
    return 0;
  }
  else if(resist >= UpLimitR)
  {//>UpLimit℃
    *temp = UpLimit;
    return 0;
  }

  /*1.先用线性公式得到一个粗略的温度:原公式丢掉一次项以上的项,即Rt = R0*(1+A*t)*/
  fT0 = (resist/R0 -1)/A;

  if(resist >= DnLimitR && resist < R0)  /*-200℃~0℃*/
  {
    for(i = 0; i < CalNum; i++)
    {
      fT = fT0 + (resist - R0*(1 + A*fT0 + B*fT0*fT0 + C*fT0*fT0*fT0*fT0 - C*100*fT0*fT0*fT0))/\
           (R0*(A + 2*B*fT0 -300*C*fT0*fT0 + 4*C*fT0*fT0*fT0));
      if(fabs(fT-fT0) < Accuracy) 
        break;
      else
        fT0 = fT;
    }
    *temp = fT;
    ret = 0;
  }
  else if(resist >= R0 && resist <= UpLimitR)  /*0℃~850℃*/
  {
    for(i = 0; i < CalNum; i++)
    {
      fT = fT0 + (resist - R0*(1 + A*fT0 + B*fT0*fT0))/(R0*(A + 2*B*fT0));
      if(fabs(fT-fT0) < Accuracy)
        break;
      else
        fT0 = fT;
    }
    *temp = fT;
    ret = 0;
  }
  *pCalNum = i;

  return ret;
}
#endif

#if(PT100_Sw == Fiting)
/*温度判定范围-200℃~650℃ ,excel数据做二项式拟合, 拟合数据excel表见FitTable.xlsx
 * 求出拟合方程如下:
 * T = 0.0012*R^2 + 2.3024*R - 242.89*/
#define F_a (0.0012)
#define F_b (2.3024)
#define F_c (-242.89)

unsigned char GetTempfromR(float resist, float *temp, unsigned short* pCalNum)
{
  if(NULL == temp) 
    return 1;

   /*0.判断阻值范围是否超限,并做区分*/
  if(resist <= DnLimitR)
  {//<DnLimit℃
    *temp = DnLimit; 
    return 0;
  }
  else if(resist >= UpLimitR)
  {//>UpLimit℃
    *temp = UpLimit;
    return 0;
  }
 
  *temp = F_a*resist*resist + F_b*resist +F_c;
  *pCalNum = 0;

  return 0;
}

#endif

#if(PT100_Sw == SearchTable)
float RTD_TAB_PT100[211] =   // 表格是以5度为一步，即-200, -195, - 190.....
{
18.52,20.68,22.83,24.97,27.10,29.22,31.34,33.44,35.54,37.64,                  // -200 ~ -155   10

39.72,41.80,43.88,45.94,48.00,50.06,52.11,54.15,56.19,58.23,                  // -150 ~ -105

60.26,62.28,64.30,66.31,68.33,70.33,72.33,74.33,76.33,78.32,                  // -100 ~ -55

80.31,82.29,84.27,86.25,88.22,90.19,92.16,94.12,96.09,98.04,                  // -50 ~ -5

100.00,101.95,103.90,105.85,107.79,109.73,111.67,113.61,115.54,117.47,        // 0   ~ 45

119.40,121.32,123.24,125.16,127.08,128.99,130.90,132.80,134.71,136.61,        // 50  ~ 95

138.51,140.40,142.29,144.18,146.07,147.95,149.83,151.71,153.58,155.46,        // 100 ~ 145

157.33,159.19,161.05,162.91,164.77,166.63,168.48,170.33,172.17,174.02,        // 150 ~ 195

175.86,177.69,179.53,181.36,183.19,185.01,186.84,188.66,190.47,192.29,        // 200 ~ 245

194.10,195.91,197.71,199.51,201.31,203.11,204.90,206.70,208.48,210.27,        // 250 ~ 295

212.05,213.83,215.61,217.38,219.15,220.92,222.68,224.45,226.21,227.96,        // 300 ~ 345

229.72,231.47,233.21,234.96,236.70,238.44,240.18,241.91,243.64,245.37,        // 350 ~ 395

247.09,248.81,250.53,252.25,253.96,255.67,257.38,259.08,260.78,262.48,        // 400 ~ 445

264.18,265.87,267.56,269.25,270.93,272.61,274.29,275.97,277.64,279.31,        // 450 ~ 495

280.98,282.64,284.30,285.96,287.62,289.27,290.92,292.56,294.21,295.85,        // 500 ~ 545

297.49,299.12,300.75,302.38,304.01,305.63,307.25,308.87,310.49,312.10,        // 550 ~ 595

313.71,315.31,316.92,318.52,320.12,321.71,323.30,324.89,326.48,328.06,        // 600 ~ 645

329.64,331.22,332.79,334.36,335.93,337.50,339.06,340.62,342.18,343.73,        // 650 ~ 695

345.28,346.83,348.38,349.92,351.46,353.00,354.53,356.06,357.59,359.12,        // 700 ~ 745

360.64,362.16,363.67,365.19,366.70,368.21,369.71,371.21,372.71,374.21,        // 750 ~ 795

375.70,377.19,378.68,380.17,381.65,383.13,384.60,386.08,387.55,389.02,        // 800 ~ 845

390.48        // 850
};

unsigned char GetTempfromR(float resist, float *temp, unsigned short* pCalNum)
{
  unsigned int i, Start, End = 0;
  volatile unsigned int Cnt = 0;

  if(resist <= DnLimitR)
  {
    *temp = DnLimit;
    *pCalNum = 0;
    return 1;
  } 
  if(resist >= UpLimitR)
  {
    *temp = UpLimit;
    *pCalNum = 0;
    return 1;
  } 

  Start = 0;
  End   = 210;

  for(i = 105; End - Start != 1;)
  {
    Cnt++;
    if(resist < RTD_TAB_PT100[i])  
    {
      End = i;
      i = (Start+End)/2;
    }
    else if(resist > RTD_TAB_PT100[i])
    {
      Start = i;
      i = (Start+End)/2;
    }
    else
    {//resist = RTD_TAB_PT100[i]
      *temp = ((float)i*5.0 - 200.0); 
      *pCalNum = Cnt;
      return 0;
    }
  }

  *pCalNum = Cnt;
  *temp = ((float)Start*5.0-200.0) + (resist-RTD_TAB_PT100[Start])/(RTD_TAB_PT100[End]-RTD_TAB_PT100[Start])*5.0;

  return 0;
}

#endif

