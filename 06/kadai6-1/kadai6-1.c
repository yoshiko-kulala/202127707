/* 
   �w�肵��������int�^�̐������f�[�^�Ƃ��ē��͂��C
   ���̓f�[�^�̂����̐����̌��Ƃ��̘a�C
   �����̌��Ƃ��̘a��Ԃ��v���O�������쐬����D
   ���̓f�[�^�́Ccalloc��p���Ċm�ۂ����������̈�ɓ��͂��邱�ƁD
   �Ⴆ�΁C���̓f�[�^����4�Ƃ��C1�C3�C0�C-2����͂����Ƃ���ƁC
   �����̌���2�C�����̘a��4�ƂȂ�D
   �����āC�����̌���1�C�����̘a��-2�ƂȂ�D

   STEP
   1. calloc��p���āC���̓f�[�^�����̃������𓮓I�Ɋm�ۂ���D
   2. �W�����͂����͂����f�[�^�̐����̌��Ƃ��̘a�C�����̌��Ƃ��̘a���o�͂���D
   3. ���I�Ɋm�ۂ������������J������D
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *data;
  int *startPos; // �f�[�^�̏��߂̃A�h���X���o���Ă���
  int num;
  int i;
  int sum_p; // �����̘a
  int sum_n; // �����̘a
  int count_p; // �����̌�
  int count_n; // �����̌�

  printf( "���͂���f�[�^������͂��ĉ������B>" );
  scanf( "%d", &num );

  //
  // (* �����ɉ𓚂����������� *) 
	data = calloc(num,sizeof(int));

    startPos = data;

  /* �f�[�^�̓��� */
  for( i = 0; i < num; i++ ){
    printf( "\n%i�Ԗڂ̃f�[�^����͂��ĉ������B>", i+1 );
    scanf( "%d", data );
    data++;
  }

  /* �ϐ������� */
  data = startPos;
  sum_p = 0;
  count_p = 0;
  sum_n = 0;
  count_n = 0;

  /* �f�[�^�̏o�� */
  //
  //(* �����ɉ𓚂����������� *)
	for(;data<startPos+num;data++){
		if(*data>0){
			count_p++;
			sum_p=sum_p+*data;
		}
		if(*data<0){
			count_n++;
			sum_n=sum_n+*data;
		}
	}

  printf( "�����̌��� %d �A���v�� %d �ł��B\n", count_p, sum_p );
  printf( "�����̌��� %d �A���v�� %d �ł��B\n", count_n, sum_n );

  //
  //(* �����ɉ𓚂����������� *)
	free(data);

    return 1;
}
