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
	if((pCBufCtrl->Out)==(pCBufCtrl->In))
		return 1;
	else
		return 0;
}

unsigned char IsFull_CBuf(tCircleBufCtrl *pCBufCtrl)//判断缓存区是否满
{
	if(((pCBufCtrl->Out)==0)&&((pCBufCtrl->In)==(pCBufCtrl->MaxItemNum -1)))
		return 1;
	if((pCBufCtrl->Out )==(pCBufCtrl->In +1))
		return 1;
	else 
		return 0;
}

unsigned int GetInPosi_CBuf(tCircleBufCtrl *pCBufCtrl)
{
	unsigned int i;
	i=pCBufCtrl->In;
	pCBufCtrl->In++;
	if((pCBufCtrl->In)>=pCBufCtrl->MaxItemNum)
		pCBufCtrl->In=0;
	return i;
}

unsigned int GetInPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
	return pCBufCtrl->In;
}

unsigned int GetInPosi_Front_CBuf(tCircleBufCtrl *pCBufCtrl)
{
    if(pCBufCtrl->Out == 0)
      pCBufCtrl->Out = pCBufCtrl->MaxItemNum;
    pCBufCtrl->Out--;

    return pCBufCtrl->Out;
}

unsigned int GetInPosi_Front_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
    unsigned int i = pCBufCtrl->Out;
    if(i == 0)
      i = pCBufCtrl->MaxItemNum;
    i--;

    return i;
}

unsigned int GetOutPosi_CBuf(tCircleBufCtrl *pCBufCtrl)
{
	unsigned int i;
	i=pCBufCtrl->Out;

	if((pCBufCtrl->Out)!=(pCBufCtrl->In))
	{
		pCBufCtrl->Out++;
		if((pCBufCtrl->Out)>=pCBufCtrl->MaxItemNum)
		    pCBufCtrl->Out=0;
	}
	return i;
}

unsigned int GetOutPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
	return pCBufCtrl->Out;
}

unsigned int GetOutPosi_Front_CBuf(tCircleBufCtrl *pCBufCtrl)
{
    unsigned int i = 0;
    if((pCBufCtrl->Out) != (pCBufCtrl->In))
    {
        if(pCBufCtrl->In == 0)
           pCBufCtrl->In = pCBufCtrl->MaxItemNum; 
        pCBufCtrl->In --;
        i = pCBufCtrl->In;
    }

    return i;
}

unsigned int GetOutPosi_Front_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
    unsigned int i = 0;
    if((pCBufCtrl->Out) != (pCBufCtrl->In))
    {
        i = pCBufCtrl->In;
        if(i == 0)
           i = pCBufCtrl->MaxItemNum; 
        i --;
    }

    return i;
}

void ResetCircle_CBuf(tCircleBufCtrl *pCBufCtrl, unsigned int MaxNumItem)
{
	pCBufCtrl->In = 0;
	pCBufCtrl->Out = 0;
	pCBufCtrl->MaxItemNum = MaxNumItem;
}

unsigned int GetItem_CBuf(tCircleBufCtrl *pCBufCtrl,unsigned int Num,unsigned int *CurGetOut)
{
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
}

unsigned short GetUseRate_CBuf(tCircleBufCtrl *pCBufCtrl,unsigned short Basic)
{
	unsigned short i=0;

	if(pCBufCtrl->In>=pCBufCtrl->Out){
		i=((pCBufCtrl->In - pCBufCtrl->Out)*Basic)/pCBufCtrl->MaxItemNum;
	}else{
		i=((pCBufCtrl->MaxItemNum - pCBufCtrl->Out + pCBufCtrl->In)*Basic)/pCBufCtrl->MaxItemNum;
	}

	return i;

}

unsigned short GetItemNum_CBuf(tCircleBufCtrl *pCBufCtrl)
{
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
}
