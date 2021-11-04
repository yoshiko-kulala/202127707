/* 関数の仮引数の値を変更するプログラム */
#include "stdio.h"
#include "math.h"

/* 仮引数の値を変更する関数 */
void change_param(int* n)
{
    /* 仮引数nの値を絶対値に変換する */
    *n = abs(*n);
}

int main(void)
{
    int i; /* ループ制御変数 */
    int narray[] = { -300, -100, -650, -1000, -240, -500 };

    for (i = 0; i < sizeof narray / sizeof(int); i++)
        /* change_param()関数を呼び出す */
        change_param(&narray[i]);

    /* change_param()関数を呼び出したあとの配列narrayの要素の値を調べる */
    printf("change_param()関数呼び出し後のnarrayの要素を調べる\n");
    for (i = 0; i < sizeof narray / sizeof(int); i++)
        printf("要素[%d]の値：%d\n", i, narray[i]);
    printf("\n");

    return 0;
}


