/******************************************************************************
 * @file     CircleBufContol.h
 * @version  V1.0.0
 * @date     2020/11/23
 * @company	 pi2star
 * @author 	 xjp
 * @brief
 *
 * CircleBufContolģ��˵��
 * 1.�����ṩ����: (1)���λ��������ƽṹ���ʼ�� (2)ȡ���λ������������ (3)ȡ���λ������������
 * 				  (4)ȡһ����������Ϣ (5)��ȡ��������ʹ��ռ��
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
  Description:    ��ȡ�������洢λ��
  Param:         	pCBufCtrl:������ƽṹָ�롣
  Return:         �������洢λ��
****************************************************************/
EX_CircleBufContol uint32_t GetInPosi_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetInPosi_CBuf
  Description:    ��ȡ�������洢λ��
  Param:         	pCBufCtrl:������ƽṹָ�롣
  Return:         �������洢λ��
****************************************************************/
EX_CircleBufContol uint32_t GetInPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_CBuf
  Description:    ��ȡ��������Ҫȡ����λ��
  Param:          pCBufCtrl:������ƽṹָ��
  Return:         ������ȡ��λ��
****************************************************************/
EX_CircleBufContol uint32_t GetOutPosi_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_CBuf_RdOnly
  Description:    ��ȡ��������Ҫȡ����λ��,���λ���λ�ò��ı�
  Param:          pCBufCtrl:������ƽṹָ��
  Return:         ������ȡ��λ��
****************************************************************/
EX_CircleBufContol uint32_t GetOutPosi_CBuf_RdOnly(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetOutPosi_CBuf
  Description:    ��ʼ�����������ƽṹ
  Param:          pCBufCtrl:������ƽṹָ��
  Return:         void
****************************************************************/
EX_CircleBufContol void ResetCircle_CBuf(tCircleBufCtrl *pCBufCtrl, uint32 cMaxNumItem);


/****************************************************************
  Function:       IsNull_CBuf
  Description:    �жϻ������Ƿ�Ϊ��
  Param:          pCBufCtrl:������ƽṹָ��
  Return:         1:�� 0:û��
****************************************************************/
EX_CircleBufContol uint8_t IsNull_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       IsFull_CBuf
  Description:    �жϻ������Ƿ���
  Param:          pCBufCtrl:������ƽṹָ��
  Return:         1:�� 0��û��
****************************************************************/
EX_CircleBufContol uint8_t IsFull_CBuf(tCircleBufCtrl *pCBufCtrl);


/****************************************************************
  Function:       GetItem_CBuf
  Description:    ȡһ�λ���
  Param:          pCBufCtrl:������ƽṹָ�� Num:Ҫȡ������ CurGetOut: ȡ���Ļ�������λ��
  Return:         ȡ���ĵ�ַ������������ȡ���Ļ����ַһ���������ģ�
****************************************************************/
EX_CircleBufContol uint32_t GetItem_CBuf(tCircleBufCtrl *pCBufCtrl,u32 Num,u32 *CurGetOut);


/****************************************************************
  Function:       GetUseRate_CBuf
  Description:    ��ȡʹ����
  Param:          pCBufCtrl:������ƽṹָ�� Basic:��׼ֵ������Basic=100 ռ�Ⱦ��Ƿ���ֵ/Basic��
  Return:         ������׼ֵ��ռ��
****************************************************************/
EX_CircleBufContol u16 GetUseRate_CBuf(tCircleBufCtrl *pCBufCtrl,u16 Basic);


/****************************************************************
  Function:       GetItemNum_CBuf
  Description:    ��ȡʹ������
  Param:          pCBufCtrl:������ƽṹָ��
  Return:         ������׼ֵ��ռ��
****************************************************************/
EX_CircleBufContol u16 GetItemNum_CBuf(tCircleBufCtrl *pCBufCtrl);

#endif