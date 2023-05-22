/***********************************************************
  > File Name: InsertSort.h
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年05月22日 星期一 13时35分45秒
  > Modified Time:2023年05月22日 星期一 13时35分45秒
 *******************************************************/

#ifndef __INSERTSORT_H
#define __INSERTSORT_H


#ifdef   INSERTSORT_C
#define  Ex_InsertSort  extern
#else
#define  Ex_InsertSort
#endif

#define  DataType int

Ex_InsertSort void insert_sort(DataType* arr,unsigned int len);

#endif
