// Stack 操作に必要な関数を記述せよ．
// 各関数の操作については教科書を確認すること．

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// stack を利用するための初期化
int StackAlloc(Stack *s, int max){
	s->ptr = 0;
	if((s->stk = calloc(max,sizeof(int))) == NULL){
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

// stack の解放
void StackFree(Stack *s){
	if(s->stk != NULL)free(s->stk);
}

// stack に新しい変数を積む
int StackPush(Stack *s, int x){
	if(s->ptr >= s->max)return -1;
	s->stk[s->ptr++] = x;
	return 0;
}

// stack から1つ値を取り出す
int StackPop(Stack *s, int *x){
	if(s->ptr <= 0)return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

// stack の次に取り出される値を確認する
int StackPeek(const Stack *s, int *x){
	if(s->ptr <= 0)return -1;
	*x = s->stk[s->ptr];
	return 0;
}

// stack に詰める最大の要素数を取得
int StackSize(const Stack *s){
	return s->max;
}

// 現在いくつの要素が積まれているかを確認する
int StackNo(const Stack *s){
	return s->ptr;
}

// これ以降は作成してもしなくても構わない

// stack が空かどうかを確認する
int StackIsEmpty(const Stack *s){
	return (s->ptr<=0);
}

// stack がいっぱいかどうかおｗ確認する
int StackIsFull(const Stack *s){
	return (s->ptr>=s->max);
}

void StackClear(Stack *s){
	s->ptr=0;
}
