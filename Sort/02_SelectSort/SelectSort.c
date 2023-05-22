/***********************************************************
  > File Name: SelectSort.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年05月22日 星期一 12时45分58秒
  > Modified Time:2023年05月22日 星期一 12时45分58秒
 *******************************************************/

#define SELECTSORT_C

#include <stdio.h>

#include "SelectSort.h"

void select_sort(DataType* arr,unsigned int len)
{
  unsigned int i,j;
  unsigned int m;
  DataType temp;

  if(len < 2)
    return;

  for(i = 0; i < len-1; i++)
  {
    m = i;//未排序序列头
    temp = arr[m];

    for(j = i+1; j < len; j++)
    {
      if(arr[j] < temp) 
      {
        m = j;
        temp = arr[m];
      }
    }

    arr[m] = arr[i];
    arr[i] = temp;
  }
  return;
}

