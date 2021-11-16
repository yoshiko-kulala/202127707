// �L���[�𗘗p���邽�߂̃v���O�������쐬����

typedef struct{
  int max;		//�L���[�̃T�C�Y
  int num;		//���݂̗v�f��
  int front;	//�擪�v�f�J�[�\��
  int rear;		//�����v�f�J�[�\��
  int *que;		//�L���[�̐擪�v�f�ւ̃|�C���^
}Queue;


// �ȉ��C�K�v�Ȃ��̂��L�q����D

int QueueAlloc(Queue *q, int max);

void QueueFree(Queue *q);

int QueueEnqueue(Queue *q, int x);

int QueueDequeu(Queue *q, int *x);

int QueueSize(const Queue *q);

int QueueNo(const Queue *q);

int QueueIsEmpty(const Queue *q);

int QueueIsFull(const Queue *q);