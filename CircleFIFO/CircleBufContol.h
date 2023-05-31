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

//#include  "Bsp.h"


#ifdef  CircleBufContol_C
#define EX_CircleBufContol
#else
#define EX_CircleBufContol extern
#endif

typedef  struct _tCircleBufCtrl{
	unsigned int In;
	unsigned int Out;
	unsigned int MaxItemNum;
}tCircleBufCtrl;

/****************************************************************
  Function:       GetInPosi_CBuf
  Description:    获取队列尾可存储位置,队列尾位置自动更新
  Param:          pCBufCtrl:缓存控制结构指针。
  Return:         可存入的队列位置
****************************************************************/
EX_CircleBufContol unsigned int GetInPosi_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetInPosi_CBuf_RdOnly
  Description:    只读的方式获取队列可存储位置,队列位置不更新
  Param:          pCBufCtrl:缓存控制结构指针。
  Return:         可存入的队列位置
****************************************************************/
EX_CircleBufContol unsigned int GetInPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetInPosi_Front_CBuf
  Description:    以插入的方式在队列头部获取存储位置,队列头位置自动更新
  Param:          pCBufCtrl:缓存控制结构指针。
  Return:         可存入的队列位置
****************************************************************/
EX_CircleBufContol unsigned int GetInPosi_Front_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetInPosi_Front_CBuf_RdOnly
  Description:    以插入的方式在队列头部获取存储位置,队列头位置不更新
  Param:          pCBufCtrl:缓存控制结构指针。
  Return:         可存入的队列位置
****************************************************************/
EX_CircleBufContol unsigned int GetInPosi_Front_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_CBuf
  Description:    获取可发送的队列头位置,队列位置自动更新
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         可取出的队列数据位置
****************************************************************/
EX_CircleBufContol unsigned int GetOutPosi_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_CBuf_RdOnly
  Description:    获取可发送的队列头位置,队列位置不更新
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         可取出的队列数据位置
****************************************************************/
EX_CircleBufContol unsigned int GetOutPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_Front_CBuf
  Description:    获取最新存入队列的可发送数据位置,可队列位置自动更新
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         可取出的队列数据位置
****************************************************************/
EX_CircleBufContol unsigned int GetOutPosi_Front_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_Front_CBuf_RdOnly
  Description:    获取最新存入队列的可发送数据位置,可队列位置不更新
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         可取出的队列数据位置
****************************************************************/
EX_CircleBufContol unsigned int GetOutPosi_Front_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       ResetCircle_CBuf
  Description:    初始化缓存区控制结构
  Param:          pCBufCtrl:缓存控制结构指针;
                  MaxNumItem:最大存储条数 
  Return:         void
****************************************************************/
EX_CircleBufContol void ResetCircle_CBuf(tCircleBufCtrl *pCBufCtrl, unsigned int MaxNumItem);


/****************************************************************
  Function:       IsNull_CBuf
  Description:    判断缓存区是否为空
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         1:空 0:没空
****************************************************************/
EX_CircleBufContol unsigned char IsNull_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       IsFull_CBuf
  Description:    判断缓存区是否满
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         1:满 0：没满
****************************************************************/
EX_CircleBufContol unsigned char IsFull_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetItem_CBuf
  Description:    取一段缓存
  Param:          pCBufCtrl:缓存控制结构指针 Num:要取的条数 CurGetOut: 取到的缓存区的位置
  Return:         取到的地址连续的条数（取到的缓存地址一定是连续的）
****************************************************************/
EX_CircleBufContol unsigned int GetItem_CBuf(tCircleBufCtrl *pCBufCtrl,unsigned int Num,unsigned int *CurGetOut);


/****************************************************************
  Function:       GetUseRate_CBuf
  Description:    获取使用率
  Param:          pCBufCtrl:缓存控制结构指针 Basic:基准值（例：Basic=100 占比就是返回值/Basic）
  Return:         相对与基准值的占比
****************************************************************/
EX_CircleBufContol unsigned short GetUseRate_CBuf(tCircleBufCtrl *pCBufCtrl,unsigned short Basic);


/****************************************************************
  Function:       GetItemNum_CBuf
  Description:    获取使用数量
  Param:          pCBufCtrl:缓存控制结构指针
  Return:         相对与基准值的占比
****************************************************************/
EX_CircleBufContol unsigned short GetItemNum_CBuf(tCircleBufCtrl *pCBufCtrl);

#endif
