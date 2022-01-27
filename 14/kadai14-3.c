#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 1; //解の数をカウント

void print_border(int n);
void print_queen(int q[], int n);

// 盤面の全パターンを生成する処理
void set_queen(int q[], int, int);

// 2つの位置のクイーンが互いに取り合う位置か判定
int safe(int q[], int i, int j);

// 盤面にあるクイーンが互いに取り合う位置にあるか判定
int safe_all(int q[], int k);

// 任意のnでのNクイーン問題を解く
int solve(int n);


// ある盤面にあるクイーンがお互いに取り合う関係にあるか判定
int safe_all(int q[], int n) {
    // ここに処理を記入（課題2)
    // q: 盤面の配列, n: 配列の要素数
    // 取り合う関係なら-1を返す
    // それ以外は1(取り合う関係にない)を返す
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(safe(q,i,j)==-1)return -1;
    }
  }
  return 1;
}


int safe(int q[], int i, int j)
{
    // ここに処理を記入（課題2)
    // q: 盤面の配列, i列目とj列目の要素が取り合う関係か調べる
    // 取り合う関係なら-1を返す
    // それ以外は1(取り合う関係にない)を返す
  if(q[i]==q[j])return -1;
  if(abs(q[i]-q[j])==abs(i-j))return -1;
  return 1;
}

// 引数で指定されたnクイーン問題を解く関数
int solve(int n)
{
    int *q;
    q = malloc(sizeof(int) * n); // 盤面を表す領域の割り当て

    set_queen(q, 0, n);

    return 0;
}

void set_queen(int q[], int m, int n)
{
// 課題1の処理に追加で記入（課題2）
  int i;
  if( m == n){
    // ある盤面に関する判定処理を書く
    if(safe_all(q,n)==1)
      print_queen(q,n);
    return;
  }
  for( i = 0; i < n; i++){
    q[m] = i;
    if(q[m]==q[m-1])set_queen(q, n, n);
    else set_queen(q, m + 1, n);
  }
}

// 盤面をテキスト表示
void print_queen(int q[], int n)
{
// 課題1を流用
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

    start = clock();
    m = solve(n);
    end = clock();
    printf("%f sec\n", ((double)(end - start) / CLOCKS_PER_SEC));

    return 0;
}