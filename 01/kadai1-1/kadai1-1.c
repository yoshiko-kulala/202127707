/* 4�񂲂Ƃɉ��s���ĕ\������v���O���� */
#include "stdio.h"

/* �O���[�o���ϐ���錾�A���������� */
int count = 4;

int main(void)
{
    int i; /* ���[�v����ϐ� */
    int count_l = 0; /* ���[�J���ϐ���錾�A���������� */

    for (i = 0; i < 20; i++) {
        /* 4�񂲂Ƃɉ��s���� */
        if (i != 0 && i % count == 0)
            printf("\n");
        /* i�̒l��\������ */
        printf("%d ", i);
        count_l++;
   }
    /* count�̒l��\������ */
    printf("\ncount�̒l�F%d\n", count_l);

    return 0;
}

