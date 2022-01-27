#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 1; //���̐����J�E���g

void print_border(int n);
void print_queen(int q[], int n);

// �Ֆʂ̑S�p�^�[���𐶐����鏈��
void set_queen(int q[], int, int);

// 2�̈ʒu�̃N�C�[�����݂��Ɏ�荇���ʒu������
int safe(int q[], int i, int j);

// �Ֆʂɂ���N�C�[�����݂��Ɏ�荇���ʒu�ɂ��邩����
int safe_all(int q[], int k);

// �C�ӂ�n�ł�N�N�C�[����������
int solve(int n);


// ����Ֆʂɂ���N�C�[�������݂��Ɏ�荇���֌W�ɂ��邩����
int safe_all(int q[], int n) {
    // �����ɏ������L���i�ۑ�2)
    // q: �Ֆʂ̔z��, n: �z��̗v�f��
    // ��荇���֌W�Ȃ�-1��Ԃ�
    // ����ȊO��1(��荇���֌W�ɂȂ�)��Ԃ�
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(safe(q,i,j)==-1)return -1;
    }
  }
  return 1;
}


int safe(int q[], int i, int j)
{
    // �����ɏ������L���i�ۑ�2)
    // q: �Ֆʂ̔z��, i��ڂ�j��ڂ̗v�f����荇���֌W�����ׂ�
    // ��荇���֌W�Ȃ�-1��Ԃ�
    // ����ȊO��1(��荇���֌W�ɂȂ�)��Ԃ�
  if(q[i]==q[j])return -1;
  if(abs(q[i]-q[j])==abs(i-j))return -1;
  return 1;
}

// �����Ŏw�肳�ꂽn�N�C�[�����������֐�
int solve(int n)
{
    int *q;
    q = malloc(sizeof(int) * n); // �Ֆʂ�\���̈�̊��蓖��

    set_queen(q, 0, n);

    return 0;
}

void set_queen(int q[], int m, int n)
{
// �ۑ�1�̏����ɒǉ��ŋL���i�ۑ�2�j
  int i;
  if( m == n){
    // ����ՖʂɊւ��锻�菈��������
    if(safe_all(q,n)==1)
      print_queen(q,n);
    return;
  }
  for( i = 0; i < n; i++){
    q[m] = i;
    set_queen(q, m + 1, n);
  }
}

// �Ֆʂ��e�L�X�g�\��
void print_queen(int q[], int n)
{
// �ۑ�1�𗬗p
  for(int i=0;i<n; i++ ) {
    for(int j=0; j<n; j++ )
      if ( i == q[j] ) printf(" Q"); else printf(" .");
        printf("\n");
    }
    printf("\n"); 
}

// main�֐�
int main(int argc, char **argv)
{
    int m;
    int n;
    int start, end;

    // N�����
    printf("Input a integer(>=1): ");
    scanf("%d", &n);

    if (n <= 0) //0�ȉ��łȂ����`�F�b�N
    {
        printf("N must be a integer than 1\n");
        return 0;
    }

    start = clock();
    m = solve(n);
    end = clock();
    printf("%f sec\n", ((double)(end - start) / CLOCKS_PER_SEC));

    return 0;
}