// Stack ����ɕK�v�Ȋ֐����L�q����D
// �e�֐��̑���ɂ��Ă͋��ȏ����m�F���邱�ƁD

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// stack �𗘗p���邽�߂̏�����
int StackAlloc(Stack *s, int max){
	s->ptr = 0;
	if((s->stk = calloc(max,sizeof(int))) == NULL){
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

// stack �̉��
void StackFree(Stack *s){
	if(s->stk != NULL)free(s->stk);
}

// stack �ɐV�����ϐ���ς�
int StackPush(Stack *s, int x){
	if(s->ptr >= s->max)return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

// stack ����1�l�����o��
int StackPop(Stack *s, int *x){
	if(s->ptr <= 0)return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

// stack �̎��Ɏ��o�����l���m�F����
int StackPeek(const Stack *s, int *x){
	if(s->ptr <= 0)return -1;
	*x = s->stk[s->ptr];
	return 0;
}

// stack �ɋl�߂�ő�̗v�f�����擾
int StackSize(const Stack *s){
	return s->max;
}

// ���݂����̗v�f���ς܂�Ă��邩���m�F����
int StackNo(const Stack *s){
	return s->ptr;
}

// ����ȍ~�͍쐬���Ă����Ȃ��Ă��\��Ȃ�

// stack ���󂩂ǂ������m�F����
int StackIsEmpty(const Stack *s){
	return (s->ptr<=0);
}

// stack �������ς����ǂ��������m�F����
int StackIsFull(const Stack *s){
	return (s->ptr>=s->max);
}

void StackClear(Stack *s){
	s->ptr=0;
}
