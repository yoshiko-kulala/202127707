//�t�@�C�����̕����̂����C�A���t�@�x�b�g�����J�E���g����

// ���

/* 
�t�@�C������ǂݍ��񂾕����̂����C�������Ƒ啶���̃A���t�@�x�b�g�݂̂�
�J�E���g���ĕ\������v���O�������쐬���Ȃ����D
*/

// step
/*
  1 �ϐ�filename�Ɋi�[���ꂽ�t�@�C���̃I�[�v���������s���B

  2 �t�@�C������1�������ǂݍ���ŃA���t�@�x�b�g���ǂ������ׂăA���t�@
  �x�b�g�ł���΃J�E���g����B
*/

#include <stdio.h>

int main(void){
  FILE	*fp;
  int		ch;
  char filename[60];
	
  int		count = 0;
  scanf("%s",filename);

  printf("���̓t�@�C�����F%s\n",filename);
  //�t�@�C���I�[�v������
  //
  /* (* �����ɉ𓚂����������� *) */
  if((fp = fopen(filename,"r"))==NULL){
    printf("Cannot open %s\n", filename);
    return 0;
  }
  //�������J�E���g����
  //
  /* (* �����ɉ𓚂����������� *) */
	while((ch=fgetc(fp))!=EOF){
		if((ch>='A' && ch<='Z')||ch>='a' && ch<='z')count++;
	}
  printf("Number of Alphabet in %s is %d \n", filename, count);
  fclose(fp);
	
  return 0;
}
