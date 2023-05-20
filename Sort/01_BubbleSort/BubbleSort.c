/***********************************************************
  > File Name: BubbleSort.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年04月29日 星期六 08时22分02秒
  > Modified Time:2023年04月29日 星期六 08时22分02秒
 *******************************************************/

#define BUBBLESORT_C

#include <stdio.h>
#include "BubbleSort.h"

void bubble_sort(DataType* arr,unsigned int len)
{
  unsigned int i,j;
  DataType temp;

  if(len < 2)
    return;

  for(i = 0; i < len-1; i++)
  {
    for(j = 0; j < len-1-i; j++)
    {
      if(arr[j] > arr[j+1]) 
      {
        temp      = arr[j];
        arr[j]    = arr[j+1];
        arr[j+1]  = temp;
      }
    }
  }
}
