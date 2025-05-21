/*************************************************************/
/* @file name       : main.c                                 */
/* @brief           : メインプログラム                       */
/* @author          : Tenda                                  */
/*************************************************************/

// /* file include */
// #include "main.h"

// /* global variables */
// volatile    u1 u1gv_hoge ;      /* 変数     */
// volatile    u1 u1gf_fuga ;      /* フラグ   */
// const       u1 u1gk_constant ;  /* 定数     */

// /*************************************************************/
// /* @function name   : メイン関数                             */
// /* @brief           : メインルーチン処理をする関数           */
// /* @author          : Tenda                                  */
// /*************************************************************/
// int main( void ) {
//     /* 宣言 */
//     pt tid_100ms ;
//     u1 u1t_count ;

//     /* 初期化 */
//     u1t_count = NUM_ZERO ;

//     while( TRUE ) {
//         /* スレッドを生成 */
//         if ( pthread_create( &tid_100ms, NULL, thread_100ms, &u1t_count ) != 0 ) {
//             perror( "pthread_create" ) ;
//             exit( NG ) ; /* 生成失敗した場合、異常値で終了する */
//         }

//         /* スレッドの終了を待機 */
//         pthread_join( tid_100ms, NULL ) ;
//         printf( "thread is end.\n" ) ;

//         /* wait task count */
//         usleep( TASK_B * TIME_1000 ) ;

//         /* ループカウント */
//         u1t_count++ ;

//         /* 終了判定 */
//         if( LOOP_MAX == u1t_count ) {
//             printf( "\nスレッドを%d回実行しました。\n", u1t_count ) ;
//             exit( OK ) ; /* スレッドを10回実行した場合、正常値で終了する */
//         }
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <sys/timerfd.h>
#include <time.h>

volatile sig_atomic_t stop_flag = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void abort_handler(int sig);
void thread_func(union sigval arg);
void thread_func2(void);

void abort_handler(int sig){
    stop_flag = 1;
}


void thread_func(union sigval arg){
    printf("Tid = %lu\n",pthread_self());
    pthread_cond_signal(&cond);
}
void thread_func2(void){
    int ret;
    struct timespec curTime,lastTime;
    clock_gettime(CLOCK_REALTIME,&lastTime);

    pthread_mutex_lock(&m);
    while(1){
        ret = pthread_cond_wait(&cond,&m);
        if(ret == 0){
            clock_gettime(CLOCK_REALTIME,&curTime);
            printf("¥033[2J");   /* 画面をクリア */
            printf("¥033[5;10H"); /* カーソルを移動 */
            printf("¥033[33m");   /* 文字色を黄色に */
            if(curTime.tv_nsec < lastTime.tv_nsec){
                printf("Interval = %10ld.%09ld\n",curTime.tv_sec - lastTime.tv_sec - 1,curTime.tv_nsec + 1000000000 - lastTime.tv_nsec);
            }
            else{
                printf("Interval = %10ld.%09ld\n",curTime.tv_sec - lastTime.tv_sec,curTime.tv_nsec - lastTime.tv_nsec);
            }
            lastTime = curTime;
        }
        if(stop_flag){
            break;
        }

    }
    pthread_mutex_unlock(&m);

}


int main(int argc,char *argv[]){
    timer_t timer_id;
    struct itimerspec ts;
    struct sigevent se;
    int status;
    pthread_t thread;
    int ret;

    if (signal(SIGINT,abort_handler) == SIG_ERR){
        printf("Singal Handler set error!!\n");
        exit(1);
    }
    se.sigev_notify = SIGEV_THREAD;
    se.sigev_value.sival_ptr = &timer_id;
    se.sigev_notify_function = thread_func;
    se.sigev_notify_attributes = NULL;

    ts.it_value.tv_sec = 1;
    ts.it_value.tv_nsec = 0;
    ts.it_interval.tv_sec = 1;
    ts.it_interval.tv_nsec = 0;
    
    status = timer_create(CLOCK_MONOTONIC,&se,&timer_id);
    if(status == -1){
        printf("Fail to creat timer\n");
        exit(1);
    }
    status = timer_settime(timer_id,0,&ts,0);
    if(status == -1){
        printf("Fail to set timer\n");
        exit(1);
    }
        ret = pthread_create(&thread,NULL,(void *)thread_func2,NULL);
    if(ret != 0){
        printf("Cannot create thread!!\n");
        exit(1);
    }


    ret = pthread_join(thread,NULL);
    if(ret != 0){
        printf("Cannot join thread!!\n");
        exit(1);
    }

    timer_delete(timer_id);

    return 0;
}

/* EOF */