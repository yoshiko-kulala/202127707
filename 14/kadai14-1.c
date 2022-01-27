#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 1; //���̐����J�E���g

void print_border(int n);
void print_queen(int q[], int n);

// �Ֆʂ̑S�p�^�[���𐶐����鏈��
void set_queen(int q[], int m, int n);

void set_queen(int q[], int m, int n)
{
  // ���� q:�Ֆʂ̔z��Cm: ��m��ڂ̔Ֆʂ��쐬�i�ċA�����ŗ��p), n:�Ֆ�q�̗v�f��
  // �����ɏ����������i�ۑ�1)
  int i;
  if( m == n){
    // ����ՖʂɊւ��锻�菈��������
  	print_queen(q,n);
    return;
  }
  for( i = 0; i < n; i++){
    q[m] = i;
    set_queen(q, m + 1, n);
  }
  // �ċA�����̎������@�ɂ���Ă͈����̎�����⏕�֐����쐬���Ă��悢
}

// �����Ŏw�肳�ꂽn�N�C�[�����������֐�(�ۑ�1�ł͉��������͊܂܂�Ȃ��j
int solve(int n)
{
    int *q;
    q = malloc(sizeof(int) * n); // �Ֆʂ�\���̈�̊��蓖��

    set_queen(q, 0, n);
    return 0;
}

void print_queen(int q[], int n)
{
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

    solve(n);

    return 0;
}