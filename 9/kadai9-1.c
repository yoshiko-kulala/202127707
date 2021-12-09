/*
	�ۑ�9-1�̂ЂȌ`
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

/*--- ���j���[ ---*/
typedef enum {
	Term, Insert, Append, Delete, Print, Clear, InsertN, DeleteN
} Menu;

/*--- �m�[�h ---*/
typedef struct __node {
	int			   no;			/* ����ԍ� */
	char		   name[10];	/* ���O */
	struct __node  *next;		/* �㑱�m�[�h�ւ̃|�C���^ */
} Node;

/*--- �m�[�h�̊e�����o�ɒl��ݒ� ----*/
void SetNode(Node *x, int no, char *name, Node *next)
{
	x->no	= no;
	x->next = next;
	strcpy(x->name, name);
}

/*--- ��̃m�[�h���m�� ---*/
Node *AllocNode(void)
{
	return (calloc(1, sizeof(Node)));
}

/*--- �擪�Ƀm�[�h��}�� ---*/
void InsertNode(Node **top, int no, char *name)
{
	Node  *ptr = *top;
	*top = AllocNode();
	SetNode(*top, no, name, ptr);	/* next�́A����܂Ő擪�������m�[�h���w�� */
}

/*--- �����Ƀm�[�h��}�� ---*/
void AppendNode(Node **top, int no, char *name)
{
	if (*top == NULL)						/* ���X�g����ł���� */
		InsertNode(top, no, name);			/* �擪�ɑ}�� */
	else {
		Node  *ptr = *top;
		while (ptr->next != NULL)			/* �����m�[�h�������� */
			ptr = ptr->next;
		ptr->next = AllocNode();
		SetNode(ptr->next, no, name, NULL);
	}
}

/*--- �擪�̃m�[�h���폜 ---*/
void DeleteNode(Node **top)
{
	if (*top != NULL) {
		Node  *ptr = (*top)->next;
		free(*top);
		*top = ptr;
	}
}

/*--- �S�Ẵm�[�h���폜 ---*/
void ClearList(Node **top)
{
	while (*top != NULL)					/* ���X�g����ɂȂ�܂� */
		DeleteNode(top);					/* �擪�̃m�[�h���폜 */
}

/*--- �S�Ẵm�[�h��\�� ---*/
void PrintList(Node **top)
{
	Node  *ptr = *top;

	puts("�y�ꗗ�z");
	while (ptr != NULL) {
		printf("%5d %-10.10s\n", ptr->no, ptr->name);
		ptr = ptr->next;
	}
}

/*--- ���`���X�g�������� ---*/
void InitList(Node **top)
{
	*top = NULL;
}

/*--- ���`���X�g�̎g�p���I�� ---*/
void TermList(Node **top)
{
	ClearList(top);						/* �S�Ẵm�[�h���폜 */
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

/*--- ���X�g��n�ԖڂɃm�[�h��}�� ---*/
void InsertNodeNth(Node **top, int n, int no, char *name){
 /* �����ɃR�[�h��ǉ� */
//��O�̌㑱�A�h���X�������ɏ���������
//��O�̌㑱�A�h���X�������̌㑱�A�h���X�ɂ���
	if (n==0){
		Node  *ptr = *top;
		*top = AllocNode();
		SetNode(*top, no, name, ptr);
	}
	else {
		Node  *ptr = *top;
		Node *mnew;
    mnew= AllocNode();
		for(int i=1;i<n;i++)ptr = ptr->next;
		SetNode(mnew, no, name, ptr->next);
		ptr->next = mnew;
	}
}

/*--- ���X�g��n�Ԗڂ̃m�[�h���폜 ---*/
void DeleteNodeNth(Node **top, int n){
 /* �����ɃR�[�h��ǉ� */
	if(n==0 && *top != NULL) {//�擪�Ȃ�Y�������ɃA�h���X��ς���
		Node  *ptr = (*top)->next;
		free(*top);
		*top = ptr;
	}
	else{//��O�̌㑱�A�h���X�������̌㑱�A�h���X�ɕύX����
		Node *del = *top;
		for(int i=1;i<n;i++)del = del->next;
		del->next=del->next->next;
		free(del);
	}
}

/*--- ���j���[�I�� ---*/
Menu SelectMenu(void)
{
	int	 ch;

	do {
		printf("\n(1) �擪�Ƀm�[�h��}��   (2) �����Ƀm�[�h��}��\n");
		printf("(3) �擪�̃m�[�h���폜   (4) �S�Ẵm�[�h�o��\n");
		printf("(5) �S�Ẵm�[�h���폜   (0) ��   ��    �I   �� �F \n");
		printf("(6) n�ԖڂɃm�[�h��}��  (7) n�Ԗڂ̃m�[�h���폜");
		scanf("%d", &ch);
	} while (ch < Term  ||  ch > DeleteN);
	return ((Menu)ch);
}

/*--- ���C�� ---*/
int main(void)
{
	Menu  menu;
	Node  *list;
	int n;
	
	InitList(&list);

	do {
		Node  x;
		switch (menu = SelectMenu()) {
		 case Insert: x = Read("�}��");
					  InsertNode(&list, x.no, x.name);	break;
		 case Append: x = Read("�}��");
					  AppendNode(&list, x.no, x.name);	break;
		 case Delete: DeleteNode(&list);				break;
		 case Print : PrintList(&list);					break;
		 case Clear : ClearList(&list);					break;
		 case InsertN: 
		 			printf("���ԖځF"); scanf( "%d", &n);
					x = Read("�}��");
				 	InsertNodeNth( &list, n, x.no, x.name);	break;
		 case DeleteN: 
		 			printf("���ԖځF"); scanf( "%d", &n);
				 	DeleteNodeNth( &list, n);	break;
		}
	} while (menu != Term);

	TermList(&list);
	return (0);
}
