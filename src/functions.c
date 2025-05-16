/*************************************************************/
/* @file name       : functions.c                            */
/* @brief           : 処理関数記載ファイル                   */
/* @author          : Tenda                                  */
/*************************************************************/

/* file include */
#include "functions.h"

/* global variables */

/*************************************************************/
/* @function name   : スレッド1                           */
/* @brief           : スレッドの世界へようこそ           */
/* @author          : Tenda                                  */
/*************************************************************/
void* thread_func(void* arg) {
    // スレッドで実行される処理
    printf("Hello from thread! arg = %d\n", *(int*)arg);
    print_text( NUM_ONE ) ; /* 文字表示関数 */
    return NULL;
}

/*************************************************************/
/* @function name   : 文字表示関数                           */
/* @brief           : 数字に対応する文字を表示する           */
/* @author          : Tenda                                  */
/*************************************************************/
void print_text( int get_number ) {
    if ( NUM_ZERO == get_number ) {
        printf("Hello\n") ;
    }
    else if ( NUM_ONE == get_number ) {
        printf("Kawasaki\n") ;
    }
    else if ( NUM_TWO == get_number ) {
        printf("Toyota\n") ;
    }
    else {
        printf("Tenda\n") ;
    }
}
/* EOF */