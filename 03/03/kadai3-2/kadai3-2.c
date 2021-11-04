// 3 �̐������^����ꂽ�Ƃ��C�����ɕ��בւ���֐� sort ���쐬����
// ���̂Ƃ��C3�̐����̓|�C���^�̌`�ŗ^��������̂Ƃ���D

// �܂��C��������s���邽�߂ɁC�Q�̕ϐ������ւ���֐� swap ��
// �쐬���Csort �ɂ͕K������𗘗p���邱��
// (swap�͉ۑ�1�̂��̂Ɠ����ł��邪�Csort�ɂ͒l�ł͂Ȃ��C
// �|�C���^���^�����邱�Ƃɒ��ӂ��邱��)

#include <stdio.h>


/*--- nx�Eny���w���I�u�W�F�N�g�̒l������ ---*/
void swap(int *nx, int *ny)
{
  *nx = *ny - *nx;
  *ny -= *nx;
  *nx += *ny;
}

/*--- *n1��*n2��*n3�ƂȂ�悤�ɕ��т����� ---*/
//
// (* ������sort�Ɋւ���L�q�����������邱�� *//
void sort3(int *x, int *y, int *z){
	if(*x > *y) swap(x, y);
	if(*y > *z) swap(y, z);
	if(*x > *y) swap(x, y);
}

int main(void)
{
	int na,nb,nc;
	puts("�O�̐�������͂��Ă��������B");
	printf("����A:");	scanf("%d",&na);
	printf("����B:");	scanf("%d",&nb);
	printf("����C:");	scanf("%d",&nc);

	sort3(&na, &nb, &nc);
	
	puts("�����̒l�������ɕ��ׂ����܂����B");
	printf("����A��%d�ł��B\n",na);
	printf("����B��%d�ł��B\n",nb);
	printf("����C��%d�ł��B\n",nc);
	return 0;
}

