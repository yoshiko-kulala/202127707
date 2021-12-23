#include <stdio.h>
#include <stdlib.h>

const char filename[] = "data.csv";

// ここで構造体の定義を行う
typedef struct{
  // 必要な要素を追加する
  
}private;

// すべてのデータを表示 & 保存する関数を作成
void print_alldata(int num, private *data, const char *filename){
  // 書き込みを行う
  FILE *fp;
}

private *load_data(const char *filename){
  // データを読み込んで，data を更新
  FILE *fp;
  private *data = NULL;

  // 1行目はデータの数

  // メモリ領域の確保
  

  // 2行目以降は
  // 名前,年齢（整数）,身長（実数）, 体重（実数）
  // fscanf ? 

  return data;
}


int main(){

  // データの読み込み
  load_data(filename);
  
  // データのソート(BMIで降順)

  // データの表示

  // データのソート（名前で昇順）


  // データの表示


  // データの解放

  return 0;
}
