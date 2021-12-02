// main 文を含む本文である．
// 必要なファイルをインクルードするとともに関数内に記述を行い
// main を完成させよ

#include <stdio.h>
#include "studata.h"

int main(){
  int num;
  // 必要な変数があれば追加すること．
  studata *data;

  // load_studata を用いてファイルの情報を読み込む
  // 読み込むファイルは data.csv である．
  // 適切に書き換えよ
  data = load_studata("data.csv",&num);
  
  // 内容を表示し，適切にデータが読み込めているか確認せよ
  printf("load_data-------------------------------\n");
	print_studata(data,num);
  // 身長でソートした後，表示させよ
	sor_by_height(num,data);
	
  printf("\nheight_sort_data-------------------------------\n");
	print_studata(data,num);

  // 名前でソートした後，表示させよ
  sort_by_name(num,data);
	
  printf("\nname_sort_data-------------------------------\n");
	print_studata(data,num);
  
  return 0;
}
