/***********************************************************
  > File Name: InsertSort.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年05月22日 星期一 13时35分41秒
  > Modified Time:2023年05月22日 星期一 13时35分41秒
 *******************************************************/

#define INSERTSORT_C

#include <stdio.h>
#include "InsertSort.h"

void insert_sort(DataType* arr,unsigned int len)
{
  int i,j;
  DataType temp;

  if(len < 2)
    return;

  for(i = 1; i < len; i++)
  {
    temp = arr[i];
    j = i-1;
    while((j >= 0) && (temp < arr[j]))
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp; 
  }
/*
  for(i = 1; i < len; i++)
  {
    for(j = i-1; j >= 0; j--) 
    {
      if(arr[i] > arr[j])
      {
        m = j; 
        break;
      }
    }

    temp = arr[i];
    //adjust data arr
    for(j = i; j >= m+2; j--)
    {
      arr[j] = arr[j-1]; 
    }

    arr[m+1] = temp;
  }
*/
}
