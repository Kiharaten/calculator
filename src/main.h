/*************************************************************/
/* @file name       : main.h                                 */
/* @brief           : メインプログラムヘッダファイル         */
/* @author          : Tenda                                  */
/*************************************************************/
#ifndef MAIN_H
#define MAIN_H

/* file include */
#include <stdio.h>      /* 標準入出力（printf, scanf etc.）     */
#include <stdlib.h>     /* 標準ライブラリ（malloc, exit etc.）  */
#include <string.h>     /* 文字列処理（strcpy, strlen etc.）    */
#include <pthread.h>
#include "functions.h"

/* type definition */
typedef unsigned char   u1 ;
typedef signed char     s1 ;

typedef unsigned short  u2 ;
typedef signed short    s2 ;

typedef unsigned int    u4 ;
typedef signed int      s4 ;

typedef unsigned long   u8 ;
typedef signed long     s8 ;

typedef float           f4 ;
typedef double          f8 ;

/* global variables */
typedef enum {
    NUM_ZERO ,
    NUM_ONE ,
    NUM_TWO ,
    NUM_THREE ,
    NUM_COUNT_MAX
} NUM ;

#endif /* MAIN_H */
/* EOF */