#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128
typedef enum { Term, Insert, Search, Print, Load, Save } Menu;

typedef struct _bnode {
  /* list13-1��BinNode���Q�l�ɏC�� (�ۑ�11-1) */
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
    printf("�y�G���[�z%s�͊��ɓo�^����Ă��܂��B\n", w->name);
  else if (cond < 0)
    p->left = InsertNode(p->left, w); /*���̎q�ɒ���*/
  else
    p->right = InsertNode(p->right, w); /*�E�̎q�ɒ���*/
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

/* �m�[�h���J������֐� */
void FreeTree(BinNode *p) {
  if (p != NULL) {
    FreeTree(p->left);
    FreeTree(p->right);
    free(p);
  }
}

/* ���j���[�I�� */
Menu SelectMenu(void) {
  int ch;
  do {
    printf("\n(1)�}�� (2)�T�� (3)�o�� (4) �Ǎ� (5) �ۑ� (0)�I�� : ");
    scanf("%d", &ch);
  } while (ch < Term || ch > Save);
  return ((Menu)ch);
}

/* 1�l���̃f�[�^��ǂݍ��ފ֐� */
BinNode ReadAll(char *message) {
  /* Read()�֐����x�[�X��3�̏���ǂݍ��� (�ۑ�11-2)  */
  BinNode temp;
  printf("%s���閼�O����͂��Ă������� : ", message);
  scanf("%s", temp.name);
  printf("%s����tel����͂��Ă������� : ", message);
  scanf("%s", temp.tel);
  printf("%s����email����͂��Ă������� : ", message);
  scanf("%s", temp.email);
  return (temp);
}

/* 1�l���̃f�[�^(���O�̂�)��ǂݍ��ފ֐� */
BinNode Read(char *message) {
  BinNode temp;
  printf("%s���閼�O����͂��Ă������� : ", message);
  scanf("%s", temp.name);

  return (temp);
}

/* �t�@�C������ǂݍ��ފ֐�(�ۑ�1�Ɖۑ�2) */
BinNode *FileRead(BinNode *root, char *filename) {
  FILE *fp;
  fp = fopen(filename, "r"); /* �t�@�C���I�[�v�� */

  BinNode x;   /* �P��̃m�[�h��ێ�����ϐ� */
  int num = 0; /* �ǂݍ��񂾃f�[�^����ێ�����ϐ� */
  if (fp != NULL) {
    while ( fscanf( fp, "%s\t%s\t%s", x.name, x.tel, x.email ) != EOF) { /* ???�͓K�X�쐬 */
      root = InsertNode( root, &x ); /* 1�s�ǂݍ��񂾓��e��؂ɒǉ� */
      num++;
    }
    printf("%d�̃f�[�^��ǂݍ��݂܂���\n", num);
    fclose(fp);
  }
  return root;
}

/* FileSave������Ăяo����鏑���o�������̖{�� */
void SaveTree(FILE *fp, BinNode *p) {
  if (p != NULL) {
    SaveTree(fp,p->left);
    fprintf(fp,"%s\t%s\t%s\n", p->name, p->tel, p->email);
    SaveTree(fp,p->right);
  }
  return 0;
  /* PrintTree���Q�l��2���؂�H��C�w�肳�ꂽ�t�@�C���|�C���^�ɏ��������o�������������i�ۑ�11-4�j
  */
}

/* �^����ꂽ2���؂��t�@�C���ifilename�j�ɏ����o��(main�֐�����Ăяo�����̂͂�����)
*/
int FileSave(BinNode *root, char *filename) {
  FILE *fp;
  fp = fopen(filename, "w");
  SaveTree(fp, root);
  fclose(fp);
  /* �t�@�C�����J����SaveTree���Ăяo������������(�ۑ�11-4) */
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
        x = ReadAll("�}��");
        root = InsertNode(root, &x);
        break;
      case Search:
        x = Read("�T��");
        SearchNode(root, &x);
        break;
      case Print:
        puts("--- �ꗗ ---");
        PrintTree(root);
        break;
      case Load: /* �t�@�C�����w�肵�ēǂݍ��� */
        printf("Please Input filename:");
        scanf("%s", &filename);
        root = FileRead(root, filename);
        break;
      case Save: /* �t�@�C�����w�肵�ĕۑ� */
        printf("Please Input filename:");
        scanf("%s", &filename);
        count = FileSave(root, filename);
        if (count >= 0) {
          printf("%s�ɏ������݂܂���\n", filename);
        } else {
          printf("%s�̏������ݎ��s���܂���\n", filename);
        }
        break;
    }
  } while (menu != Term);

  return (0);
}
