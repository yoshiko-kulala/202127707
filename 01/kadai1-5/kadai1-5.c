/* �Ăяo���̂��тɌĂяo���񐔂�Ԃ��֐����g���v���O���� */
#include "stdio.h"

#define MAX_COUNT 5

/* ���[�J���ϐ����g���֐� */
int getcount()
{
    /* �֐��̃��[�J���ϐ���錾�A���������� */
    static int count = 0;

    /* ���[�J���ϐ����C���N�������g���ĕԂ� */
    return ++count;
}

int main(void)
{
    int i; /* ���[�v����ϐ� */

    /* getcount()�֐����Ăяo�� */
    for (i = 0; i < MAX_COUNT; i++) {
        printf("%d ", getcount());
    }
    printf("\n");

    return 0;
}
