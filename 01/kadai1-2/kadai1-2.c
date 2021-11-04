/* 奇数を表示するプログラム */
#include "stdio.h"

int main(void)
{
    int n = 0;

    /* nが99より大きくなればループを終了する */
    while (++n > 0 && n < 100) {
        /* 奇数なら表示する */
        if (n % 2)
            printf("%d ", n);
    }

    return 0;
}

