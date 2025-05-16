/* file include */
#include <stdio.h>   // 標準入出力（printf, scanf など）
#include <stdlib.h>  // 標準ライブラリ（malloc, exit など）
#include <string.h>  // 文字列処理（strcpy, strlen など）

/* グローバル定数 */
#define NUM_ZERO    0
#define NUM_ONE     1
#define NUM_TWO     2
#define NUM_THREE   3

/* 関数プロトタイプ宣言 */
void print_text(int get_number) ;

int main(void) {
    print_text( NUM_THREE ); /* 文字表示関数 */
    return(0);
}

/*****************************************
 * 文字表示関数
 * 数字を受け取って、対応する文字をprintfする
 * Author:Tenda
 *****************************************/
void print_text(int get_number) {
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