#include <stdio.h>

void print_text(int get_number) ;

int main(void) {
    print_text(3);
}

void print_text(int get_number) {
    if ( 0 == get_number ) {
        printf("Hello\n") ;
    }
    else if ( 1 == get_number ) {
        printf("Kawasaki\n") ;
    }
    else if ( 2 == get_number ) {
        printf("Toyota\n") ;
    }
    else {
        printf("Tenda\n") ;
    }
}

/*
#include <stdio.h>   // 標準入出力（printf, scanf など）
#include <stdlib.h>  // 標準ライブラリ（malloc, exit など）
#include <string.h>  // 文字列処理（strcpy, strlen など）

// グローバル定数（例）
#define MAX_LENGTH 100

// 関数プロトタイプ（宣言）
void print_text(const char* message);
int get_number_from_user(void);

int main(void) {
    // 変数定義
    char message[MAX_LENGTH];
    int number;

    // 標準入力からデータを取得
    printf("メッセージを入力してください: ");
    fgets(message, MAX_LENGTH, stdin);

    // 改行を取り除く（fgets用）
    message[strcspn(message, "\n")] = '\0';

    number = get_number_from_user();

    // 出力
    print_text(message);
    printf("あなたの入力した数字: %d\n", number);

    return 0;
}

// 関数定義（メッセージ表示）
void print_text(const char* message) {
    printf("入力されたメッセージ: %s\n", message);
}

// 関数定義（ユーザーから数字を取得）
int get_number_from_user(void) {
    int num;
    printf("数字を入力してください: ");
    scanf("%d", &num);
    return num;
}
*/