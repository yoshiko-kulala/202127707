#include <stdio.h>

/*
��蕶�F
������str�̒��ɁA����moji���܂܂�Ă����(�������݂���ꍇ�́A�ł��擪
���Ƃ���)�A���̓Y������Ԃ��A�܂܂�Ă��Ȃ����-1��Ԃ��֐�
   int str_char(const char str[],int moji) {}
���쐬����B
*/



/*
  step1

  ������str�̒��ɁA����moji���܂܂�Ă����(�������݂���ꍇ�́A�ł���
  �����Ƃ���)�A���̓Y������Ԃ��A�܂܂�Ă��Ȃ����-1��Ԃ��֐�
  str_char()���쐬����B
*/

/*
  step2

  STEP1�ō쐬�����֐���p���A�W�����͂����͂����������p�����̉��Ԗ�
  �ł��邩���ʂ��o�͂���B
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
	
  printf("�p��������͂��Ă��������@�F");
  scanf("%s",ch);
	
  no = str_char("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",ch[0]);
	
  if(no >= 0 && no <= 25)
    printf("����͉p�啶����%d�Ԗڂł��B\n",no+1);
  else if (no >= 26 && no <= 51)
    printf("����͉p��������%d�Ԗڂł��B\n",no-25);
  else 
    printf("����͉p�����ł͂���܂���");
  return(0);
}
