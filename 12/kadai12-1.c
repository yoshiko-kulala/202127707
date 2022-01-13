#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ハッシュテーブル構造定義 */
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
  int state; /* FULL:使用中 EMPTY:未使用 */
} HashRecord;

typedef struct
{
  int size;
  HashRecord *table;
} Hash;

Hash *HashAlloc(int n);
void HashFree(Hash *);
int HashCode(Hash *hash, char *s);

// Hashの作成
Hash *HashAlloc(int n)
{
  int i;
  Hash *hash;
  hash = malloc(sizeof(Hash)); // hash本体の領域確保

  if (hash == NULL)
  {
    return NULL;
  }

  hash->size = n;
  hash->table = (HashRecord *)calloc(n, sizeof(HashRecord)); // hashテーブルの領域確保

  if (hash->table == NULL)
  { // hashテーブルの領域確保に失敗したとき
    free(hash);
    return NULL;
  }

  for (i = 0; i < hash->size; i++)
  { // hashテーブルの初期状態を作成
    hash->table[i].state = EMPTY;
  }

  return hash; // hash本体へのポインタを返却
}

// ハッシュテーブルに使用したメモリを解放
void HashFree(Hash *hash)
{
  hash->size = 0;
  free(hash->table);
  free(hash);
}

int HashCode(Hash *hash, char *s)
{
// コードを作成 （課題1）
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

  // ハッシュテーブルの生成
  printf("ハッシュテーブルの大きさを入力して下さい?> ");
  scanf("%d", &size);

  if (size < 1)
    return -1; // 入力数エラー

  hash = HashAlloc(size);

  if (HashCode(hash, "") == 0)
  {
    printf("\"\"の場合 -> OK\n");
  }
  else
  {
    printf("\"\"の場合 -> NG\n");
    return -1;
  }

  while (1)
  {
    printf("文字列を入力（大文字アルファベットのみ，qで終了）: ");
    scanf("%s", buf);
    if (strcmp(buf, "q") == 0)
      break;
    printf("%d\n", HashCode(hash, buf));
  }

  return 0;
}