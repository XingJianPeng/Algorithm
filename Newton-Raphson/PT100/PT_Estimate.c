/***********************************************************
  > File Name: PT_Estimate.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年04月25日 星期二 09时47分28秒
  > Modified Time:2023年04月27日 星期四 11时07分08秒
 *******************************************************/

#define PT_ESTIMATE_C

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "PT100.h"

int main(int argc, char **argv)
{
  FILE *fp;
  int temp = 0;
  float R = 0;
  float T = 0;
  int Num = 0;
  char buf[200] = {0};

  fp = fopen("Result.txt", "w+");
  if(NULL == fp)
  {
    printf("foepn err\n");
  }


  memset((void*)buf,0,200);
  sprintf(buf, "Temp:    R:           Cal_T:          Usedtime:         Num:\n");
  fwrite(buf, strlen(buf), 1, fp);
  for(temp = -200; temp <= 850; temp++)
  {
    GetRfromTemp(temp, &R);

    clock_t start,end;
    start = clock();
    GetTempfromR(R, &T,(unsigned short*)&Num);
    end = clock();
    double seconds = (double)(end - start)/CLOCKS_PER_SEC;

    memset((void*)buf,0,200);
    sprintf(buf, "%d℃    %f      %f    %lfs     %d\n",temp, R, T, seconds, Num);
    fwrite(buf, strlen(buf), 1, fp);
  }

  fclose(fp);
  return 0;
}

