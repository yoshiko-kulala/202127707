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
int HashAdd(Hash *, char *, char *);
int HashGet(Hash *, char *, char *);
int HashDelete(Hash *, char *);
int HashCode(Hash *, char *);

void HashDump(Hash *);

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

// ハッシュテーブルにデータを格納 (TRUE:キーにレコードを追加する, FALSE:キーが使用中ならば上書きしない)
int HashAdd(Hash *hash, char *key, char *value)
{
// コードを作成 （課題2）
	int code = HashCode(hash,key);
	if(hash->table[code].state==FULL)return FALSE;
	else{
		strcpy(hash->table[code].key,key);
		strcpy(hash->table[code].value,value);
		hash->table[code].state=FULL;
		return TRUE;
	}
}

// 入力したキーに対応するデータを返す．(TRUE:データ取得成功, FALSE:データなし)
int HashGet(Hash *hash, char *key, char *value)
{
// コードを作成 （課題2）
	int code = HashCode(hash,key);
	if(hash->table[code].state==EMPTY)return FALSE;
	if(strcpy(hash->table[code].key,key)==0)return FALSE;
	strcpy(value,hash->table[code].value);
	return TRUE;
}

// 入力したキーを削除する．(TRUE:データ取得成功, FALSE:データなし)
int HashDelete(Hash *hash, char *key)
{
// コードを作成 （課題3）
	int code = HashCode(hash,key);
	if(hash->table[code].state==EMPTY)return FALSE;
	else{
		hash->table[code].state=EMPTY;
		return TRUE;
	}
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

// ハッシュテーブルのレコードを全て表示する（ハッシュが空でも表示）．
void HashDump(Hash *hash)
{
  int i;

  for (i = 0; i < hash->size; i++)
  {
    printf("%4d: ", i);

    switch (hash->table[i].state)
    {
    case FULL:
      printf("(%s, %s)", hash->table[i].key, hash->table[i].value);
      break;
    case EMPTY:
      printf("empty");
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

  // ハッシュテーブルの生成
  printf("ハッシュテーブルの大きさを入力して下さい?> ");
  scanf("%d", &size);

  if (size < 1)
    return -1; // 入力数エラー

  hash = HashAlloc(size);

  if (hash == NULL)
    return -1; // メモリ確保失敗

  puts("ハッシュテーブルを操作するコマンドを入力");
  puts("a: データを格納");
  puts("g: キーに対応するデータの取得");
  puts("d: キーを削除");
  puts("p: ハッシュテーブルを出力");
  puts("q: 終了");

  do
  {
    printf("?> ");
    scanf("%s", buf);
    cmd = buf[0];

    switch (cmd)
    {
    case 'a': /* データを格納 */
      printf("名前と血液型をスペース区切りで入力（例:YAMADA B）: ");
      scanf("%s %s", key, value);
      printf("%c -> %s %s\n", cmd, key, value);

      if (HashAdd(hash, key, value) == TRUE)
      {
        printf("(%s, %s) を格納しました．\n", key, value);
      }
      else
      { /* 衝突 */
        printf("重複しています．\n");
      }
      break;
    case 'g': /* キーに対応するデータを取得 */
      printf("名前を入力して下さい: ");
      scanf("%s", key);
      printf("%c -> %s\n", cmd, key);

      if (HashGet(hash, key, value) == TRUE)
      {
        printf("%sの血液型は%sです．\n", key, value);
      }
      else
      {
        printf("%sは登録されていません．\n", key);
      }
      break;
    case 'd': /* キーを削除 */
      printf("誰を削除しますか?: ");
      scanf("%s", key);
      printf("%c -> %s\n", cmd, key);

      if (HashDelete(hash, key) == TRUE)
      {
        printf("%sを削除しました．\n", key);
      }
      else
      {
        printf("%sは登録されていません．\n", key);
      }
      break;
    case 'p': /* データを表示 */
      printf("%c\n", cmd);
      HashDump(hash);
      break;
    case 'q': /* 終了 */
      printf("%c\n", cmd);
      puts("プログラムを終了します．");
      break;
    case '\n': /* 改行 */
    case '\r': /* 復帰 */
      break;
    default: /* 入力エラー */
      puts("不正なコマンドです．");
      break;
    }
  } while (cmd != 'q');

  HashDump(hash); // 解放前の出力
  HashFree(hash); // メモリ解放

  return 0;
}