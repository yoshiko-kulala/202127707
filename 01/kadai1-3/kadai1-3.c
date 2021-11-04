/* 配列のとなり合う要素が同じであることを調べるプログラム */
#include "stdio.h"

int main(void)
{
    int narray[8] = { 120, 50, 70, 70, 100, 20, 30, 80 };
    int i; /* ループ制御変数 */

    for (i = 0; i < 7; i++) {
        if (narray[i] == narray[i + 1]) {
            printf("配列の第 %d 要素と第 %d 要素の値は同じです。\n", 
                   i + 1, i + 2);
        }
    }

    return 0;
}
