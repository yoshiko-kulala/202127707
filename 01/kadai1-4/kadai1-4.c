/* 2�̐����ƕ��������_���̕��ϒl�����߂�v���O���� */
#include "stdio.h"

#define MAX_LEN 10

int main(void)
{
    /* int�^�̔z�� */
    int narray1[] = { 11, 23, 35, 48, 56, 66, 73, 84, 99, 101 };
    int narray2[] = { 12, 24, 30, 41, 52, 67, 75, 78, 91, 107 };

    /* float�^�̔z�� */
    float farray1[] = { 11.0f, 23.0f, 35.0f, 48.0f, 56.0f, 66.0f,
                        73.0f, 84.0f, 99.0f, 101.0f };
    float farray2[] = { 12.0f, 24.0f, 30.0f, 41.0f, 52.0f, 67.0f,
                        75.0f, 78.0f, 91.0f, 107.0f };

    int i, num;    /* i�̓��[�v����ϐ� */
    float ft;

    /* 2�̐����̕��ϒl�����߂� */
    for (i = 0; i < MAX_LEN; i++) {
        num = (narray1[i] + narray2[i]) / 2;
        printf("%d��%d�̕��ϒl�F%d\n", narray1[i], narray2[i], num);
    }

    /* 2�̕��������_���̕��ϒl�����߂� */
    for (i = 0; i < MAX_LEN; i++) {
        ft = (farray1[i] + farray2[i]) / 2;
        printf("%f��%f�̕��ϒl�F%f\n", farray1[i], farray2[i], ft);
    }

    return 0;
}


