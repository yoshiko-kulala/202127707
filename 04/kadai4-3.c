/* ������̔�r */

/* 
   ��蕶�F
   string.h�Ő錾����Ă���֐�strcmp�́C2�̕�����s1��s2���r���Ă�
   ���C�قȂ镶�����o�������ꍇ�ɂ����̕����̑΂ɐ�������召�֌W��
   ��r����֐��ł���D

   ���̊֐�strcmp�ɏ����āC������s1��s2�̔�r���s���C�����񂪓��������0
   ���C�قȂ镶�������݂���΁C���̕����R�[�h�̍���l�Ƃ��ĕԂ��֐�
   str_cmp���쐬����D
*/



#include <stdio.h>
#include <string.h>

/*
  str_cmp���쐬����D
*/


/*--- ��̕�����s1��s2���r ---*/


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

  puts("\"ABCD\"�Ƃ̔�r���s���܂��B");
  puts("\"XXXX\"�ŏI�����܂��B");

  while (1) {
    printf("������st�F");
    scanf("%s", st);

    if (strcmp("XXXX", st) == 0)
      break;
    printf("str_cmp(\"ABCD\", st) = %d\n", str_cmp("ABCD", st));
  }

  return 0;
}
