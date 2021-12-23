#include <stdlib.h>
#include <stdio.h>

int comp1(const void *p, const void *q){
  int a, b;
  // ��U int * �ւƕϊ����Ēl���擾
  // �\���̂̏ꍇ���K�������̍\���̂ւƃL���X�g
  a = *(int *)p;
  b = *(int *)q;

  if (a > b) return -1;
  if (a < b) return 1;
  return 0;
}

int comp2(const void *p, const void *q){
  int a, b;
  // ��U int * �ւƕϊ����Ēl���擾
  // �\���̂̏ꍇ���K�������̍\���̂ւƃL���X�g
  a = *(int *)p;
  b = *(int *)q;

  if (a > b) return 1;
  if (a < b) return -1;
  return 0;
}


int main(){
  int data[10] = {0,1,2,3,4,5,6,7,8,9};
  int i;

  // comp1 ���g���ă\�[�g
  qsort(data, 10, sizeof(int), comp1);
  printf("comp1:\n");
  for (i=0;i<10;i++)
    printf("%d ", data[i]);
  putchar('\n');
  
  // comp2 ���g���ă\�[�g
  qsort(data, 10, sizeof(int), comp2);
  printf("comp2:\n");
  for (i=0;i<10;i++)
    printf("%d ", data[i]);
  putchar('\n');
  
  return 0;
}
