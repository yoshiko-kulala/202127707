#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // 配列の長さ

void quick(int *, int, int);
int pivot(int a[], int left, int right);
void swap(int *x, int *y);
int partition(int a[], int left, int right, int p);

void printarray(char *s, int *a, int n);
void debug(int a[], int left, int right, int p, int center);
int comparearray(int *a, int *b, int n);
int comp(const void *a, const void *b);

// ピボットの値を求める関数(課題1)
int pivot(int a[], int left, int right)
{
  return left;
}

// 配列aのleftからrightまでをピボットpで分割する関数(課題1)
int partition(int a[], int left, int right, int p)
{
  int i=left+1,j=right;
  while(1){
    while(a[i]<a[p]){
      if(i>=right)break;
      i++;
    }
    while(a[j]>a[p]){
      if(left>=j)break;
      j--;
    }
    if(i>=j)break;
    else swap(&a[i],&a[j]);
    //i++;j--;
  }
  if(j==left)return j;
  swap(&a[left],&a[j]);
  return j;
}

// 配列aのleftからrightまでをクィックソートする関数(課題1)
void quick(int a[], int left, int right)
{
  if(right>left){
    int p = pivot(a, left, right);
    int center = partition(a, left, right, p);
  if(center-left>1)
    quick(a, left, center - 1);
  if(right-center>1)
    quick(a, center + 1, right);
    }
}
// xとyを入れ替える関数(必要に応じて使う)
void swap(int *x, int *y)
{
  int t = *x;
  *x = *y;
  *y = t;
}

// 文字列sと長さnの配列aを表示する関数(確認用・必要に応じて使う)
void printarray(char *s, int *a, int n)
{
  int i;
  printf("%s", s);
  for (i = 0; i < n; i++)
    printf("%4d", a[i]);
  printf("\n");
}

// 配列間の比較(確認用・必要に応じて使う)
int comparearray(int *a, int *b, int n)
{
  int i;
  for (i = 0; i < n; i++)
    if (a[i] != b[i])
      return a[i] - b[i];
  return 0;
}

// qsortの補助関数
int comp(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

// デバッグ用の関数(確認用・必要に応じて使う)
void debug(int a[], int left, int right, int p, int center)
{
  int i = 0;
  printf("(%d, %d) pivot: %d, center: %d\n", left, right, p, center);
  for (i = 0; i < N; i++)
  {
    printf("%4d", a[i]);
  }
  printf("\n");
}

int main(void)
{
  int a[N], b[N], c[N];
  int i, cmp;
  clock_t start, end;
  int seed;

  printf("Input a integer: "); //乱数生成用のseed値を取得
  scanf("%d", &seed);
  srand(seed); // 乱数生成のseed値を設定（この値により乱数の生成パターンが決まる）

  for (i = 0; i < N; i++)
  {
    a[i] = rand() % 1000;
    b[i] = a[i];
    c[i] = a[i];
  }

  start = clock();
  quick(a, 0, N - 1);
  end = clock();
  printarray("result: ", a, N);

  qsort(b, N, sizeof(int), comp); // 組み込みライブラリのクイックソートを実行（正解）
  cmp = comparearray(a, b, N);
  if (cmp != 0) //正解の判定
  {
    printf("-- NG --\n");
  }
  else
  {
    printf("-- OK --\n");
  }
  printarray("orig : ", c, N);
  printarray("yours: ", a, N);
  printarray("qsort: ", b, N);

  return 0;
}
