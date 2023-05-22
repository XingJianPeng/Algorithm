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
  int m;
  DataType base = arr[0];
  DataType temp;

  if(len < 2)
    return;

  i = 0;
  j = len-1;

  while(i < j)
  {
    if(arr[j] < base)
    {//find a left element
      while(i < j) 
      {
        if(arr[i] > base)
        {
          temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp; 

          break;
        }
        i++;
      }
    }
    j--;
  }
  
  m = i;
  arr[0] = arr[m];
  arr[m] = base;

  //deal with left and right
  quick_sort(&arr[0],m);
  quick_sort(&arr[m+1],len-m-1);
}
