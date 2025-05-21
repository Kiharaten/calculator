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
#include <unistd.h>

/* header include */
#include "functions.h"

/* type definition */
typedef pthread_t       pt ;

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

/* definition */
#define TRUE        ( 1 )
#define FALSE       ( 0 )

#define OK          ( 0 )
#define NG          ( 1 )

#define ON          ( 1 )
#define OFF         ( 0 )

#define TIME_A      ( 10 )   /* 10ms周期タスク */
#define TASK_B      ( 100 )  /* 100ms周期タスク */
#define TASK_C      ( 1000 ) /* 1000ms周期タスク */
#define TIME_1000   ( 1000 ) /* 時間1000倍用 */
#define LOOP_MAX    ( 100 )  /* 周回数 */

typedef enum {
    NUM_ZERO ,
    NUM_ONE ,
    NUM_TWO ,
    NUM_THREE ,
    NUM_COUNT_MAX
} NUM ;

#endif /* MAIN_H */
/* EOF */