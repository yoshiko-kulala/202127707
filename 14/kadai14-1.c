#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 1; //解の数をカウント

void print_border(int n);
void print_queen(int q[], int n);

// 盤面の全パターンを生成する処理
void set_queen(int q[], int m, int n);

void set_queen(int q[], int m, int n)
{
  // 引数 q:盤面の配列，m: 第m列目の盤面を作成（再帰処理で利用), n:盤面qの要素数
  // ここに処理を書く（課題1)
  print_queen(q,n);
  int i;
  if( m == n){
    // ある盤面に関する判定処理を書く
    return;
  }
  for( i = 0; i < n; i++){
    q[m] = i;
    set_queen(q, m + 1, n);
  }
  // 再帰処理の実装方法によっては引数の取り方や補助関数を作成してもよい
}

// 引数で指定されたnクイーン問題を解く関数(課題1では解く処理は含まれない）
int solve(int n)
{
    int *q;
    q = malloc(sizeof(int) * n); // 盤面を表す領域の割り当て

    set_queen(q, 0, n);
    return 0;
}

void print_queen(int q[], int n)
{
  for(int i=0;i<n; i++ ) {
    for(int j=0; j<n; j++ )
      if ( i == q[j] ) printf(" Q"); else printf(" .");
        printf("\n");
    }
    printf("\n"); 
}


// main関数
int main(int argc, char **argv)
{
    int m;
    int n;
    int start, end;

    // Nを入力
    printf("Input a integer(>=1): ");
    scanf("%d", &n);

    if (n <= 0) //0以下でないかチェック
    {
        printf("N must be a integer than 1\n");
        return 0;
    }

    solve(n);

    return 0;
}