/* �\���̂̃����o�ɒl��������֐� */

/* ==================== ��� ==================== */
/*
  �L�[�{�[�h�����͂��ꂽ�l���\���� xyz �ɑ������֐�
  set_xyz ������������D
  
  �֐��̉������Ƃ��āC�\���̂̃|�C���^���^�����Ă��邱�Ƃ�
  ���ӂ��邱��
*/
/* ======================================== */


#include <stdio.h>

struct xyz{		/* xyz�̓^�O�� */
  /* �����o */	
  int x;
  long y;
  double z;
};

/* p���w���\����xyz�ɒl���� */
void set_xyz(struct xyz *p, int x, long y, double z)
{
  //
  /* (* �����ɉ𓚂����������� *) */
	p->x=x;
	p->y=y;
	p->z=z;
}

int main(void)
{
  /* sa��struct xyz�^�̃I�u�W�F�N�g */
  struct xyz sa;
	
  int x=0;
  long y=0;
  double z=0.f;

  /* �l�̑��*/	
  scanf("%d",&x);
  scanf("%ld",&y);
  scanf("%lf",&z);
	
  set_xyz(&sa,x,y,z);
  /* �����o�̒l��\�� */
  printf("sa.x = %d\n", sa.x);
  printf("sa.y = %ld\n", sa.y);
  printf("sa.z = %f\n", sa.z);
	
  return (0);
}
