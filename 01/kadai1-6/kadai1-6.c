/* �֐��̉������̒l��ύX����v���O���� */
#include "stdio.h"
#include "math.h"

/* �������̒l��ύX����֐� */
void change_param(int* n)
{
    /* ������n�̒l���Βl�ɕϊ����� */
    *n = abs(*n);
}

int main(void)
{
    int i; /* ���[�v����ϐ� */
    int narray[] = { -300, -100, -650, -1000, -240, -500 };

    for (i = 0; i < sizeof narray / sizeof(int); i++)
        /* change_param()�֐����Ăяo�� */
        change_param(&narray[i]);

    /* change_param()�֐����Ăяo�������Ƃ̔z��narray�̗v�f�̒l�𒲂ׂ� */
    printf("change_param()�֐��Ăяo�����narray�̗v�f�𒲂ׂ�\n");
    for (i = 0; i < sizeof narray / sizeof(int); i++)
        printf("�v�f[%d]�̒l�F%d\n", i, narray[i]);
    printf("\n");

    return 0;
}


