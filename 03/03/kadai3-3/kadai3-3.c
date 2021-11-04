#include<stdio.h>
// 問題：n 個の配列の先頭を示すポインタが与えられた時
// その配列を降順に並べ替える関数 bubble_sort を完成させよ．
// また，配列に値を代入するための関数
// setarrayを完成させよ．


/*--- nx・nyが指すオブジェクトの値を交換 ---*/
void swap(int *nx, int *ny)
{
  int temp = *nx;
  *nx = *ny;
  *ny = temp;
}

void setarray(int *vc,int a,int b,int c,int d,int e)
{
  //
  //(* ここに解答を書き加える *)
  // 1番目にはa, 2番目にはb と順番になるように入力すること
	vc[0]=a;vc[1]=b;vc[2]=c;vc[3]=d;vc[4]=e;
}

void bubble_sort(int *data, int n){
  //
  //(* ここに解答を書き加える *)
  // data[0] > data [1] > ... > data[4]
  // 配列のソートは，前回用いたアルゴリズムをそのまま使用してよい．
	if(n==1)return;
	else{
		for(int i=0;i<n-1;i++){
			if(data[i]>data[i+1])
			swap(&data[i],&data[i+1]);
		}
	}
	bubble_sort(data,n-1);
}

int main(void)
{
  int i,a,b,c,d,e;
  int ary[5] = {0};

  printf("配列に代入する整数を5つ入力してください\n");
  printf("整数1："); 
  scanf("%d",&a);
  printf("整数2：");
  scanf("%d",&b);
  printf("整数3：");
  scanf("%d",&c);
  printf("整数4：");
  scanf("%d",&d);
  printf("整数5：");
  scanf("%d",&e);
  putchar('\n');

  setarray(ary,a,b,c,d,e);

  for(i=0;i<5;i++)
    printf("ary[%d] = %d\n",i,ary[i]);

  bubble_sort(ary,5);
  printf ("\nbabble sort!\n");
  for(i=0;i<5;i++)
    printf("ary[%d] = %d\n",i,ary[i]);

  return (0);
}

