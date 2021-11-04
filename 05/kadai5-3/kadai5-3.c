/*
  �t�@�C������w�肳�ꂽ���������̕��͂�ǂݍ��݁C���͂Ɋ܂܂��
  �P��𕪊�����v���O�������쐬����D

  �ȉ��̎菇�ɂ��������āC�v���O�������쐬����

  step1 :
  void load_characters(const char *filename, int cnum, char string[])
  �t�@�C������filename�ɁC��������cnum�Ɏw�肷�邱�ƂŁC
  ���̕��������̕�����ǂݍ��� string �Ɋi�[����֐� load_charcters ��
  �쐬����D

  step2 :
  int string2words(const char *string, int max_num, word wordset[], int max_wnum)
  ������ string ��P�ꂲ�Ƃɐ؂蕪���C�\���� word �ւƊi�[����D
  ���̂Ƃ��C�P��Ƃ́C' '�i�X�y�[�X�j, ','�i�J���}�j,'.'
  '\n'�i�J�ƋL���j�Ƃ���D
  �A���t�@�x�b�g����ѐ����ȊO�̋L���ň͂܂ꂽ�����ł���D�Ⴆ��
  I have a pen. -> [I,have,a,pen] �ƕ��������i��؂�͊܂܂Ȃ��j

  ���̂Ƃ��C������̍ő啶������ max_num �Ƃ���D�������C
  �������ɏI�[�퍆 '\0' ������ꍇ�ɂ́Cmax_num �ȉ��̏ꍇ�ł�������͏I��
  �Ƃ���D

  word �\���͈̂ȉ��̒ʂ�ł���C������ num �ƕ����� word ������.
  �ő啶������ 15�����i�I�[�퍆���܂߂��j�ł���C15�����ȏ�̕���
  ���^������ꍇ�́C����ȍ~�Ȗ�������D

  typedef struct {
    int num;
    char word[16];
  } word;

  max_num �͍ő�P�ꐔ�ł���Cwnum �𒴂���P�ꂪ�܂܂��ꍇ�́C����ȍ~�͖�������D

  �߂�l�͒P�ꐔ�ł���D

  step2-1 :
  step2 ��i�߂邽�߂ɁC�܂��C�ȉ����쐬����D
  int issep(char c)
  c ����؂蕶���ł��邩�ǂ������m�F���C��؂蕶���ł����1���C����ȊO��0��
  �Ԃ��D

  step2-2 :
  ���ɁC��L�𗘗p���Ĉȉ����쐬����D
  int string2word(const char *string, int max_num, int position, word *w)
  ����́Cposition �����ڈȍ~�̕����񂩂�P��𔲂��o���Cw �ւƊi�[���C
  �P����\������ŏI�����̎��̕����̈ʒu��Ԃ��D
  �P�ꂪ������Ȃ������ꍇ�i�^����ꂽ�����ȍ~��؂蕶�� or �ŏI����
  �����ׂċ�؂�L���ł������ꍇ�j�ɂ�0��Ԃ��D

  �Ⴆ��
  string = "I have a pen", position = 3 �Ƃ����ꍇ�C
  word->num = 4, word->word�ɂ� have ���i�[����C�����7��Ԃ�


  step2-3
  ��̊֐���p���邱�ƂŁCstring2words���쐬����D

*/

#include <stdio.h>
#include <string.h>

typedef struct {
  int num;
  char word[16];
} word;

void load_characters(const char *filename, int cnum, char string[]) {
  FILE *fp = NULL;

  // �����ɓ������L�q����
  // ������Ƃ��ēǂݍ��ނ��߁C�ŏI�v�f�ɕ����̏I�[�퍆��ǉ����邱�ƁD
  fp = fopen(filename, "r");
  int i = 0;
  for (; i < cnum; i++) {
  	char ch=fgetc(fp);
    if(ch==EOF)break;
    string[i] = ch;
  }
}

int string2words(const char *string, int max_num, word words[], int max_word) {
  // �����ɉ񓚂��L�q����

  int word_num = 0; // �P��Ƃ��Đ؂�o���ꂽ��������D
  int position = 0; // �ǂ��܂Ŋm�F���s������������D
	int word_pos;
  // while ���[�v��p���ċL�q����Ƃ悢
  // string2word ���P���������i�P��������Ȃ������ꍇ�̕�����
  // ��Ԃ��Ȃ��j���C�������ꂽ�P�ꂪmax_word �𒴂��Ȃ�����C
  // position ��i�߂Ȃ���C���Ԃ� words �ɒP����i�[����D
  for(word_num = 0;word_num<max_word;word_num++){
  	word_pos=0;
  	while(string[position]!=',' && string[position]!=' ' && string[position]!='\n'){
  		words[word_num].word[word_pos]=string[position];
  		word_pos++;
  		position++;
  		//if(position>max_word)break;
  	}
  	while(string[position]==','|| string[position]==' ' || string[position]=='\n')position++;
  	words[word_num].num=word_pos+1;
  	if(string[position]=='\0')return word_num+1;
  }
  return word_num+1;
}

int main() {
  char *filename = "ihaveapen.txt";
  char string[1024] = "";
  int max_str = 1023;
#define MAX_WORD 16
  word words[MAX_WORD] = {};
  int cnum = 0, word_num = 0;
  int i;

  // �������ǂݍ���
  cnum = load_characters(filename, max_str, string);

  printf("loaded strings\n");
  printf("[%s]\n", string);


  // ��������
  word_num = string2words(string, cnum, words, MAX_WORD);
  printf("separated wors\n");
  for (i = 0; i < word_num; i++) {
    printf("[%s]\n", words[i].word);
  }

  return 0;

}
