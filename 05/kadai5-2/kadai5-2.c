#include <stdio.h>
#include <string.h>

/* 問題

   教科書のList13-2(身長と体重を読み込んで平均値を求めて表示する)を参考に, 
   ファイルから読み込んだ個人データを体重順にソート(昇順)した上で表示する
   プログラムを作成する. 

   (注: 数字の場合，昇順とは小さい順にならべること．)

   データ形式は，名前(60文字以内) 身長(double型) 体重(double型) になっている．
   例)
   Taro 170.0 70.2
   Jiro 158.0 80.5

*/

/* Step
   1. ファイルをオープンし, 個人データを読み込む.
   2. 個人データのうち, 体重順にソートを行う(昇順).
*/


/* 個人データ */
typedef struct{
  char name[100];
  double height;
  double weight;
}member;

/* 構造体を交換する関数 */
//
/* (* ここに解答を書き加える *) */
void swap_ma(member *p1,member *p2){
	member tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void sort_ma(member m[],int i){
	int cou,subcou;
	for(cou=i-1;cou>0;cou--){
		for(subcou=cou;subcou>0;subcou--){
			if(m[subcou].weight < m[subcou-1].weight){
				swap_ma(&m[subcou],&m[subcou-1]);
			}
		}
	}
}

int main(void)
{
  FILE *fp;
  member ma[10];
    
  char str[10];
  int i = 0;
    
  char filename[60];
    
  printf("ファイル名 :"); scanf("%s",filename);
    
  //ファイルを開く
  //ファイルがオープンできなかったらtrueとなる
  //
  if((fp = fopen(filename,"r"))==NULL){
    /* (* ここに解答を書き加える *) */
    
    printf("ファイルをオープンできません。\n");
    return 1;
  }else{
    //ファイルがオープンできた時の処理
    int j;
    int k;
    while(fscanf(fp, "%s%lf%lf",ma[i].name,&(ma[i].height),&(ma[i].weight)) == 3){
      printf("%-10s %5.1f %5.1f\n",ma[i].name,ma[i].height,ma[i].weight);
      i++;
    }
    j=i;
    //ソートを行う
    //
    /* (* ここに解答を書き加える *) */
    /* ソートのアルゴリズムについては以前の課題参照 */
    sort_ma(ma,j);
    
    //ソート結果を表示
    printf("----------SortResult----------\n");
    for(i=0;i<j;i++)
      printf("%-10s %5.1f %5.1f\n",ma[i].name,ma[i].height,ma[i].weight);
    fclose(fp);
  }
  
  return (0);
}
