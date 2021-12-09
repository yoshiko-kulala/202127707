#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

typedef struct __node {
  int no; /* 会員番号*/
  char name[10]; /* 名前 */
  struct __node *next; /* 後続ノードへのポインタ */
} Node;

int no_arr[4]={14,82,57,36};
char name_arr[4][10]={"Hiraki","Iketaka","Katoh","Miyama"};

int main(){
  Node *top;
  Node *ptr = top; 
  for(int i=0;i<4;i++){
      ptr->no = no_arr[i];
      strcpy(ptr->name, name_arr[i]);
      ptr->next =calloc(1, sizeof(Node));
      ptr = ptr->next;
  }
  ptr=top;
  for(int i=0;i<4;i++){
		printf("%5d %-10.10s\n", ptr->no, ptr->name);
		ptr = ptr->next;
	}
  return 0;
}