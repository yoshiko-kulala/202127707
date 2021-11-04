#include <stdio.h>

/*
問題文：
文字列strの中に、文字mojiが含まれていれば(複数存在する場合は、最も先頭
側とする)、その添え字を返し、含まれていなければ-1を返す関数
   int str_char(const char str[],int moji) {}
を作成せよ。
*/



/*
  step1

  文字列strの中に、文字mojiが含まれていれば(複数存在する場合は、最も先
  頭側とする)、その添え字を返し、含まれていなければ-1を返す関数
  str_char()を作成する。
*/

/*
  step2

  STEP1で作成した関数を用い、標準入力より入力した文字が英文字の何番目
  であるか結果を出力する。
*/

									       
int str_char(const char str[],int moji)
{
	int i=0;
	for(i=0;i<52;i++){
		if(moji==str[i])return i;
	}
	return -1;
}
int main(void)
{
  int no;
  char ch[10];
	
  printf("英文字を入力してください　：");
  scanf("%s",ch);
	
  no = str_char("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",ch[0]);
	
  if(no >= 0 && no <= 25)
    printf("それは英大文字の%d番目です。\n",no+1);
  else if (no >= 26 && no <= 51)
    printf("それは英小文字の%d番目です。\n",no-25);
  else 
    printf("それは英文字ではありません");
  return(0);
}
