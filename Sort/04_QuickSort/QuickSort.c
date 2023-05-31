/***********************************************************
  > File Name: QuickSort.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年05月22日 星期一 16时13分13秒
  > Modified Time:2023年05月22日 星期一 16时13分13秒
 *******************************************************/

#define QUICKSORT_C

#include <stdio.h>
#include "QuickSort.h"

void quick_sort(DataType* arr,unsigned int len)
{
  int i,j;
  DataType base = arr[0];

  if(len < 2)
    return;

  i = 0;
  j = len-1;

  while(i < j)
  {
    while((i < j) && (arr[j] >= base)) j--;
    if(i < j) arr[i++] = arr[j];
    while((i < j) && (arr[i] <= base)) i++;
    if(i < j) arr[j--] = arr[i];
  }
  
  arr[i] = base;

  //deal with left and right
  quick_sort(&arr[0],i);
  quick_sort(&arr[i+1],len-i-1);
}
