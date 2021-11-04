/* 再帰関数を使って累乗値を計算するプログラム */
#include "stdio.h"
#include "math.h"

#define MAX_COUNT 10

/* 計算結果を書き出すグローバル変数 */
double result = 1;

/* 累乗計算を行う再帰関数 */
double mult(double n, double times)
{
    result *= n; times--;

    if (times > 0)
        /* 自己再帰的に呼び出す */
        return mult(n, times);
    /* 再帰処理を終える */
    return result;
}

double mypow(double n, double times){
	result = 1;
	return mult(n, times);
}

int main(void)
{
    int i ;

    printf("独自の関数を使って累乗値を求める\n");
    /* 毎回、底と指数を更新して、累乗値を求める */
    for (i = 1; i < MAX_COUNT; i++){
        printf("底「%d」、指数「%d」の累乗値：%g\n", i, i, mypow(i, i));
    }

    printf("pow()関数を使って累乗値を求める\n");
    /* 毎回、底と指数を更新して、累乗値を求める */
    for (i = 1; i < MAX_COUNT; i++){
        printf("底「%d」、指数「%d」の累乗値：%g\n", i, i, pow(i, i));
    }

    return 0;
}



