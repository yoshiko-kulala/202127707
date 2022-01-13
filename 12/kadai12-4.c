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
  DELETED = -1,
  EMPTY = 0,
  FULL = 1
};

typedef struct
{
  char key[64];
  char value[64];
  int state; /* FULL:�g�p�� EMPTY:���g�p DELETED:�폜 */
} HashRecord;

typedef struct
{
  int size;
  HashRecord *table;
} Hash;

Hash *HashAlloc(int n);
void HashFree(Hash *);
int HashAdd(Hash *, char *, char *);
int HashGet(Hash *, char *, char *);
int HashDelete(Hash *, char *);
int HashCode(Hash *, char *);
void HashDump(Hash *);

// �n�b�V���e�[�u������
Hash *HashAlloc(int n)
{
  int i;

  Hash *hash;
  hash = malloc(sizeof(Hash));

  if (hash == NULL)
  {
    return NULL;
  }

  hash->size = n;
  hash->table = (HashRecord *)calloc(n, sizeof(HashRecord));

  if (hash->table == NULL)
  {
    free(hash);
    return NULL;
  }

  for (i = 0; i < hash->size; i++)
  {
    hash->table[i].state = EMPTY;
  }

  return hash;
}

// �n�b�V���e�[�u���Ɏg�p���������������
void HashFree(Hash *hash)
{
  hash->size = 0;
  free(hash->table);
  free(hash);
}

// �n�b�V���e�[�u���Ƀf�[�^���i�[
// return (TRUE:�L�[�Ƀ��R�[�h��ǉ����� FALSE:�L�[���g�p���Ȃ�Ώ㏑�����Ȃ�)
int HashAdd(Hash *hash, char *key, char *value)
{
  // �R�[�h���쐬 �i�ۑ�4�j���ۑ�2���C��
  int code = HashCode(hash, key);
  while (hash->table[code].state == FULL) {
    code = (code + 1) % hash->size;
    if (code == HashCode(hash, key))return FALSE;
  }
  strcpy(hash->table[code].key, key);
  strcpy(hash->table[code].value, value);
  hash->table[code].state = FULL;
  return TRUE;
}

// ���͂����L�[�ɑΉ�����f�[�^��Ԃ��D(TRUE:�f�[�^�擾����, FALSE:�f�[�^�Ȃ�)
int HashGet(Hash *hash, char *key, char *value)
{
  // �R�[�h���쐬 �i�ۑ�4�j���ۑ�2���C��
  int code = HashCode(hash, key);
  if (hash->table[code].state == EMPTY)return FALSE;
  while (strcmp(hash->table[code].key, key) != 0) {
    code = (code + 1) % hash->size;
    if (code == HashCode(hash, key))return FALSE;
  }
  strcpy(value, hash->table[code].value);
  return TRUE;
}

// ���͂����L�[���폜����D
int HashDelete(Hash *hash, char *key)
{
  // �R�[�h���쐬 �i�ۑ�4�j���ۑ�3���C��
  int code = HashCode(hash, key);
  while (strcmp(hash->table[code].key, key) != 0) {
    code = (code + 1) % hash->size;
    if (code == HashCode(hash, key))return FALSE;
  }
  hash->table[code].state = EMPTY;
  return TRUE;
}

// A-Z�̂ݍl��. 2�����ȏ�.
int HashCode(Hash * hash, char *s)
{
  // �R�[�h���쐬 �i�ۑ�1�j
  if (strlen(s) == 0)return 0;
  else if (strlen(s) == 1)return (s[0] - 'A') % hash->size;
  else {
    int n;
    n = strlen(s);
    return ((s[0] - 'A' + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26) % hash->size);
  }
}

void HashDump(Hash * hash)
{
  int i, h;

  for (i = 0; i < hash->size; i++)
  {
    printf("%4d: ", i);

    switch (hash->table[i].state)
    {
      case FULL:
        h = HashCode(hash, hash->table[i].key);
        printf("(%s[%d], %s)", hash->table[i].key, h, hash->table[i].value);
        break;
      case EMPTY:
        printf("empty");
        break;
      case DELETED:
        printf("deleted");
        break;
      default:
        printf("unknown");
        break;
    }

    printf("\n");
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

  if (hash == NULL)
    return -1; // �������m�ێ��s

  puts("�n�b�V���e�[�u���𑀍삷��R�}���h�����");
  puts("a: �f�[�^���i�[");
  puts("g: �L�[�ɑΉ�����f�[�^�̎擾");
  puts("d: �L�[���폜");
  puts("p: �n�b�V���e�[�u�����o��");
  puts("q: �I��");
  do
  {
    printf("?> ");
    scanf("%s", buf);
    cmd = buf[0];

    switch (cmd)
    {
      case 'a': /* �f�[�^���i�[ */
        printf("���O�ƌ��t�^���X�y�[�X��؂�œ��́i��:YAMADA B�j: ");
        scanf("%s %s", key, value);
        printf("%c -> %s %s\n", cmd, key, value);

        if (HashAdd(hash, key, value) == TRUE)
        {
          printf("(%s, %s) ���i�[���܂����D\n", key, value);
        }
        else
        { /* �Փ� */
          printf("�d�����Ă��܂��D\n");
        }
        break;
      case 'g': /* �L�[�ɑΉ�����f�[�^���擾 */
        printf("���O����͂��ĉ�����: ");
        scanf("%s", key);
        printf("%c -> %s\n", cmd, key);

        if (HashGet(hash, key, value) == TRUE)
        {
          printf("%s�̌��t�^��%s�ł��D\n", key, value);
        }
        else
        {
          printf("%s�͓o�^����Ă��܂���D\n", key);
        }
        break;
      case 'd': /* �L�[���폜 */
        printf("�N���폜���܂���?: ");
        scanf("%s", key);
        printf("%c -> %s\n", cmd, key);

        if (HashDelete(hash, key) == TRUE)
        {
          printf("%s���폜���܂����D\n", key);
        }
        else
        {
          printf("%s�͓o�^����Ă��܂���D\n", key);
        }
        break;
      case 'p': /* �f�[�^��\�� */
        printf("%c\n", cmd);
        HashDump(hash);
        break;
      case 'q': /* �I�� */
        printf("%c\n", cmd);
        puts("�v���O�������I�����܂��D");
        break;
      case '\n': /* ���s */
      case '\r': /* ���A */
        break;
      default: /* ���̓G���[ */
        puts("�s���ȃR�}���h�ł��D");
        break;
    }
  } while (cmd != 'q');

  HashDump(hash); // ����O�̏o��
  HashFree(hash); // ���������

  return 0;
}