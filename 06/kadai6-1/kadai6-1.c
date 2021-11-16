/* 
   指定した個数だけint型の整数をデータとして入力し，
   入力データのうちの正数の個数とその和，
   負数の個数とその和を返すプログラムを作成する．
   入力データは，callocを用いて確保したメモリ領域に入力すること．
   例えば，入力データ数を4とし，1，3，0，-2を入力したとすると，
   正数の個数は2個，正数の和は4となる．
   そして，負数の個数は1個，負数の和は-2となる．

   STEP
   1. callocを用いて，入力データ数分のメモリを動的に確保する．
   2. 標準入力より入力したデータの正数の個数とその和，負数の個数とその和を出力する．
   3. 動的に確保したメモリを開放する．
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *data;
  int *startPos; // データの初めのアドレスを覚えておく
  int num;
  int i;
  int sum_p; // 正数の和
  int sum_n; // 負数の和
  int count_p; // 正数の個数
  int count_n; // 負数の個数

  printf( "入力するデータ数を入力して下さい。>" );
  scanf( "%d", &num );

  //
  // (* ここに解答を書き加える *) 
	data = calloc(num,sizeof(int));

    startPos = data;

  /* データの入力 */
  for( i = 0; i < num; i++ ){
    printf( "\n%i番目のデータを入力して下さい。>", i+1 );
    scanf( "%d", data );
    data++;
  }

  /* 変数初期化 */
  data = startPos;
  sum_p = 0;
  count_p = 0;
  sum_n = 0;
  count_n = 0;

  /* データの出力 */
  //
  //(* ここに解答を書き加える *)
	for(;data<startPos+num;data++){
		if(*data>0){
			count_p++;
			sum_p=sum_p+*data;
		}
		if(*data<0){
			count_n++;
			sum_n=sum_n+*data;
		}
	}

  printf( "正数の個数は %d 個、合計は %d です。\n", count_p, sum_p );
  printf( "負数の個数は %d 個、合計は %d です。\n", count_n, sum_n );

  //
  //(* ここに解答を書き加える *)
	free(data);

    return 1;
}
