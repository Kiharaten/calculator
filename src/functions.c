/*************************************************************/
/* @file name       : functions.c                            */
/* @brief           : 処理関数記載ファイル                   */
/* @author          : Tenda                                  */
/*************************************************************/

/* file include */
#include "functions.h"

/* global variables */
u1 u1gv_number ;

/*************************************************************/
/* @function name   : スレッド1                              */
/* @brief           : スレッドの世界へようこそ               */
/* @author          : Tenda                                  */
/*************************************************************/
void* thread_100ms(void* arg) {
    /* 宣言 */
    u1* pt_num ;

    /* 引数取得 */
    pt_num = ( u1* )arg ;
    u1gv_number = *pt_num ;

    print_text() ; /* 文字表示関数 */
    return NULL ;
}

/*************************************************************/
/* @function name   : 文字表示関数                           */
/* @brief           : 数字に対応する文字を表示する           */
/* @author          : Tenda                                  */
/*************************************************************/
void print_text( void ) {

    /* ループ回数表示 */
    printf("num = %d, ", u1gv_number ) ;

    switch ( u1gv_number ) {
        case NUM_ZERO :
            printf( "Hello        " ) ;
            break ;

        case NUM_ONE :
            printf( "Toyota       " ) ;
            break ;

        case NUM_TWO :
            printf( "Kawasaki     " ) ;
            break ;

        case NUM_THREE :
            printf( "Nishimatzuya " ) ;
            break ;

        default :
            printf( "Tenda        " ) ;
            break ;
    }
}
/* EOF */