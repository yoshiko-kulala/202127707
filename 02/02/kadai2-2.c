#include <time.h>
#include <stdio.h>

/*--- ���݂̔N�����ƌߑO���ߌォ��\������ ---*/

/* ==================== ��� ==================== */

/* 
   ���݂̓����ƌߑO�ߌ�̂����ꂩ��\��������v���O������
   �쐬����

   �Ⴆ�΁C
   2019�N10��10��19:00�ł����
   2019/10/10 A.M.
   2032�N11��11��01:00�ł����
   2031/11/11 P.M.
   �̂悤�ɕ\�����邱��

   �Ȃ��C���ݎ������擾����֐��ɂ��Ă͍u�`�������m�F���邱��
*/



void put_time(void)
{
  //
  /* (* �����ɉ𓚂����������� *) */
	time_t current;
	struct tm *local;
	time(&current);
	local = Localtime(&current);
	printf("%4d/%02d/%02 ",local->tm_year+1900,local->tm_mon+1local->tm_mday);
	if(local->tm_hour>12)printf("P.M.\n");
	else printf("A.M.\n");
}

int main(void)
{
  printf("���݂�");
  put_time();
  printf("�ł�\n");

  return(0);
}
