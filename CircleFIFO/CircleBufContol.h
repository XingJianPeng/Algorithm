/******************************************************************************
 * @file     CircleBufContol.h
 * @version  V1.0.0
 * @date     2020/11/23
 * @company	 pi2star
 * @author 	 xjp
 * @brief
 *
 * CircleBufContol模块说明
 * 1.对外提供功能: (1)环形缓存区控制结构体初始化 (2)取环形缓存区的输入点 (3)取环形缓存区的输出点
 * 				  (4)取一定数量的信息 (5)获取缓冲区的使用占比
 *
 *
 ******************************************************************************/

#ifndef __CircleBufContol_H
#define __CircleBufContol_H

#include  "Bsp.h"


#ifdef  CircleBufContol_C
#define EX_CircleBufContol
#else
#define EX_CircleBufContol extern
#endif

typedef  struct _tCircleBufCtrl{
	uint32_t In;
	uint32_t Out;
	uint32_t MaxItemNum;
}tCircleBufCtrl;

/****************************************************************
  Function:       GetInPosi_CBuf
  Description:    获取缓存区存储位置
  Param:         	pCBufCtrl:缓存控制结构指针。
  Return:         缓存区存储位置
****************************************************************/
EX_CircleBufContol uint32_t GetInPosi_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetInPosi_CBuf
  Description:    获取缓存区存储位置
  Param:         	pCBufCtrl:缓存控制结构指针。
  Return:         缓存区存储位置
****************************************************************/
EX_CircleBufContol uint32_t GetInPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_CBuf
  Description:    获取缓存区需要取出的位置
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         缓存区取出位置
****************************************************************/
EX_CircleBufContol uint32_t GetOutPosi_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_CBuf_RdOnly
  Description:    读取缓存区需要取出的位置,环形缓存位置不改变
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         缓存区取出位置
****************************************************************/
EX_CircleBufContol uint32_t GetOutPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_CBuf
  Description:    初始化缓存区控制结构
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         void
****************************************************************/
EX_CircleBufContol void ResetCircle_CBuf(tCircleBufCtrl *pCBufCtrl, uint32 cMaxNumItem);


/****************************************************************
  Function:       IsNull_CBuf
  Description:    判断缓存区是否为空
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         1:空 0:没空
****************************************************************/
EX_CircleBufContol uint8_t IsNull_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       IsFull_CBuf
  Description:    判断缓存区是否满
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         1:满 0：没满
****************************************************************/
EX_CircleBufContol uint8_t IsFull_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetItem_CBuf
  Description:    取一段缓存
  Param:          pCBufCtrl:缓存控制结构指针 Num:要取的条数 CurGetOut: 取到的缓存区的位置
  Return:         取到的地址连续的条数（取到的缓存地址一定是连续的）
****************************************************************/
EX_CircleBufContol uint32_t GetItem_CBuf(tCircleBufCtrl *pCBufCtrl,u32 Num,u32 *CurGetOut);


/****************************************************************
  Function:       GetUseRate_CBuf
  Description:    获取使用率
  Param:          pCBufCtrl:缓存控制结构指针 Basic:基准值（例：Basic=100 占比就是返回值/Basic）
  Return:         相对与基准值的占比
****************************************************************/
EX_CircleBufContol u16 GetUseRate_CBuf(tCircleBufCtrl *pCBufCtrl,u16 Basic);


/****************************************************************
  Function:       GetItemNum_CBuf
  Description:    获取使用数量
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         相对与基准值的占比
****************************************************************/
EX_CircleBufContol u16 GetItemNum_CBuf(tCircleBufCtrl *pCBufCtrl);

#endif
