/***********************************************************
  > File Name: test.c
  > Author: xjp
  > Mail: -----------------
  > Created  Time:2023年05月31日 星期三 11时29分57秒
  > Modified Time:2023年05月31日 星期三 11时29分57秒
 *******************************************************/

#define TEST_C

#include <stdio.h>
#include <stdint.h>
#include "CircleBufContol.h"

uint32_t arr[5];
tCircleBufCtrl mCtrl;

int main(int argc, char **argv)
{
  int i = 0;
  int cnt = 0;
  ResetCircle_CBuf(&mCtrl, 5);    
 
  /*
  arr[GetInPosi_CBuf(&mCtrl)] = cnt++;
    
  for(i = 0; i < 4; i++)
  {
    if(IsFull_CBuf(&mCtrl))
      GetOutPosi_CBuf(&mCtrl);
    arr[GetInPosi_CBuf(&mCtrl)] = cnt++;
    if(IsFull_CBuf(&mCtrl))
      GetOutPosi_CBuf(&mCtrl);
    arr[GetInPosi_CBuf(&mCtrl)] = cnt++;      
    if(IsFull_CBuf(&mCtrl))
      GetOutPosi_CBuf(&mCtrl);
    arr[GetInPosi_CBuf(&mCtrl)] = cnt++;      

    printf("print num is %d\n",arr[GetOutPosi_Front_CBuf(&mCtrl)]);
    printf("print num is %d\n",arr[GetOutPosi_CBuf(&mCtrl)]);
  }

  while(!IsNull_CBuf(&mCtrl))
  {
    printf("print num is %d\n",arr[GetOutPosi_Front_CBuf(&mCtrl)]);
  }
  */
  for(i = 0; i < 4; i++)
  {
    if(IsFull_CBuf(&mCtrl))
      GetOutPosi_Front_CBuf(&mCtrl);
    arr[GetInPosi_Front_CBuf(&mCtrl)] = cnt++;
    if(IsFull_CBuf(&mCtrl))
      GetOutPosi_Front_CBuf(&mCtrl);
    arr[GetInPosi_Front_CBuf(&mCtrl)] = cnt++;
    if(IsFull_CBuf(&mCtrl))
      GetOutPosi_Front_CBuf(&mCtrl);
    arr[GetInPosi_Front_CBuf(&mCtrl)] = cnt++;

    printf("print num is %d\n",arr[GetOutPosi_Front_CBuf(&mCtrl)]);
    printf("print num is %d\n",arr[GetOutPosi_CBuf(&mCtrl)]);
  }
  while(!IsNull_CBuf(&mCtrl))
  {
    printf("print num is %d\n",arr[GetOutPosi_CBuf(&mCtrl)]);
  }

  return 0;
}

