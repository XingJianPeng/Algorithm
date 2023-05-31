/******************************************************************************
 * @file     CircleBufContol.c
 * @version  V1.0.0
 * @date     2020/11/23
 * @company	 pi2star
 * @author 	 xjp
 * @brief
 *
 ******************************************************************************/
#define  CircleBufContol_C

#include "CircleBufContol.h"

unsigned char IsNull_CBuf(tCircleBufCtrl *pCBufCtrl)//判断缓存区是否为空
{
#if(CircleVer)
    return !(pCBufCtrl->Entries); 
#else
	if((pCBufCtrl->Out)==(pCBufCtrl->In))
		return 1;
	else
		return 0;
#endif
}

unsigned char IsFull_CBuf(tCircleBufCtrl *pCBufCtrl)//判断缓存区是否满
{
#if(CircleVer)
    return ((pCBufCtrl->Entries == pCBufCtrl->MaxItemNum)?(1):(0));
#else
	if(((pCBufCtrl->Out)==0)&&((pCBufCtrl->In)==(pCBufCtrl->MaxItemNum -1)))
		return 1;
	if((pCBufCtrl->Out )==(pCBufCtrl->In +1))
		return 1;
	else 
		return 0;
#endif
}

unsigned int GetInPosi_CBuf(tCircleBufCtrl *pCBufCtrl)
{
#if(CircleVer)
    unsigned int i;
    if(IsFull_CBuf(pCBufCtrl))  //if full,cover the newest item
    {
      if(pCBufCtrl->In == 0)
        i = pCBufCtrl->MaxItemNum;

      i--; 
      return i;
    }

    i = pCBufCtrl->In++;
    pCBufCtrl->Entries++;
    if(pCBufCtrl->In >= pCBufCtrl->MaxItemNum)
      pCBufCtrl->In = 0;

    return i;
#else
	unsigned int i;
	i=pCBufCtrl->In;
	pCBufCtrl->In++;
	if((pCBufCtrl->In)>=pCBufCtrl->MaxItemNum)
		pCBufCtrl->In=0;
	return i;
#endif
}

unsigned int GetInPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
#if(CircleVer)
    unsigned int i;
    if(IsFull_CBuf(pCBufCtrl))  //if full,cover the newest item
    {
      if(pCBufCtrl->In == 0)
        i = pCBufCtrl->MaxItemNum;

      i--; 
      return i;
    }
    return pCBufCtrl->In;
#else
	return pCBufCtrl->In;
#endif
}

unsigned int GetInPosi_Front_CBuf(tCircleBufCtrl *pCBufCtrl)
{
#if(CircleVer)
    if(IsFull_CBuf(pCBufCtrl))  //if full,cover the newest item
      return pCBufCtrl->Out;
    
    if(pCBufCtrl->Out == 0)
      pCBufCtrl->Out = pCBufCtrl->MaxItemNum;
    pCBufCtrl->Out--;
    pCBufCtrl->Entries++;

    return pCBufCtrl->Out;
#else
    if(pCBufCtrl->Out == 0)
      pCBufCtrl->Out = pCBufCtrl->MaxItemNum;
    pCBufCtrl->Out--;

    return pCBufCtrl->Out;
#endif
}

unsigned int GetInPosi_Front_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
#if(CircleVer)
    unsigned int i = pCBufCtrl->Out;

    if(IsFull_CBuf(pCBufCtrl))  //if full,cover the newest item
      return pCBufCtrl->Out;

    if(i == 0)
      i = pCBufCtrl->MaxItemNum;
    i--;

    return i;
   
#else
    unsigned int i = pCBufCtrl->Out;
    if(i == 0)
      i = pCBufCtrl->MaxItemNum;
    i--;

    return i;
#endif
}

unsigned int GetOutPosi_CBuf(tCircleBufCtrl *pCBufCtrl)
{
#if(CircleVer)
	unsigned int i;
	i=pCBufCtrl->Out;

    if(!IsNull_CBuf(pCBufCtrl)) 
    {
      pCBufCtrl->Out++;
      pCBufCtrl->Entries--;
      if((pCBufCtrl->Out)>=pCBufCtrl->MaxItemNum)
	    pCBufCtrl->Out=0;
    }

    return i;
#else
	unsigned int i;
	i=pCBufCtrl->Out;

	if((pCBufCtrl->Out)!=(pCBufCtrl->In))
	{
		pCBufCtrl->Out++;
		if((pCBufCtrl->Out)>=pCBufCtrl->MaxItemNum)
		    pCBufCtrl->Out=0;
	}
	return i;
#endif
}

unsigned int GetOutPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
	return pCBufCtrl->Out;
}

unsigned int GetOutPosi_Front_CBuf(tCircleBufCtrl *pCBufCtrl)
{
#if(CircleVer)
    unsigned int i = 0;
    if(IsNull_CBuf(pCBufCtrl))
      return pCBufCtrl->Out;

    if(pCBufCtrl->In == 0)
       pCBufCtrl->In = pCBufCtrl->MaxItemNum; 
    pCBufCtrl->In --;
    pCBufCtrl->Entries--;
    i = pCBufCtrl->In;

    return i;
#else
    unsigned int i = 0;
    if((pCBufCtrl->Out) != (pCBufCtrl->In))
    {
        if(pCBufCtrl->In == 0)
           pCBufCtrl->In = pCBufCtrl->MaxItemNum; 
        pCBufCtrl->In --;
        i = pCBufCtrl->In;
    }

    return i;
#endif
}

unsigned int GetOutPosi_Front_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
#if(CircleVer)
    unsigned int i = 0;
    if(IsNull_CBuf(pCBufCtrl))
      return pCBufCtrl->Out;

    i = pCBufCtrl->In;
    if(i == 0)
       i = pCBufCtrl->MaxItemNum; 
    i --;

    return i;
#else
    unsigned int i = 0;
    if((pCBufCtrl->Out) != (pCBufCtrl->In))
    {
        i = pCBufCtrl->In;
        if(i == 0)
           i = pCBufCtrl->MaxItemNum; 
        i --;
    }

    return i;
#endif
}

void ResetCircle_CBuf(tCircleBufCtrl *pCBufCtrl, unsigned int MaxNumItem)
{
	pCBufCtrl->In = 0;
	pCBufCtrl->Out = 0;
#if(CircleVer)
    pCBufCtrl->Entries = 0;
#endif
	pCBufCtrl->MaxItemNum = MaxNumItem;
}

unsigned int GetItem_CBuf(tCircleBufCtrl *pCBufCtrl,unsigned int Num,unsigned int *CurGetOut)
{
#if(CircleVer)
 	unsigned int Item=0;
	*CurGetOut=pCBufCtrl->Out;
    if(IsNull_CBuf(pCBufCtrl))
      return 0;

    if(IsFull_CBuf(pCBufCtrl))
      return pCBufCtrl->MaxItemNum - pCBufCtrl->Out;

	if(pCBufCtrl->In > pCBufCtrl->Out) 
    {
		Item = pCBufCtrl->In - pCBufCtrl->Out; //最多取多少
		if (Item < Num) 
        {
			pCBufCtrl->Out = pCBufCtrl->In;
            pCBufCtrl->Entries -= Item;
			return Item;
		} 
        else 
        {
			pCBufCtrl->Out += Num;
            pCBufCtrl->Entries -= Num;
			return Num;
		}
	} 
    else 
    {
		Item = pCBufCtrl->MaxItemNum - pCBufCtrl->Out; //最多取多少
		if (Item < Num) 
        {
			pCBufCtrl->Out = 0;
            pCBufCtrl->Entries -= Item;
			return Item;
		} 
        else 
        {
			pCBufCtrl->Out += Num;
            pCBufCtrl->Entries -= Num;
			return Num;
		}
	}
#else
	unsigned int Item=0;
	*CurGetOut=pCBufCtrl->Out;
	if (pCBufCtrl->In > pCBufCtrl->Out) {
		Item = pCBufCtrl->In - pCBufCtrl->Out; //最多取多少
		if (Item < Num) {

			pCBufCtrl->Out = pCBufCtrl->In;
			return Item;
		} else {
			pCBufCtrl->Out += Num;
			return Num;
		}
	} else {
		Item = pCBufCtrl->MaxItemNum - pCBufCtrl->Out; //最多取多少
		if (Item < Num) {

			pCBufCtrl->Out = 0;
			return Item;
		} else {
			pCBufCtrl->Out += Num;
			return Num;
		}
	}
#endif
}

unsigned short GetUseRate_CBuf(tCircleBufCtrl *pCBufCtrl,unsigned short Basic)
{
#if(CircleVer)
    return (pCBufCtrl->Entries)*Basic/pCBufCtrl->MaxItemNum; 
#else
	unsigned short i=0;

	if(pCBufCtrl->In>=pCBufCtrl->Out){
		i=((pCBufCtrl->In - pCBufCtrl->Out)*Basic)/pCBufCtrl->MaxItemNum;
	}else{
		i=((pCBufCtrl->MaxItemNum - pCBufCtrl->Out + pCBufCtrl->In)*Basic)/pCBufCtrl->MaxItemNum;
	}

	return i;
#endif
}

unsigned short GetItemNum_CBuf(tCircleBufCtrl *pCBufCtrl)
{
#if(CircleVer)
    return pCBufCtrl->Entries;
#else
	unsigned short i = 0;
	if(pCBufCtrl->In >= pCBufCtrl->Out)
	{
		i=(pCBufCtrl->In - pCBufCtrl->Out);
	}
	else
	{
		i=(pCBufCtrl->MaxItemNum - pCBufCtrl->Out + pCBufCtrl->In);
	}
	return i;
#endif
}
