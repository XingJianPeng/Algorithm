/***********************************************************
  > File Name: main.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年05月21日 星期日 00时57分54秒
  > Modified Time:2023年05月21日 星期日 00时57分54秒
 *******************************************************/

#define MAIN_C

#include <stdio.h>
#include "01_BubbleSort/BubbleSort.h"
#include "02_SelectSort/SelectSort.h"
#include "03_InsertSort/InsertSort.h"
#include "04_QuickSort/QuickSort.h"

int arr[] = {1,3,2,7,6,4,9,0,-1,45,21,16,4,8};
int main(int argc, char **argv)
{
  int i = 0;
  int len = sizeof(arr)/sizeof(arr[0]);

  //bubble_sort(arr,5);
  //select_sort(arr,5);
  //insert_sort(arr,5);
  printf("len = %d\n",len);
  quick_sort(arr,len);
  for(i = 0; i < len; i++)
    printf("%d ",arr[i]);
  printf("\n");
  return 0;
}

