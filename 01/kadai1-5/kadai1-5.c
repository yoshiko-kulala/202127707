/* 呼び出しのたびに呼び出し回数を返す関数を使うプログラム */
#include "stdio.h"

#define MAX_COUNT 5

/* ローカル変数を使う関数 */
int getcount()
{
    /* 関数のローカル変数を宣言、初期化する */
    static int count = 0;

    /* ローカル変数をインクリメントして返す */
    return ++count;
}

int main(void)
{
    int i; /* ループ制御変数 */

    /* getcount()関数を呼び出す */
    for (i = 0; i < MAX_COUNT; i++) {
        printf("%d ", getcount());
    }
    printf("\n");

    return 0;
}
