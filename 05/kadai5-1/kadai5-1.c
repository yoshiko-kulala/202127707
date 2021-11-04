//ファイル内の文字のうち，アルファベットだけカウントする

// 問題

/* 
ファイルから読み込んだ文字のうち，小文字と大文字のアルファベットのみを
カウントして表示するプログラムを作成しなさい．
*/

// step
/*
  1 変数filenameに格納されたファイルのオープン処理を行う。

  2 ファイルから1文字ずつ読み込んでアルファベットかどうか調べてアルファ
  ベットであればカウントする。
*/

#include <stdio.h>

int main(void){
  FILE	*fp;
  int		ch;
  char filename[60];
	
  int		count = 0;
  scanf("%s",filename);

  printf("入力ファイル名：%s\n",filename);
  //ファイルオープン処理
  //
  /* (* ここに解答を書き加える *) */
  if((fp = fopen(filename,"r"))==NULL){
    printf("Cannot open %s\n", filename);
    return 0;
  }
  //文字数カウント処理
  //
  /* (* ここに解答を書き加える *) */
	while((ch=fgetc(fp))!=EOF){
		if((ch>='A' && ch<='Z')||ch>='a' && ch<='z')count++;
	}
  printf("Number of Alphabet in %s is %d \n", filename, count);
  fclose(fp);
	
  return 0;
}
