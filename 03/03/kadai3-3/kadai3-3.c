#include<stdio.h>
// ���Fn �̔z��̐擪�������|�C���^���^����ꂽ��
// ���̔z����~���ɕ��בւ���֐� bubble_sort ������������D
// �܂��C�z��ɒl�������邽�߂̊֐�
// setarray������������D


/*--- nx�Eny���w���I�u�W�F�N�g�̒l������ ---*/
void swap(int *nx, int *ny)
{
  int temp = *nx;
  *nx = *ny;
  *ny = temp;
}

void setarray(int *vc,int a,int b,int c,int d,int e)
{
  //
  //(* �����ɉ𓚂����������� *)
  // 1�Ԗڂɂ�a, 2�Ԗڂɂ�b �Ə��ԂɂȂ�悤�ɓ��͂��邱��
	vc[0]=a;vc[1]=b;vc[2]=c;vc[3]=d;vc[4]=e;
}

void bubble_sort(int *data, int n){
  //
  //(* �����ɉ𓚂����������� *)
  // data[0] > data [1] > ... > data[4]
  // �z��̃\�[�g�́C�O��p�����A���S���Y�������̂܂܎g�p���Ă悢�D
	if(n==1)return;
	else{
		for(int i=0;i<n-1;i++){
			if(data[i]>data[i+1])
			swap(&data[i],&data[i+1]);
		}
	}
	bubble_sort(data,n-1);
}

int main(void)
{
  int i,a,b,c,d,e;
  int ary[5] = {0};

  printf("�z��ɑ�����鐮����5���͂��Ă�������\n");
  printf("����1�F"); 
  scanf("%d",&a);
  printf("����2�F");
  scanf("%d",&b);
  printf("����3�F");
  scanf("%d",&c);
  printf("����4�F");
  scanf("%d",&d);
  printf("����5�F");
  scanf("%d",&e);
  putchar('\n');

  setarray(ary,a,b,c,d,e);

  for(i=0;i<5;i++)
    printf("ary[%d] = %d\n",i,ary[i]);

  bubble_sort(ary,5);
  printf ("\nbabble sort!\n");
  for(i=0;i<5;i++)
    printf("ary[%d] = %d\n",i,ary[i]);

  return (0);
}

