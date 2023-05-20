/***********************************************************
  > File Name: main.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年04月24日 星期一 11时13分07秒
  > Modified Time:2023年04月27日 星期四 11时06分30秒
 *******************************************************/

#define MAIN_C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PT100.h"

int main(int argc, char **argv)
{
  float Temp = 0;
  unsigned short Cnt = 0;
  if(argc < 2)     
  {
    printf("./PT ResistanceVal\n");
    return 1;
  }
  float R = strtof(argv[1],NULL);

  GetTempfromR(R, &Temp, &Cnt);

  printf("R = %f; Temp = %f; Cnt = %d\n", R, Temp, Cnt);

  return 0;
}

