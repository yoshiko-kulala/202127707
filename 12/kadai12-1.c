#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* �n�b�V���e�[�u���\����` */
enum
{
  FALSE = 0,
  TRUE = 1
};
enum
{
  EMPTY = 0,
  FULL = 1
};

typedef struct
{
  char key[64];
  char value[64];
  int state; /* FULL:�g�p�� EMPTY:���g�p */
} HashRecord;

typedef struct
{
  int size;
  HashRecord *table;
} Hash;

Hash *HashAlloc(int n);
void HashFree(Hash *);
int HashCode(Hash *hash, char *s);

// Hash�̍쐬
Hash *HashAlloc(int n)
{
  int i;
  Hash *hash;
  hash = malloc(sizeof(Hash)); // hash�{�̗̂̈�m��

  if (hash == NULL)
  {
    return NULL;
  }

  hash->size = n;
  hash->table = (HashRecord *)calloc(n, sizeof(HashRecord)); // hash�e�[�u���̗̈�m��

  if (hash->table == NULL)
  { // hash�e�[�u���̗̈�m�ۂɎ��s�����Ƃ�
    free(hash);
    return NULL;
  }

  for (i = 0; i < hash->size; i++)
  { // hash�e�[�u���̏�����Ԃ��쐬
    hash->table[i].state = EMPTY;
  }

  return hash; // hash�{�̂ւ̃|�C���^��ԋp
}

// �n�b�V���e�[�u���Ɏg�p���������������
void HashFree(Hash *hash)
{
  hash->size = 0;
  free(hash->table);
  free(hash);
}

int HashCode(Hash *hash, char *s)
{
// �R�[�h���쐬 �i�ۑ�1�j
	if(strlen(s)==0)return 0;
	else if(strlen(s)==1)return (s[0]-'A')% hash->size;
	else{
		int n;
		n = strlen(s);
		return ((s[0] - 'A' +(s[n/2-1] - 'A') * 26 +(s[n-2] - 'A') * 26 * 26) % hash->size);
	}
}

int main(void)
{
  int size = 0, h;
  char cmd, key[64], value[64], buf[64];
  Hash *hash;

  // �n�b�V���e�[�u���̐���
  printf("�n�b�V���e�[�u���̑傫������͂��ĉ�����?> ");
  scanf("%d", &size);

  if (size < 1)
    return -1; // ���͐��G���[

  hash = HashAlloc(size);

  if (HashCode(hash, "") == 0)
  {
    printf("\"\"�̏ꍇ -> OK\n");
  }
  else
  {
    printf("\"\"�̏ꍇ -> NG\n");
    return -1;
  }

  while (1)
  {
    printf("���������́i�啶���A���t�@�x�b�g�̂݁Cq�ŏI���j: ");
    scanf("%s", buf);
    if (strcmp(buf, "q") == 0)
      break;
    printf("%d\n", HashCode(hash, buf));
  }

  return 0;
}