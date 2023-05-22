/***********************************************************
  > File Name: SelectSort.h
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年05月22日 星期一 12时46分05秒
  > Modified Time:2023年05月22日 星期一 12时46分05秒
 *******************************************************/

#ifndef __SELECTSORT_H
#define __SELECTSORT_H


#ifdef   SELECTSORT_C
#define  Ex_SelectSort  extern
#else
#define  Ex_SelectSort
#endif

#define  DataType int

Ex_SelectSort void select_sort(DataType* arr,unsigned int len);

#endif
