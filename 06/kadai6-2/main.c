// stack.c に記述した内容を用いて，Stack が正しく動作するかを確認せよ．
// キーボードから10個の数字を入力し，その入力した数字をStackに格納した後，
// 順番に取り出しながら表示を行うプログラムを作成せよ．
// 例えば1-10の数字を順番に入力したとすれば，その逆順に数字が表示されることになる．

#include <stdio.h>


// stack.cに記述された関数を使用する際に必要なものを記述せよ．
#include "stack.h"



int main(){
  Stack stk;
  int i;
  int key;
  int num=0;


  // stack の初期化
	StackAlloc(&stk,10);

  // キーボードから入力する数を入力
  printf("input num?:");
  scanf("%d",&num);

  for (i=0;i<num;i++){
    printf("Input number");
    // 入力を受け取る．
    scanf("%d",&key);
	StackPush(&stk, key);
    // スタックに格納する
  }
  

  while(StackIsEmpty(&stk)==0){
    // スタックから順番に数字を取り出して表示する．
	StackPop(&stk,&key);
	printf("%d\n",key);
    // スタックの中身が空となったら終了
  }
	StackFree(&stk);
  return 0;
}
