/* �ċA�֐����g���ėݏ�l���v�Z����v���O���� */
#include "stdio.h"
#include "math.h"

#define MAX_COUNT 10

/* �v�Z���ʂ������o���O���[�o���ϐ� */
double result = 1;

/* �ݏ�v�Z���s���ċA�֐� */
double mult(double n, double times)
{
    result *= n; times--;

    if (times > 0)
        /* ���ȍċA�I�ɌĂяo�� */
        return mult(n, times);
    /* �ċA�������I���� */
    return result;
}

double mypow(double n, double times){
	result = 1;
	return mult(n, times);
}

int main(void)
{
    int i ;

    printf("�Ǝ��̊֐����g���ėݏ�l�����߂�\n");
    /* ����A��Ǝw�����X�V���āA�ݏ�l�����߂� */
    for (i = 1; i < MAX_COUNT; i++){
        printf("��u%d�v�A�w���u%d�v�̗ݏ�l�F%g\n", i, i, mypow(i, i));
    }

    printf("pow()�֐����g���ėݏ�l�����߂�\n");
    /* ����A��Ǝw�����X�V���āA�ݏ�l�����߂� */
    for (i = 1; i < MAX_COUNT; i++){
        printf("��u%d�v�A�w���u%d�v�̗ݏ�l�F%g\n", i, i, pow(i, i));
    }

    return 0;
}



