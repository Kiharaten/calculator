/*************************************************************/
/* @file name       : main.c                                 */
/* @brief           : メインプログラム                       */
/* @author          : Tenda                                  */
/*************************************************************/

/* file include */
#include "main.h"

/*************************************************************/
/* @function name   : メイン関数                             */
/* @brief           : メインルーチン処理をする関数           */
/* @author          : Tenda                                  */
/*************************************************************/
int main(void) {
    pthread_t tid;
    int arg = 42;

    /* スレッドを作成 */
    if (pthread_create(&tid, NULL, thread_func, &arg) != 0) {
        perror("pthread_create");
        return 1;
    }

    // スレッドの終了を待機
    pthread_join(tid, NULL);

    printf("メインスレッド終了\n");
    return 0;
}
/* EOF */