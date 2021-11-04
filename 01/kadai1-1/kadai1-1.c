/* 4列ごとに改行して表示するプログラム */
#include "stdio.h"

/* グローバル変数を宣言、初期化する */
int count = 4;

int main(void)
{
    int i; /* ループ制御変数 */
    int count_l = 0; /* ローカル変数を宣言、初期化する */

    for (i = 0; i < 20; i++) {
        /* 4回ごとに改行する */
        if (i != 0 && i % count == 0)
            printf("\n");
        /* iの値を表示する */
        printf("%d ", i);
        count_l++;
   }
    /* countの値を表示する */
    printf("\ncountの値：%d\n", count_l);

    return 0;
}

