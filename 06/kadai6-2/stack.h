// stack.c ���g�p���邽�߂ɕK�v�ȏ����L�q���邱��

// Stack �Ɏg�p����\����
typedef struct{
  int max;	//�X�^�b�N�T�C�Y
  int ptr;	//�X�^�b�N�|�C���^
  int *stk;	//�擪�|�C���^
}Stack;


// �K�v�ȃv���g�^�C�v�錾���L�q����D
int StackAlloc(Stack *s, int max);

// stack �̉��
void StackFree(Stack *s);

// stack �ɐV�����ϐ���ς�
int StackPush(Stack *s, int x);

// stack ����1�l�����o��
int StackPop(Stack *s, int *x);

// stack �̎��Ɏ��o�����l���m�F����
int StackPeek(const Stack *s, int *x);

int StackSize(const Stack *s);

// ���݂����̗v�f���ς܂�Ă��邩���m�F����
int StackNo(const Stack *s);

// ����ȍ~�͍쐬���Ă����Ȃ��Ă��\��Ȃ�

// stack ���󂩂ǂ������m�F����
int StackIsEmpty(const Stack *s);

// stack �������ς����ǂ��������m�F����
int StackIsFull(const Stack *s);

void StackClear(Stack *s);
