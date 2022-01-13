/* 課題10-3のひな型 */

#include <stdio.h>
/* 定数の定義 */
#define True 1
#define False 0
/* nilはNULL(空リスト)を表す */
#define nil NULL
/* データ型の定義 */
typedef int Bool;
typedef int Data;

/* データ構造の定義 */
typedef struct Cell {
    Data value;
    struct Cell *next;
} * List;

/* 関数プロトタイプの定義 */
List cons(Data n, List L);
Data first(List L);
List rest(List L);
void writeData(Data v);
void writeList(List L);
List readList(void);
int length(List L);

List append(List L1, List L2);
List reverse(List L);

/* cons(d,L): リストLの先頭にデータｄを加えたリストを返す */
List cons(Data d, List L) {
    List newList;
    newList = (List)malloc(sizeof(struct Cell));
    newList->value = d;
    newList->next = L;
    return newList;
}

/* first(L): リストLの先頭のデータを返す */
Data first(List L) { return L->value; }

/* rest(L): リストLの先頭を除いた残りのリストを返す */
List rest(List L) { return L->next; }

/* データ1個分を出力 */
void writeData(Data n) { printf("%d", n); }

/* リスト全体を出力するための再帰関数 */
void writeRest(List L) {
    if(L != nil) {
        printf(",");
        writeData(first(L));
        writeRest(rest(L));
    }
}

/* リスト全体を出力するための関数 */
void writeList(List L) {
    printf("[");
    if(L != nil) {
        writeData(first(L));
        writeRest(rest(L));
    }
    printf("]");
}

/* リストのデータ読み込み関数 */
List readList(void) {
    int n, i;
    List L;
    Data d;
    printf("リストの要素数＝");
    scanf("%d", &n);
    L = nil;
    for(i = 0; i < n; i++) {
        printf("リストの第%d要素＝", i);
        scanf("%d", &d);
        L = cons(d, L);
    }
    return (L);
}

/* リストの長さを求める関数 */
int length(List L) {
    if(L == nil)
        return 0;
    else
        return 1 + length(rest(L));
}

/* 2つのリストを連結した新たなリストを返却する関数 */
/* 課題10-2で作成したappend関数を転記する */
List append(List L1, List L2){
/* ここにソースコードを書く */
    Data d;
    List conect;
    if(L1 == nil&&L2 == nil){
        conect = nil;
    }
    else if(L1 == nil){
        conect = append(L1, rest(L2));
        d=first(L2);
        conect = cons(d, conect);
    }
    else{
        conect = append(rest(L1), L2);
        d=first(L1);
        conect = cons(d, conect);
    }
    return (conect);
}


/* リストの内容を反転したリストを返却する関数 */
List reverse(List L){
	/* 課題10-3のソースコードを作成 */
	if(L == nil){
		return L;
	}
	else{
		return append(reverse(rest(L)),cons(first(L),nil));
	}
/* ここにソースコードを書く */
    /*int num = length(L);
    Data d;
    List rev;
    rev = nil;
    for(int i=0;i<num;i++){
        d=first(L);
        rev = cons(d, rev);
        L=rest(L);
    }
    return (rev);*/
}

/* メイン関数 */
int main(int argc, char **argv){
  int i, n, x;
  Data v;
  List L = nil;
  List Lr, Lrr;
  printf("【長さnのリストを作成】\n");
  printf("n: ");  scanf("%d", &n);
  for( i = 0; i < n; i++){
  	Data v;
  	v = i;
  	L = cons(v, L);
  }
  printf("作成されたリスト:\n");
  writeList(L);

  /* 動作確認 */
  printf("\n【動作確認】\n");
  Lr = reverse(L);
  Lrr = reverse(Lr);

  printf("Lr = ");
  writeList(Lr);
  printf("\n");
  
  printf("Lrr = ");
  writeList(Lrr);
  printf("\n");
  return 0;
}