/***********************************************************
  > File Name: QuickSort.h
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年05月22日 星期一 16时13分35秒
  > Modified Time:2023年05月22日 星期一 16时13分35秒
 *******************************************************/

#ifndef __QUICKSORT_H
#define __QUICKSORT_H


#ifdef   QUICKSORT_C
#define  Ex_QuickSort  extern
#else
#define  Ex_QuickSort
#endif

#define  DataType int

Ex_QuickSort void quick_sort(DataType* arr,unsigned int len);

#endif
