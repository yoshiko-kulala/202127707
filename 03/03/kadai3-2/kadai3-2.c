// 3 つの整数が与えられたとき，昇順に並べ替える関数 sort を作成せよ
// このとき，3つの整数はポインタの形で与えられるものとする．

// また，これを実行するために，２つの変数を入れ替える関数 swap を
// 作成し，sort には必ずこれを利用すること
// (swapは課題1のものと同じであるが，sortには値ではなく，
// ポインタが与えられることに注意すること)

#include <stdio.h>


/*--- nx・nyが指すオブジェクトの値を交換 ---*/
void swap(int *nx, int *ny)
{
  *nx = *ny - *nx;
  *ny -= *nx;
  *nx += *ny;
}

/*--- *n1≦*n2≦*n3となるように並びかえる ---*/
//
// (* ここにsortに関する記述を書き加えること *//
void sort3(int *x, int *y, int *z){
	if(*x > *y) swap(x, y);
	if(*y > *z) swap(y, z);
	if(*x > *y) swap(x, y);
}

int main(void)
{
	int na,nb,nc;
	puts("三つの整数を入力してください。");
	printf("整数A:");	scanf("%d",&na);
	printf("整数B:");	scanf("%d",&nb);
	printf("整数C:");	scanf("%d",&nc);

	sort3(&na, &nb, &nc);
	
	puts("これらの値を昇順に並べかえました。");
	printf("整数Aは%dです。\n",na);
	printf("整数Bは%dです。\n",nb);
	printf("整数Cは%dです。\n",nc);
	return 0;
}

