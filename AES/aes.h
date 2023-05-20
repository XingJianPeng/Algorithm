#ifndef AES_H
#define AES_H

#include <stdlib.h>
#include <string.h>

#ifdef  AES_C
#define EX_AES
#else
#define EX_AES extern
#endif

/***************************************************
 * Function:    ase 
 * Description: ase加密(ECB模式)
 * Param:       p:    明文的字符串数组。
 *              plen: 明文的长度,长度必须为16的倍数。
 *              key : 密钥字符数组
 * Return:      0 = successful 
 **************************************************/
EX_AES unsigned char aes(char *p, int plen, char *key);



/***************************************************
 * Function:    deAse 
 * Description: ase解密(ECB模式)
 * Param:       p:    明文的字符串数组。
 *              plen: 明文的长度,长度必须为16的倍数。
 *              key : 密钥字符数组
 * Return:      void
 **************************************************/
EX_AES unsigned char deAes(char *c, int clen, char *key);


#endif


