#include <stdio.h>

/*
  ��蕶�F
  ������from�̓��e�𕶎���to�ɃR�s�[����֐�mystrcpy�����������Ȃ����D
*/



/*
  mystrcpy������������D
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

  printf("������̓���:");
  scanf("%s",source);

  mystrcpy(str, source);

  printf("����:%s �R�s�[:%s", source, str);

  return 0;
}