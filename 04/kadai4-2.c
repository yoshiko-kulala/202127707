#include <stdio.h>

/*
  問題文：
  文字列fromの内容を文字列toにコピーする関数mystrcpyを完成させなさい．
*/



/*
  mystrcpyを完成させる．
*/


void mystrcpy(char *to, const char *from){
	int i=0;
	for(i=0;from[i]!='\0';i++){
		to[i]=from[i];
	}
}

int main(void)
{
  char *p, str[80],source[80];

  printf("文字列の入力:");
  scanf("%s",source);

  mystrcpy(str, source);

  printf("入力:%s コピー:%s", source, str);

  return 0;
}