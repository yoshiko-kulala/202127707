// 問題：与えられた変数に対して，値を交換する
// swap_int, swap_double を作成せよ
// また，それぞれの変数にに適切に値が交換されていることを確認せよ


#include <stdio.h>
#include <stdlib.h>

void swap_int(int *p1,int *p2){
  *p1 = *p2 - *p1;
  *p2 -= *p1;
  *p1 += *p2;
}

void swap_double(double *p1, double *p2){
  *p1 = *p2 - *p1;
  *p2 -= *p1;
  *p1 += *p2;
}

int main(){
  int i1=10, i2=30;
  double d1 = 10.0, d2 = 30.5;

  // set_int を用いて i1 に i2 を代入せよ
  // i1 へ i2 を代入できるよう適切に引数を与えること
  // コメントアウトを外し，適切に記述すること
  swap_int(&i1,&i2); 
  printf("i1 = %d, i2 = %d\n",i1, i2);

  // set_double を用いて d1 に d2 を代入せよ
  // d1 へ d2 を代入できるよう適切に引数を与えること
  // コメントアウトを外し，適切に記述すること
  swap_double(&d1,&d2); 
  printf("d1 = %f, d2 = %f\n",d1, d2);

  return 0;
}
