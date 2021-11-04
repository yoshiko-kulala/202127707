/* 文字列の比較 */

/* 
   問題文：
   string.hで宣言されている関数strcmpは，2つの文字列s1とs2を比較してい
   き，異なる文字が出現した場合にそれらの文字の対に成立する大小関係を
   比較する関数である．

   この関数strcmpに準じて，文字列s1とs2の比較を行い，文字列が等しければ0
   を，異なる文字が存在すれば，その文字コードの差を値として返す関数
   str_cmpを作成せよ．
*/



#include <stdio.h>
#include <string.h>

/*
  str_cmpを作成する．
*/


/*--- 二つの文字列s1とs2を比較 ---*/


int str_cmp(const char *s1, const char *s2)
{
	int i;
	for(i=0;s1[i]!='\0';i++){
		if(s1[i]!=s2[i])return s1[i]-s2[i];
	}
	return 0;
}

int main(void)
{
  char st[128];

  puts("\"ABCD\"との比較を行います。");
  puts("\"XXXX\"で終了します。");

  while (1) {
    printf("文字列st：");
    scanf("%s", st);

    if (strcmp("XXXX", st) == 0)
      break;
    printf("str_cmp(\"ABCD\", st) = %d\n", str_cmp("ABCD", st));
  }

  return 0;
}
