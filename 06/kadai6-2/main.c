// stack.c �ɋL�q�������e��p���āCStack �����������삷�邩���m�F����D
// �L�[�{�[�h����10�̐�������͂��C���̓��͂���������Stack�Ɋi�[������C
// ���ԂɎ��o���Ȃ���\�����s���v���O�������쐬����D
// �Ⴆ��1-10�̐��������Ԃɓ��͂����Ƃ���΁C���̋t���ɐ������\������邱�ƂɂȂ�D

#include <stdio.h>


// stack.c�ɋL�q���ꂽ�֐����g�p����ۂɕK�v�Ȃ��̂��L�q����D
#include "stack.h"



int main(){
  Stack stk;
  int i;
  int key;
  int num=0;


  // stack �̏�����
	StackAlloc(&stk,10);

  // �L�[�{�[�h������͂��鐔�����
  printf("input num?:");
  scanf("%d",&num);

  for (i=0;i<num;i++){
    printf("Input number");
    // ���͂��󂯎��D
    scanf("%d",&key);
	StackPush(&stk, key);
    // �X�^�b�N�Ɋi�[����
  }
  

  while(StackIsEmpty(&stk)==0){
    // �X�^�b�N���珇�Ԃɐ��������o���ĕ\������D
	StackPop(&stk,&key);
	printf("%d\n",key);
    // �X�^�b�N�̒��g����ƂȂ�����I��
  }
	StackFree(&stk);
  return 0;
}
