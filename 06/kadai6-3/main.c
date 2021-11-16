// Queue を用いてキーボードからの入力を記録・再現するプログラムを作成せよ．

#include <stdio.h>
#include "queue.h"
// キーボードから10個の数字を入力し，その入力した数字をStackに格納した後，
// 順番に取り出しながら表示を行うプログラムを作成せよ．
// 例えば1-10の数字を順番に入力したとすれば，その順に数字が表示されることになる．
// 必要があれば処理を追加せよ．

int main() {
  Queue *q;
  int i;
  int key;
  int num = 0;
  
  // queue の初期化
  QueueAlloc(q, 10);

  // キーボードから入力する数を入力
  printf("input num?:");
  scanf("%d", &num);

  for (i = 0; i < num; i++) {
    printf("Input number");
    // 入力を受け取る．
    scanf("%d", &key);
    QueueEnqueue(q, key);
    // queueに格納する
  }


  while (QueueIsEmpty(q) == 0) {
    // queueから順番に数字を取り出して表示する．
    QueueDequeu(q, &key);
    printf("%d\n", key);
    // queueの中身が空となったら終了
  }
  QueueFree(q);
  return 0;
}
