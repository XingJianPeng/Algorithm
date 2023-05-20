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

uint8_t IsNull_CBuf(tCircleBufCtrl *pCBufCtrl)//判断缓存区是否为空
{
	if((pCBufCtrl->Out)==(pCBufCtrl->In))
		return 1;
	else
		return 0;
}
uint8_t IsFull_CBuf(tCircleBufCtrl *pCBufCtrl)//判断缓存区是否满
{
	if(((pCBufCtrl->Out)==0)&&((pCBufCtrl->In)==(pCBufCtrl->MaxItemNum -1)))
		return 1;
	if((pCBufCtrl->Out )==(pCBufCtrl->In +1))
		return 1;
	else 
		return 0;
}
uint32_t GetInPosi_CBuf(tCircleBufCtrl *pCBufCtrl)
{
	uint32_t i;
	i=pCBufCtrl->In;
	pCBufCtrl->In++;
	if((pCBufCtrl->In)>=pCBufCtrl->MaxItemNum)
		pCBufCtrl->In=0;
	return i;
}

uint32_t GetInPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
	return pCBufCtrl->In;
}

uint32_t GetOutPosi_CBuf(tCircleBufCtrl *pCBufCtrl)
{
	uint32_t i;
	i=pCBufCtrl->Out;

	if((pCBufCtrl->Out)!=(pCBufCtrl->In))
	{
		pCBufCtrl->Out++;
		if((pCBufCtrl->Out)>=pCBufCtrl->MaxItemNum)
		    pCBufCtrl->Out=0;
	}
	return i;
}

uint32_t GetOutPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl)
{
	return pCBufCtrl->Out;
}

void ResetCircle_CBuf(tCircleBufCtrl *pCBufCtrl, uint32 cMaxNumItem)
{
	pCBufCtrl->In = 0;
	pCBufCtrl->Out = 0;
	pCBufCtrl->MaxItemNum = cMaxNumItem;
}

uint32_t GetItem_CBuf(tCircleBufCtrl *pCBufCtrl,u32 Num,u32 *CurGetOut)
{
	u32 Item=0;
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
u16 GetUseRate_CBuf(tCircleBufCtrl *pCBufCtrl,u16 Basic)
{
	u16 i=0;

	if(pCBufCtrl->In>=pCBufCtrl->Out){
		i=((pCBufCtrl->In-pCBufCtrl->Out)*Basic)/pCBufCtrl->MaxItemNum;
	}else{
		i=((pCBufCtrl->MaxItemNum-pCBufCtrl->Out+pCBufCtrl->In)*Basic)/pCBufCtrl->MaxItemNum;
	}

	return i;

}

u16 GetItemNum_CBuf(tCircleBufCtrl *pCBufCtrl)
{
	u16 i = 0;
	if(pCBufCtrl->In >= pCBufCtrl->Out)
	{
		i=(pCBufCtrl->In-pCBufCtrl->Out);
	}
	else
	{
		i=(pCBufCtrl->MaxItemNum - pCBufCtrl->Out + pCBufCtrl->In);
	}
	return i;
}
