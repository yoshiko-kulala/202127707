// stack.c を使用するために必要な情報を記述すること

// Stack に使用する構造体
typedef struct{
  int max;	//スタックサイズ
  int ptr;	//スタックポインタ
  int *stk;	//先頭ポインタ
}Stack;


// 必要なプロトタイプ宣言を記述せよ．
int StackAlloc(Stack *s, int max);

// stack の解放
void StackFree(Stack *s);

// stack に新しい変数を積む
int StackPush(Stack *s, int x);

// stack から1つ値を取り出す
int StackPop(Stack *s, int *x);

// stack の次に取り出される値を確認する
int StackPeek(const Stack *s, int *x);

int StackSize(const Stack *s);

// 現在いくつの要素が積まれているかを確認する
int StackNo(const Stack *s);

// これ以降は作成してもしなくても構わない

// stack が空かどうかを確認する
int StackIsEmpty(const Stack *s);

// stack がいっぱいかどうかおｗ確認する
int StackIsFull(const Stack *s);

void StackClear(Stack *s);
