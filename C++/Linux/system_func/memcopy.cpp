//
// 内存拷贝函数，考虑到了内存地址重叠的情况
//

#include <stdio.h>

void memcopy(void* src, void* dst, int length)
{
    if (length <= 0) return;
    if ((char*)src >= (char*)dst
            && (char*)src <= (char*)dst + length) {
        char* p1 = (char*) src;
        char* p2 = (char*) dst;
        while (length > 0) {
            *p2++ = *p1++;
            --length;
        }
    } else {
        char* p1 = (char*) src + length - 1;
        char* p2 = (char*) dst + length - 1;
        while (length > 0) {
            *p2-- = *p1--;
            --length;
        }
    }
}

int main()
{
    char p1[] = "abc";
    char p2[4];
    memcopy(p1, p2, 4);
    printf("%s\n", p2);
    int B[] = {0, 0, 0, 0, 0, 1,2,3,4,5,6,7,8,9,0, 0, 0, 0, 0, 0, 0, 0};
    int *A = B + 5;
    memcopy(A, B, 10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        printf("%d  ", B[i]);
    }
    printf("\n");
    return 0;
}
