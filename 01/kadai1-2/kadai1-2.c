/* ���\������v���O���� */
#include "stdio.h"

int main(void)
{
    int n = 0;

    /* n��99���傫���Ȃ�΃��[�v���I������ */
    while (++n > 0 && n < 100) {
        /* ��Ȃ�\������ */
        if (n % 2)
            printf("%d ", n);
    }

    return 0;
}

