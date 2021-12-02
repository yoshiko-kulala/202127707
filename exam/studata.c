// �������1
// ����t�@�C���Ɋw���̐g���̏d�Ɋւ���f�[�^���܂܂�Ă���D
// ���̃f�[�^��ǂݍ���ł��ꂼ��̏����\���̂Ɋi�[���C�������s�������D
// �ȉ��̖��ɓ�����D
// �Ȃ��C�K�v������ΐV�K�Ɋ֐���ǉ����Ă��ǂ��D

// 2. ���̍\���̂ɑ΂��Ēl��������֐� set_studata ���쐬����D
//    �������Cset_studata �͈ȉ��̂悤�ɒ�`�������̂Ƃ���D
//    ������̃R�s�[�ɗ��ӂ��邱�ƁD
#include "studata.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void set_studata(studata *data, char *name,int age,
		 double weight, double height){
    //name�̃R�s�[
    mystrcpy(data->name,name);
    //���̑��̃R�s�[
    data->age=age;
    data->weight=weight;
    data->height=height;
}

// 3. �t�@�C������w������ǂݍ���� studata �̔z��ɏ����i�[����
//    �֐����쐬����D
//    �t�@�C���Ɋ܂܂��f�[�^�̐��͕s���ł��邪�C1�s�ڂɃf�[�^�̐����L�q
//    ����Ă���D
// ��F(�f�[�^�̐���2�Ƃ���)
// 2
// Chris 25 180.0 65.0
// Bob 25 180.0 65.0
//     �f�[�^�̐��ɍ��킹�ēK�؂ɔz��𓮓I�������Ƃ��Ċm�ۂ��C���̔z��
//     �ɏ����i�[���ĕԂ� load_studata ���쐬����D
//     �Ȃ��C�f�[�^�̊i�[�ɂ� 2 �ō쐬���� set_studata ��K���p���邱��
///    �܂��Cnum �͐����^�̃|�C���^�ł���C���̃|�C���^�̎����ϐ���
//     �ǂݍ��܂ꂽ�f�[�^�̐����i�[����D
//     �ǂݍ��݂��I������t�@�C���ɂ��Ă͕K���N���[�Y���邱�ƁD



studata *load_studata(char *filename, int *num){
	//�t�@�C���J��
   FILE	*fp;
   fp = fopen(filename,"r");
   fscanf(fp,"%d",num);
   //�m�ۂ��ׂ���������
   //printf("%d",num);
   studata *load;
   load = (studata*)calloc(*num,sizeof(studata));
   int iii;
   for(iii=0;iii<*num;iii++){
   		char load_name[33];
   		int load_age;
   		double load_weight,load_height;
   		fscanf(fp, "%s %d %lf %lf", load_name, &load_age, &load_height, &load_weight);
   		//printf( "%s %d %lf %lf\n", &load_name, load_age, load_height, load_weight);
   		set_studata(&load[iii],load_name,load_age, load_height, load_weight);
   }  
   return load;
}

// 4. �m�F�̂��߂ɔz��Ɋ܂܂��������Ԃɕ\������ print_studata ���쐬����D
void print_studata(studata *data, int num){
	int iii=0;
	studata *pos=data;
	for(iii=0;iii<num;iii++){
		printf("No.%d\t%s\t%d\t%lf\t%lf\n",iii,&data->name,data->age,data->weight,data->height);
		data++;
	}
	data=pos;
}

// 5. �z���g���ɂ��������ă\�[�g����֐� sort_by_height ���쐬����D
void sor_by_height(int num, studata *data){
	int iii,jjj;
	studata *pos=data;
	for(iii=0;iii<num;iii++){
		for(jjj=0;jjj<num-1;jjj++){
			if(data->weight > (data+1)->weight){
				swap_s(data->name,(data+1)->name);
				int_swap(&data->age,&(data+1)->age);
				swap_double(&data->weight,&(data+1)->weight);
				swap_double(&data->height,&(data+1)->height);
			}
			data++;
		}
		data=pos;
	}
}

// 6. �z����w���̖��O�ɂ��������ă\�[�g������
//    �\�[�g���� strcmp �ɂ��^�����鏇���֌W�ɏ]�����̂Ƃ��C�\�[�g��
//    ���s����֐� sort_by_name ���쐬����D�Ȃ��Cnum �͓ǂݍ��񂾃f�[�^�̐�
//    �ł���D
//    �֐��́C������2�������Ƃ��Ď����C strcmp(str1, str2) �Ƃ����Ƃ�
//    str �̕����������O�ł���� 0��菬�����l���C���ł����0���傫���l��
//    �����ł���� 0 ��Ԃ��D
void sort_by_name(int num, studata *data){
	int iii,jjj;
	studata *pos=data;
	for(iii=0;iii<num;iii++){
		for(jjj=0;jjj<num-1;jjj++){
			int kkk=0;
			while(data->name[kkk] == (data+1)->name[kkk])kkk++;
			if(data->name[kkk] > (data+1)->name[kkk]){
				swap_s(data->name,(data+1)->name);
				int_swap(&data->age,&(data+1)->age);
				swap_double(&data->weight,&(data+1)->weight);
				swap_double(&data->height,&(data+1)->height);
			}
			data++;
		}
		data=pos;
	}
}

// 7. �ȏ�̊֐��� main.c �Ɋ܂܂�� main ������Ăяo�����D
//    �Ăяo���ɕK�v�ȏ�� studata.h �ɋL�q���C��L�֐����e�X�g���邽�߂�
//    �v���O������main�֐��ɋL�q����D
void mystrcpy(char *to, const char *from){
	int i=0;
	for(i=0;from[i]!='\0';i++){
		to[i]=from[i];
	}
}


void int_swap(int *p1,int *p2){
   *p1 = *p2 - *p1;
   *p2 -= *p1;
   *p1 += *p2;
}

void swap_double(double *p1,double *p2){
   *p1 = *p2 - *p1;
   *p2 -= *p1;
   *p1 += *p2;
}

void swap_s(char *to, char *from){
	int i=0;
	char tmp[33]={'\0'};
	for(i=0;from[i]!='\0';i++){
		tmp[i]=from[i];
	}
	for(i=0;i<33;i++)from[i]='\0';
	for(i=0;to[i]!='\0';i++){
		from[i]=to[i];
	}
	for(i=0;i<33;i++)to[i]='\0';
	for(i=0;tmp[i]!='\0';i++){
		to[i]=tmp[i];
	}
}