/*
	線形リストの実現例
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

/*--- メニュー ---*/
typedef enum {
	Term, Insert, Append, Delete, Print, Clear
} Menu;

/*--- ノード ---*/
typedef struct __node {
	int			   no;			/* 会員番号 */
	char		   name[10];	/* 名前 */
	struct __node  *next;		/* 後続ノードへのポインタ */
} Node;

/*--- ノードの各メンバに値を設定 ----*/
void SetNode(Node *x, int no, char *name, Node *next)
{
	x->no	= no;
	x->next = next;
	strcpy(x->name, name);
}

/*--- 一つのノードを確保 ---*/
Node *AllocNode(void)
{
	return (calloc(1, sizeof(Node)));
}

/*--- 先頭にノードを挿入 ---*/
void InsertNode(Node **top, int no, char *name)
{
	Node  *ptr = *top;
	*top = AllocNode();
	SetNode(*top, no, name, ptr);	/* nextは、それまで先頭だったノードを指す */
}

/*--- 末尾にノードを挿入 ---*/
void AppendNode(Node **top, int no, char *name)
{
	if (*top == NULL)						/* リストが空であれば */
		InsertNode(top, no, name);			/* 先頭に挿入 */
	else {
		Node  *ptr = *top;
		while (ptr->next != NULL)			/* 末尾ノードを見つける */
			ptr = ptr->next;
		ptr->next = AllocNode();
		SetNode(ptr->next, no, name, NULL);
	}
}

/*--- 先頭のノードを削除 ---*/
void DeleteNode(Node **top)
{
	if (*top != NULL) {
		Node  *ptr = (*top)->next;
		free(*top);
		*top = ptr;
	}
}

/*--- 全てのノードを削除 ---*/
void ClearList(Node **top)
{
	while (*top != NULL)					/* リストが空になるまで */
		DeleteNode(top);					/* 先頭のノードを削除 */
}

/*--- 全てのノードを表示 ---*/
void PrintList(Node **top)
{
	Node  *ptr = *top;

	puts("【一覧】");
	while (ptr != NULL) {
		printf("%5d %-10.10s\n", ptr->no, ptr->name);
		ptr = ptr->next;
	}
}

/*--- 線形リストを初期化 ---*/
void InitList(Node **top)
{
	*top = NULL;
}

/*--- 線形リストの使用を終了 ---*/
void TermList(Node **top)
{
	ClearList(top);						/* 全てのノードを削除 */
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
		printf("\n(1) 先頭にノードを挿入   (2) 末尾にノードを挿入\n");
		printf("(3) 先頭のノードを削除   (4) 全てのノード出力\n");
		printf("(5) 全てのノードを削除   (0) 処   理    終   了 ： ");
		scanf("%d", &ch);
	} while (ch < Term  ||  ch > Clear);
	return ((Menu)ch);
}

/*--- メイン ---*/
int main(void)
{
	Menu  menu;
	Node  *list;

	InitList(&list);

	do {
		Node  x;
		switch (menu = SelectMenu()) {
		 case Insert: x = Read("挿入");
					  InsertNode(&list, x.no, x.name);	break;
		 case Append: x = Read("挿入");
					  AppendNode(&list, x.no, x.name);	break;
		 case Delete: DeleteNode(&list);				break;
		 case Print : PrintList(&list);					break;
		 case Clear : ClearList(&list);					break;
		}
	} while (menu != Term);

	TermList(&list);
	return (0);
}
