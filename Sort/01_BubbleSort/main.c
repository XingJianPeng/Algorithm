/***********************************************************
  > File Name: main.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年05月21日 星期日 00时57分54秒
  > Modified Time:2023年05月21日 星期日 00时57分54秒
 *******************************************************/

#define MAIN_C

#include <stdio.h>
#include "BubbleSort.h"

int arr[5] = {1,3,2,7,6};
int main(int argc, char **argv)
{
  int i = 0;

  bubble_sort(arr,5);
  for(i = 0; i < 5; i++)
    printf("%d ",arr[i]);
  printf("\n");
  return 0;
}

