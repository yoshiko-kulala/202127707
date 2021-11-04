// ���F�^����ꂽ�ϐ��ɑ΂��āC�l����������
// swap_int, swap_double ���쐬����
// �܂��C���ꂼ��̕ϐ��ɂɓK�؂ɒl����������Ă��邱�Ƃ��m�F����


#include <stdio.h>
#include <stdlib.h>

void swap_int(int *p1,int *p2){
  *p1 = *p2 - *p1;
  *p2 -= *p1;
  *p1 += *p2;
}

void swap_double(double *p1, double *p2){
  *p1 = *p2 - *p1;
  *p2 -= *p1;
  *p1 += *p2;
}

int main(){
  int i1=10, i2=30;
  double d1 = 10.0, d2 = 30.5;

  // set_int ��p���� i1 �� i2 ��������
  // i1 �� i2 �����ł���悤�K�؂Ɉ�����^���邱��
  // �R�����g�A�E�g���O���C�K�؂ɋL�q���邱��
  swap_int(&i1,&i2); 
  printf("i1 = %d, i2 = %d\n",i1, i2);

  // set_double ��p���� d1 �� d2 ��������
  // d1 �� d2 �����ł���悤�K�؂Ɉ�����^���邱��
  // �R�����g�A�E�g���O���C�K�؂ɋL�q���邱��
  swap_double(&d1,&d2); 
  printf("d1 = %f, d2 = %f\n",d1, d2);

  return 0;
}
