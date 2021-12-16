/*
	課題9-2のひな形
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define NAMELEN 10

/* メニュー */
typedef enum {
	Term, Enque, Deque, Len, Print, IsEmpty, Clear
} Menu;

/* ノード */
typedef struct __node {
  int    no;            /* 会員番号 */
  char   name[NAMELEN]; /* 名前 */
  struct __node  *next; /* 後続ノードへのポインタ */
} Node;

/* キューを実現する構造体 */
typedef struct {
  int    num;     /* 現在の要素数 */
  Node   *front;  /* 先頭要素へのポインタ */
  Node   *rear;   /* 末尾要素へのポインタ */
} Queue;

Queue *QueueInit(); /* キューの初期化 */
void QueueClear(Queue *q); /* キューを空にする */

void QueueEnque(Queue *q, Node *x); /* キューにエンキュー */
Node *QueueDeque(Queue *q); /* キューからデータをデキュー */

int QueueLen(const Queue *q); /* キューに蓄えられているデータ数 */
void QueuePrint(const Queue *q); /* キューに蓄えられているすべてのノードを表示  */
int QueueIsEmpty(const Queue *q); /* キューは空か(空のとき1)*/

Node *AllocNode(void); /* 1つのノードを確保 */
void SetNode(Node *x, int no, char *name, Node *next);

/* ノードの各メンバに値を設定 */
void SetNode(Node *x, int no, char *name, Node *next){
	x->no	= no;
	x->next = next;
	strcpy(x->name, name);
}

/* 一つのノードを確保 */
Node *AllocNode(void){
	return (calloc(1, sizeof(Node)));
}

/* 線形リストを初期化 */
Queue* QueueInit(){
   	Queue *q;
	q = (Queue *)calloc(1, sizeof(Queue));
	q->num = 0;
	q->front = NULL;
	q->rear = NULL;
	return q;
}

/* キューにエンキュー */
void QueueEnque(Queue *q, Node *n){
 /* ここにコードを追加 */
  Node *ptr;
  if(q->num == 0){
    ptr = AllocNode();
    q->front=ptr;
    SetNode(ptr, n->no, n->name, NULL);
    q->rear = ptr;
  }
  else{
    ptr = q->rear;
    ptr->next = AllocNode();
    SetNode(ptr->next, n->no, n->name, NULL);
    q->rear = ptr->next;
  }
	q->num++;
}

/* キューからデータをデキュー */
Node *QueueDeque(Queue *q){
 /* ここにコードを追加 */
	if(q->num > 0){
		q->num--;
		Node *ptr = AllocNode(),*de = q->front;;
    SetNode(ptr, de->no, de->name, de->next);
		free(q->front);
		q->front = ptr->next;
    return ptr;
	}
  else return NULL;
}

/* キューを空にする */
void QueueClear(Queue *q){
 /* ここにコードを追加 */
	while (q->front != NULL){
    Node *ptr = q->front;
    q->front = ptr->next;
    free(ptr);
  }
	q->num = 0;
	q->front = NULL;
	q->rear = NULL;
}

/* 全てのノードを表示 */
void QueuePrint(const Queue *q){
	Node  *ptr = q->front;
	printf("キューの内容\n");
	while (ptr != NULL) {
		printf("%5d %-10.10s\n", ptr->no, ptr->name);
		ptr = ptr->next;
	}
}

/* キューは空か(空のとき1)*/
int QueueIsEmpty(const Queue *q){
 /* ここにコードを追加 */
	return q->num == 0;
}

/* キューに蓄えられているデータ数 */
int QueueLen(const Queue *q){
 /* ここにコードを追加 */
	return q->num;
}


/*--- データの入力 ---*/
Node Read(char *message)
{
	Node  temp;

	printf("%sするデータを入力してください。\n", message);

	printf("番号：");	scanf("%d", &temp.no);
	printf("名前：");	scanf("%s", temp.name);

	return (temp);
}

/*--- メニュー選択 ---*/
Menu SelectMenu(void)
{
	int	 ch;

	do {
		printf("\n(1) エンキュー   (2) デキュー\n");
		printf("(3) キューの長さ   (4) キューの出力\n");
		printf("(5) キューは空か   (6) キューを空にする\n");
		printf("(0) 処理終了 ： ");
		scanf("%d", &ch);
	} while (ch < Term || ch > Clear);
	return ((Menu)ch);
}

/*--- メイン ---*/
int main(void)
{
	Menu  menu;
	Queue  *que;
	Node *n;
	que = QueueInit();

	do {
		Node  x;
		switch (menu = SelectMenu()) {
		 case Enque:
		 	x = Read("挿入");
			Node *n = AllocNode();
			SetNode( n, x.no, x.name, NULL);
		 	QueueEnque(que, n);
		 	break;
		 case Deque:
		 	n = QueueDeque(que);
		 	if( n != NULL){
			 	printf("%5d %-10.10s\n", n->no, n->name);
		 	}
		 	break;
		 case Print:
		 	QueuePrint(que);
		 	break;
		 case Len:
		 	printf("キューの長さ: %d\n", QueueLen(que));
		 	break;
		 case IsEmpty:
		 	if( QueueIsEmpty(que) == 1){
		 		printf("キューは空です\n");
		 	}
		 	else{
		 		printf("キューは空ではない\n");
		 	}
		 	break;
		 case Clear :
		 	printf("キューを空にしました\n");
		 	QueueClear(que);
		 	break;
		}
	} while (menu != Term);

	return (0);
}
