/*
	�ۑ�9-2�̂ЂȌ`
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define NAMELEN 10

/* ���j���[ */
typedef enum {
	Term, Enque, Deque, Len, Print, IsEmpty, Clear
} Menu;

/* �m�[�h */
typedef struct __node {
  int    no;            /* ����ԍ� */
  char   name[NAMELEN]; /* ���O */
  struct __node  *next; /* �㑱�m�[�h�ւ̃|�C���^ */
} Node;

/* �L���[����������\���� */
typedef struct {
  int    num;     /* ���݂̗v�f�� */
  Node   *front;  /* �擪�v�f�ւ̃|�C���^ */
  Node   *rear;   /* �����v�f�ւ̃|�C���^ */
} Queue;

Queue *QueueInit(); /* �L���[�̏����� */
void QueueClear(Queue *q); /* �L���[����ɂ��� */

void QueueEnque(Queue *q, Node *x); /* �L���[�ɃG���L���[ */
Node *QueueDeque(Queue *q); /* �L���[����f�[�^���f�L���[ */

int QueueLen(const Queue *q); /* �L���[�ɒ~�����Ă���f�[�^�� */
void QueuePrint(const Queue *q); /* �L���[�ɒ~�����Ă��邷�ׂẴm�[�h��\��  */
int QueueIsEmpty(const Queue *q); /* �L���[�͋�(��̂Ƃ�1)*/

Node *AllocNode(void); /* 1�̃m�[�h���m�� */
void SetNode(Node *x, int no, char *name, Node *next);

/* �m�[�h�̊e�����o�ɒl��ݒ� */
void SetNode(Node *x, int no, char *name, Node *next){
	x->no	= no;
	x->next = next;
	strcpy(x->name, name);
}

/* ��̃m�[�h���m�� */
Node *AllocNode(void){
	return (calloc(1, sizeof(Node)));
}

/* ���`���X�g�������� */
Queue* QueueInit(){
   	Queue *q;
	q = (Queue *)calloc(1, sizeof(Queue));
	q->num = 0;
	q->front = NULL;
	q->rear = NULL;
	return q;
}

/* �L���[�ɃG���L���[ */
void QueueEnque(Queue *q, Node *n){
 /* �����ɃR�[�h��ǉ� */
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

/* �L���[����f�[�^���f�L���[ */
Node *QueueDeque(Queue *q){
 /* �����ɃR�[�h��ǉ� */
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

/* �L���[����ɂ��� */
void QueueClear(Queue *q){
 /* �����ɃR�[�h��ǉ� */
	while (q->front != NULL){
    Node *ptr = q->front;
    q->front = ptr->next;
    free(ptr);
  }
	q->num = 0;
	q->front = NULL;
	q->rear = NULL;
}

/* �S�Ẵm�[�h��\�� */
void QueuePrint(const Queue *q){
	Node  *ptr = q->front;
	printf("�L���[�̓��e\n");
	while (ptr != NULL) {
		printf("%5d %-10.10s\n", ptr->no, ptr->name);
		ptr = ptr->next;
	}
}

/* �L���[�͋�(��̂Ƃ�1)*/
int QueueIsEmpty(const Queue *q){
 /* �����ɃR�[�h��ǉ� */
	return q->num == 0;
}

/* �L���[�ɒ~�����Ă���f�[�^�� */
int QueueLen(const Queue *q){
 /* �����ɃR�[�h��ǉ� */
	return q->num;
}


/*--- �f�[�^�̓��� ---*/
Node Read(char *message)
{
	Node  temp;

	printf("%s����f�[�^����͂��Ă��������B\n", message);

	printf("�ԍ��F");	scanf("%d", &temp.no);
	printf("���O�F");	scanf("%s", temp.name);

	return (temp);
}

/*--- ���j���[�I�� ---*/
Menu SelectMenu(void)
{
	int	 ch;

	do {
		printf("\n(1) �G���L���[   (2) �f�L���[\n");
		printf("(3) �L���[�̒���   (4) �L���[�̏o��\n");
		printf("(5) �L���[�͋�   (6) �L���[����ɂ���\n");
		printf("(0) �����I�� �F ");
		scanf("%d", &ch);
	} while (ch < Term || ch > Clear);
	return ((Menu)ch);
}

/*--- ���C�� ---*/
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
		 	x = Read("�}��");
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
		 	printf("�L���[�̒���: %d\n", QueueLen(que));
		 	break;
		 case IsEmpty:
		 	if( QueueIsEmpty(que) == 1){
		 		printf("�L���[�͋�ł�\n");
		 	}
		 	else{
		 		printf("�L���[�͋�ł͂Ȃ�\n");
		 	}
		 	break;
		 case Clear :
		 	printf("�L���[����ɂ��܂���\n");
		 	QueueClear(que);
		 	break;
		}
	} while (menu != Term);

	return (0);
}
