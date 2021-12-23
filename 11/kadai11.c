#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128
typedef enum { Term, Insert, Search, Print, Load, Save } Menu;

typedef struct _bnode {
  /* list13-1のBinNodeを参考に修正 (課題11-1) */
  char name[MAX_LEN];
  char tel[12];
  char email[22];
  struct _bnode *left;
  struct _bnode *right;
} BinNode;

BinNode *AllocNode(void) {
  BinNode *p;
  p = (BinNode *)calloc(1, sizeof(BinNode));
  return p;
}

BinNode *InsertNode(BinNode *p, BinNode *w) {
  int cond;
  if (p == NULL) {
    p = AllocNode();
    strcpy(p->name, w->name);
    strcpy(p->tel, w->tel);
    strcpy(p->email, w->email);
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w->name, p->name)) == 0)
    printf("【エラー】%sは既に登録されています。\n", w->name);
  else if (cond < 0)
    p->left = InsertNode(p->left, w); /*左の子に着目*/
  else
    p->right = InsertNode(p->right, w); /*右の子に着目*/
  return p;
}

void SearchNode(BinNode *p, BinNode *w) {
  int cond;
  if (p == NULL)
    printf("%s is not registered\n", w->name);
  else if ((cond = strcmp(w->name, p->name)) == 0)
    printf("%s is registered\n", w->name);
  else if (cond < 0)
    SearchNode(p->left, w);
  else
    SearchNode(p->right, w);
}

void PrintTree(BinNode *p) {
  if (p != NULL) {
    PrintTree(p->left);
    printf("%8s%12s%22s\n", p->name, p->tel, p->email);
    PrintTree(p->right);
  }
}

/* ノードを開放する関数 */
void FreeTree(BinNode *p) {
  if (p != NULL) {
    FreeTree(p->left);
    FreeTree(p->right);
    free(p);
  }
}

/* メニュー選択 */
Menu SelectMenu(void) {
  int ch;
  do {
    printf("\n(1)挿入 (2)探索 (3)出力 (4) 読込 (5) 保存 (0)終了 : ");
    scanf("%d", &ch);
  } while (ch < Term || ch > Save);
  return ((Menu)ch);
}

/* 1人分のデータを読み込む関数 */
BinNode ReadAll(char *message) {
  /* Read()関数をベースに3つの情報を読み込み (課題11-2)  */
  BinNode temp;
  printf("%sする名前を入力してください : ", message);
  scanf("%s", temp.name);
  printf("%sするtelを入力してください : ", message);
  scanf("%s", temp.tel);
  printf("%sするemailを入力してください : ", message);
  scanf("%s", temp.email);
  return (temp);
}

/* 1人分のデータ(名前のみ)を読み込む関数 */
BinNode Read(char *message) {
  BinNode temp;
  printf("%sする名前を入力してください : ", message);
  scanf("%s", temp.name);

  return (temp);
}

/* ファイルから読み込む関数(課題1と課題2) */
BinNode *FileRead(BinNode *root, char *filename) {
  FILE *fp;
  fp = fopen(filename, "r"); /* ファイルオープン */

  BinNode x;   /* 単一のノードを保持する変数 */
  int num = 0; /* 読み込んだデータ数を保持する変数 */
  if (fp != NULL) {
    while ( fscanf( fp, "%s\t%s\t%s", x.name, x.tel, x.email ) != EOF) { /* ???は適宜作成 */
      root = InsertNode( root, &x ); /* 1行読み込んだ内容を木に追加 */
      num++;
    }
    printf("%d個のデータを読み込みました\n", num);
    fclose(fp);
  }
  return root;
}

/* FileSave内から呼び出される書き出し処理の本体 */
void SaveTree(FILE *fp, BinNode *p) {
  if (p != NULL) {
    SaveTree(fp,p->left);
    fprintf(fp,"%s\t%s\t%s\n", p->name, p->tel, p->email);
    SaveTree(fp,p->right);
  }
  return 0;
  /* PrintTreeを参考に2分木を辿り，指定されたファイルポインタに順次書き出す処理を書く（課題11-4）
  */
}

/* 与えられた2分木をファイル（filename）に書き出し(main関数から呼び出されるのはこちら)
*/
int FileSave(BinNode *root, char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  SaveTree(fp, root);
  fclose(fp);
  /* ファイルを開いてSaveTreeを呼び出す処理を書く(課題11-4) */
}



int main(void) {
  Menu menu;
  BinNode *root;
  root = NULL;
  int count;
  char filename[128];

  do {
    BinNode x;
    switch (menu = SelectMenu()) {
      case Insert:
        x = ReadAll("挿入");
        root = InsertNode(root, &x);
        break;
      case Search:
        x = Read("探索");
        SearchNode(root, &x);
        break;
      case Print:
        puts("--- 一覧 ---");
        PrintTree(root);
        break;
      case Load: /* ファイルを指定して読み込み */
        printf("Please Input filename:");
        scanf("%s", &filename);
        root = FileRead(root, filename);
        break;
      case Save: /* ファイルを指定して保存 */
        printf("Please Input filename:");
        scanf("%s", &filename);
        count = FileSave(root, filename);
        if (count >= 0) {
          printf("%sに書き込みました\n", filename);
        } else {
          printf("%sの書き込み失敗しました\n", filename);
        }
        break;
    }
  } while (menu != Term);

  return (0);
}
