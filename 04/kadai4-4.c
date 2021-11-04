/* 
   問題文：

   入力された文字列から2つの連続した文字を検索する関数str_2chrを
   以下の指定に従って作成しなさい。

   関数str_2chrは最初の文字がある位置の添え字をint型で返し、
   第1引数として検索する文字列を示すchar型配列を、
   第2引数として探す2つの文字の1文字目を示すchar型変数を、
   第3引数として探す2つの文字の2文字目を示すchar型変数を、
   第4引数として文字列の最大の長さを示すint型変数を使用すること。

   なお、関数str_2chrは探す2つの文字が文字列中に存在しなければ-1を返し、
   複数存在する場合は、最も先頭側の添え字を返すとする。
   以下の実行例を参考とすること。

   実行例：
   文字列を入力して下さい：Stringring
   探したい2文字の単語を入力します
   1文字目：r
   2文字目：i
   2文字の単語'ri'は文字列の3文字目と4文字目に存在します。

   また、関数str_2chr以外のプログラムは、
   問題プログラムに表示されているものを使用すること。
*/


/*
  step 1
  入力された文字列から2つの連続した文字を検索する関数str_2chr定義する
*/

/*
  step2
  STEP1で定義した関数を用いて、標準入力より入力した文字列中に2文字の単
  語があるか検索を行い、単語があるならば存在する位置を表示し、単語がな
  いならば単語が存在しないということを表示する
*/


#include <stdio.h>

#define MAX_STR_LEN 60	/* 最大文字列長 */

/* 以下に、文字列から2つの連続する文字を検索する関数を定義する */
//

// (* ここに解答を書き加える *)
int str_2chr(const char *moto,char char1,char char2,int len){
	int i;
	for(i=0;i<len-1;i++){
		if(moto[i]==char1&&moto[i+1]==char2)return i;
	}
	return -1;
}

int main(void)
{
  char str[MAX_STR_LEN];	/* 検査対象文字列 */
  char tmp[MAX_STR_LEN];	/* 一時的に単語を格納する */
  char first_char;	/* 1文字目 */
  char second_char;	/* 2文字目 */
  int idx;	/* 文字列のインデックス */
	
  printf("文字列を入力して下さい：");
  scanf("%s", str);
	
  /* 探したい文字を一旦文字列tmpに格納してから取り出す */
  printf("探したい2文字の単語を入力します\n");
  printf("1文字目：");
  scanf("%s", tmp);
  first_char = tmp[0];
  printf("2文字目：");
  scanf("%s", tmp);
  second_char = tmp[0];
	
  if ((idx = str_2chr(str, first_char, second_char, MAX_STR_LEN)) == -1){
    printf("2文字の単語'%c%c'は", first_char, second_char);
    printf("文字列中に存在しません。\n");
  }
  else{
    printf("2文字の単語'%c%c'は", first_char, second_char);
    printf("文字列の%d文字目と%d文字目に存在します。\n", idx + 1, idx + 2);
  }

  return (0);
}
