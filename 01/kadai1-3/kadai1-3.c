/* �z��̂ƂȂ荇���v�f�������ł��邱�Ƃ𒲂ׂ�v���O���� */
#include "stdio.h"

int main(void)
{
    int narray[8] = { 120, 50, 70, 70, 100, 20, 30, 80 };
    int i; /* ���[�v����ϐ� */

    for (i = 0; i < 7; i++) {
        if (narray[i] == narray[i + 1]) {
            printf("�z��̑� %d �v�f�Ƒ� %d �v�f�̒l�͓����ł��B\n", 
                   i + 1, i + 2);
        }
    }

    return 0;
}
