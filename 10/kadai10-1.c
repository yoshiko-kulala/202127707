/* 課題10-1のひな型 */

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

int sumR(List L);
int sumNR(List L);

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

/* リストの合計を求める関数（再帰版） */
/* ここにソースコードを書く */
int sumR(List L) {
    int num =0;
    if(L != nil) {
        printf(",");
        num=num+first(L);
        writeData(first(L));
        num=num+sumR(rest(L));
        return num;
    }
    else return 0;
}

/* リストの合計を求める関数（非再帰版） */
/* ここにソースコードを書く */
int sumNR(List L) {
    int num = length(L);
    int sum = 0;
    for(int i=0;i<num;i++){
        sum=sum+first(L);
        L=rest(L);
    }
    return sum;
}

/* メイン関数 */
int main(int argc, char **argv) {
    int i, n;
    Data v;
    List L = nil;
    printf("【長さnのリストを作成】\n");
    printf("n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        Data v;
        v = i;
        L = cons(v, L);
    }
    printf("作成されたリスト:\n");
    writeList(L);

    /* 動作確認 */
    printf("\n【動作確認】\n");
    printf("Lの合計値(再帰版): %d\n", sumR(L));
    printf("Lの合計値(非再帰版): %d\n", sumNR(L));
    writeList(L);

    return 0;
}