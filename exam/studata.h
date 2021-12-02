// studata.c のためのヘッダファイルである．
// 必要な情報を記述せよ
// 構造体の定義はこちらで行うこと．

typedef struct{
  char name[33];
  int age;
  double height;
  double weight;
}studata;

void set_studata(studata *data, char *name,int age,double weight, double height);
		 
studata *load_studata(char *filename, int *num);

void print_studata(studata *data, int num);

void sor_by_height(int num, studata *data);

void sort_by_name(int num, studata *data);

void mystrcpy(char *to, const char *from);

void int_swap(int *p1,int *p2);

void swap_double(double *p1,double *p2);

void swap_s(char *to, char *from);