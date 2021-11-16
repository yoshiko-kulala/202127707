// キューを利用するためのプログラムを作成せよ

typedef struct{
  int max;		//キューのサイズ
  int num;		//現在の要素数
  int front;	//先頭要素カーソル
  int rear;		//末尾要素カーソル
  int *que;		//キューの先頭要素へのポインタ
}Queue;


// 以下，必要なものを記述せよ．

int QueueAlloc(Queue *q, int max);

void QueueFree(Queue *q);

int QueueEnqueue(Queue *q, int x);

int QueueDequeu(Queue *q, int *x);

int QueueSize(const Queue *q);

int QueueNo(const Queue *q);

int QueueIsEmpty(const Queue *q);

int QueueIsFull(const Queue *q);