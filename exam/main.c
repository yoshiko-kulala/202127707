// main �����܂ޖ{���ł���D
// �K�v�ȃt�@�C�����C���N���[�h����ƂƂ��Ɋ֐����ɋL�q���s��
// main ������������

#include <stdio.h>
#include "studata.h"

int main(){
  int num;
  // �K�v�ȕϐ�������Βǉ����邱�ƁD
  studata *data;

  // load_studata ��p���ăt�@�C���̏���ǂݍ���
  // �ǂݍ��ރt�@�C���� data.csv �ł���D
  // �K�؂ɏ���������
  data = load_studata("data.csv",&num);
  
  // ���e��\�����C�K�؂Ƀf�[�^���ǂݍ��߂Ă��邩�m�F����
  printf("load_data-------------------------------\n");
	print_studata(data,num);
  // �g���Ń\�[�g������C�\��������
	sor_by_height(num,data);
	
  printf("\nheight_sort_data-------------------------------\n");
	print_studata(data,num);

  // ���O�Ń\�[�g������C�\��������
  sort_by_name(num,data);
	
  printf("\nname_sort_data-------------------------------\n");
	print_studata(data,num);
  
  return 0;
}
