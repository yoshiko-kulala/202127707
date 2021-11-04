#include <stdio.h>
#include <string.h>

/* ���

   ���ȏ���List13-2(�g���Ƒ̏d��ǂݍ���ŕ��ϒl�����߂ĕ\������)���Q�l��, 
   �t�@�C������ǂݍ��񂾌l�f�[�^��̏d���Ƀ\�[�g(����)������ŕ\������
   �v���O�������쐬����. 

   (��: �����̏ꍇ�C�����Ƃ͏��������ɂȂ�ׂ邱�ƁD)

   �f�[�^�`���́C���O(60�����ȓ�) �g��(double�^) �̏d(double�^) �ɂȂ��Ă���D
   ��)
   Taro 170.0 70.2
   Jiro 158.0 80.5

*/

/* Step
   1. �t�@�C�����I�[�v����, �l�f�[�^��ǂݍ���.
   2. �l�f�[�^�̂���, �̏d���Ƀ\�[�g���s��(����).
*/


/* �l�f�[�^ */
typedef struct{
  char name[100];
  double height;
  double weight;
}member;

/* �\���̂���������֐� */
//
/* (* �����ɉ𓚂����������� *) */
void swap_ma(member *p1,member *p2){
	member tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void sort_ma(member m[],int i){
	int cou,subcou;
	for(cou=i-1;cou>0;cou--){
		for(subcou=cou;subcou>0;subcou--){
			if(m[subcou].weight < m[subcou-1].weight){
				swap_ma(&m[subcou],&m[subcou-1]);
			}
		}
	}
}

int main(void)
{
  FILE *fp;
  member ma[10];
    
  char str[10];
  int i = 0;
    
  char filename[60];
    
  printf("�t�@�C���� :"); scanf("%s",filename);
    
  //�t�@�C�����J��
  //�t�@�C�����I�[�v���ł��Ȃ�������true�ƂȂ�
  //
  if((fp = fopen(filename,"r"))==NULL){
    /* (* �����ɉ𓚂����������� *) */
    
    printf("�t�@�C�����I�[�v���ł��܂���B\n");
    return 1;
  }else{
    //�t�@�C�����I�[�v���ł������̏���
    int j;
    int k;
    while(fscanf(fp, "%s%lf%lf",ma[i].name,&(ma[i].height),&(ma[i].weight)) == 3){
      printf("%-10s %5.1f %5.1f\n",ma[i].name,ma[i].height,ma[i].weight);
      i++;
    }
    j=i;
    //�\�[�g���s��
    //
    /* (* �����ɉ𓚂����������� *) */
    /* �\�[�g�̃A���S���Y���ɂ��Ă͈ȑO�̉ۑ�Q�� */
    sort_ma(ma,j);
    
    //�\�[�g���ʂ�\��
    printf("----------SortResult----------\n");
    for(i=0;i<j;i++)
      printf("%-10s %5.1f %5.1f\n",ma[i].name,ma[i].height,ma[i].weight);
    fclose(fp);
  }
  
  return (0);
}
