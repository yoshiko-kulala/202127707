#include <stdlib.h>
#include <stdio.h>

int comp1(const void *p, const void *q){
  int a, b;
  // 一旦 int * へと変換して値を取得
  // 構造体の場合も必ず何かの構造体へとキャスト
  a = *(int *)p;
  b = *(int *)q;

  if (a > b) return -1;
  if (a < b) return 1;
  return 0;
}

int comp2(const void *p, const void *q){
  int a, b;
  // 一旦 int * へと変換して値を取得
  // 構造体の場合も必ず何かの構造体へとキャスト
  a = *(int *)p;
  b = *(int *)q;

  if (a > b) return 1;
  if (a < b) return -1;
  return 0;
}


int main(){
  int data[10] = {0,1,2,3,4,5,6,7,8,9};
  int i;

  // comp1 を使ってソート
  qsort(data, 10, sizeof(int), comp1);
  printf("comp1:\n");
  for (i=0;i<10;i++)
    printf("%d ", data[i]);
  putchar('\n');
  
  // comp2 を使ってソート
  qsort(data, 10, sizeof(int), comp2);
  printf("comp2:\n");
  for (i=0;i<10;i++)
    printf("%d ", data[i]);
  putchar('\n');
  
  return 0;
}
