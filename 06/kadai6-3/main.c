// Queue ��p���ăL�[�{�[�h����̓��͂��L�^�E�Č�����v���O�������쐬����D

#include <stdio.h>
#include "queue.h"
// �L�[�{�[�h����10�̐�������͂��C���̓��͂���������Stack�Ɋi�[������C
// ���ԂɎ��o���Ȃ���\�����s���v���O�������쐬����D
// �Ⴆ��1-10�̐��������Ԃɓ��͂����Ƃ���΁C���̏��ɐ������\������邱�ƂɂȂ�D
// �K�v������Ώ�����ǉ�����D

int main() {
  Queue *q;
  int i;
  int key;
  int num = 0;
  
  // queue �̏�����
  QueueAlloc(q, 10);

  // �L�[�{�[�h������͂��鐔�����
  printf("input num?:");
  scanf("%d", &num);

  for (i = 0; i < num; i++) {
    printf("Input number");
    // ���͂��󂯎��D
    scanf("%d", &key);
    QueueEnqueue(q, key);
    // queue�Ɋi�[����
  }


  while (QueueIsEmpty(q) == 0) {
    // queue���珇�Ԃɐ��������o���ĕ\������D
    QueueDequeu(q, &key);
    printf("%d\n", key);
    // queue�̒��g����ƂȂ�����I��
  }
  QueueFree(q);
  return 0;
}
