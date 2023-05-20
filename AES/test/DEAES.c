
#include "aes.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char input[1000] = {0};
char key[16] = {
  0xA1, 0xA2, 0xAB, 0xA4,
  0xA5, 0xA8, 0xAC, 0xAE,
  0xA6, 0xA9, 0xAD, 0xAF,
  0xA7, 0xAA, 0xAE, 0xA0,
};

int main(int argc, char** argv)
{
  int len = 0;
  FILE*  fp;

  if(argc != 2 && argc != 3)
  {
    printf("Tip: ./AES srcfile [-s]\n");
    return 1;
  }

  fp = fopen(argv[1],"r+");
  if(NULL == fp)
  {
    printf("Error: %s\n",strerror(errno));
    return 1;
  }

  //read every hex data to input arr
  ssize_t readnum = 0;
  size_t n = 0;
  char* buff = NULL;
  char* p = NULL;
  char* pN = NULL;
  char temp[500];

  char deli[] = {" ,;\n"};
  p = &temp[0];
  while(1)
  {
    readnum = getline(&buff,&n,fp);
    if(-1 == readnum)
    {
      break;
    }

    //firt 
    p = strtok(buff,deli); 
    while(NULL != p)
    {
      input[len++] = (char)strtoul(p,&pN,0); 
      p = strtok(NULL,deli);
    }
  }

  free(buff);
  fclose(fp);

  int silence = 0;
  if(argc == 3 && strcmp(argv[2],"-s")==0)
  {
    silence = 1;
  }

  len = len/16*16+((len%16)?(16):(0));
  if(!silence)
  {
    printf("input data is(in Hex Mode):\n");

    for(int i = 0 ; i < len; i++)
    {
      printf("0x%.2hhX ",input[i]);
    }
    printf("\n");
    printf("data is aesing...:\n");
  }

  //clock_t start,end;
  //start = clock();
  deAes(input,len,key);
  //end = clock();
  //double seconds = (double)(end - start)/CLOCKS_PER_SEC;
  //printf("aes use time:%.10f\n",seconds);

  if(!silence)
    printf("de aes data is(in Hex Mode):\n");
  for(int i = 0 ; i < len; i++)
  {
    printf("0x%.2hhX ",input[i]);
  }
  printf("\n");

  return 0;
}

