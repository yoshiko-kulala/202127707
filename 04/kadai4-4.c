/* 
   ��蕶�F

   ���͂��ꂽ�����񂩂�2�̘A��������������������֐�str_2chr��
   �ȉ��̎w��ɏ]���č쐬���Ȃ����B

   �֐�str_2chr�͍ŏ��̕���������ʒu�̓Y������int�^�ŕԂ��A
   ��1�����Ƃ��Č������镶���������char�^�z����A
   ��2�����Ƃ��ĒT��2�̕�����1�����ڂ�����char�^�ϐ����A
   ��3�����Ƃ��ĒT��2�̕�����2�����ڂ�����char�^�ϐ����A
   ��4�����Ƃ��ĕ�����̍ő�̒���������int�^�ϐ����g�p���邱�ƁB

   �Ȃ��A�֐�str_2chr�͒T��2�̕����������񒆂ɑ��݂��Ȃ����-1��Ԃ��A
   �������݂���ꍇ�́A�ł��擪���̓Y������Ԃ��Ƃ���B
   �ȉ��̎��s����Q�l�Ƃ��邱�ƁB

   ���s��F
   ���������͂��ĉ������FStringring
   �T������2�����̒P�����͂��܂�
   1�����ځFr
   2�����ځFi
   2�����̒P��'ri'�͕������3�����ڂ�4�����ڂɑ��݂��܂��B

   �܂��A�֐�str_2chr�ȊO�̃v���O�����́A
   ���v���O�����ɕ\������Ă�����̂��g�p���邱�ƁB
*/


/*
  step 1
  ���͂��ꂽ�����񂩂�2�̘A��������������������֐�str_2chr��`����
*/

/*
  step2
  STEP1�Œ�`�����֐���p���āA�W�����͂����͂��������񒆂�2�����̒P
  �ꂪ���邩�������s���A�P�ꂪ����Ȃ�Α��݂���ʒu��\�����A�P�ꂪ��
  ���Ȃ�ΒP�ꂪ���݂��Ȃ��Ƃ������Ƃ�\������
*/


#include <stdio.h>

#define MAX_STR_LEN 60	/* �ő啶���� */

/* �ȉ��ɁA�����񂩂�2�̘A�����镶������������֐����`���� */
//

// (* �����ɉ𓚂����������� *)
int str_2chr(const char *moto,char char1,char char2,int len){
	int i;
	for(i=0;i<len-1;i++){
		if(moto[i]==char1&&moto[i+1]==char2)return i;
	}
	return -1;
}

int main(void)
{
  char str[MAX_STR_LEN];	/* �����Ώە����� */
  char tmp[MAX_STR_LEN];	/* �ꎞ�I�ɒP����i�[���� */
  char first_char;	/* 1������ */
  char second_char;	/* 2������ */
  int idx;	/* ������̃C���f�b�N�X */
	
  printf("���������͂��ĉ������F");
  scanf("%s", str);
	
  /* �T��������������U������tmp�Ɋi�[���Ă�����o�� */
  printf("�T������2�����̒P�����͂��܂�\n");
  printf("1�����ځF");
  scanf("%s", tmp);
  first_char = tmp[0];
  printf("2�����ځF");
  scanf("%s", tmp);
  second_char = tmp[0];
	
  if ((idx = str_2chr(str, first_char, second_char, MAX_STR_LEN)) == -1){
    printf("2�����̒P��'%c%c'��", first_char, second_char);
    printf("�����񒆂ɑ��݂��܂���B\n");
  }
  else{
    printf("2�����̒P��'%c%c'��", first_char, second_char);
    printf("�������%d�����ڂ�%d�����ڂɑ��݂��܂��B\n", idx + 1, idx + 2);
  }

  return (0);
}
