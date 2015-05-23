#include <stdio.h>

int core_count(int monthes)
{
    int *tmp = new int[monthes];
    if (monthes <= 3) return 1;
    tmp[0] = 1;
    tmp[1] = 1;
    tmp[2] = 1;
    for (int i = 3; i < monthes; ++i) {
        tmp[i] = tmp[i - 1] + tmp[i - 3];
    }
    int result = tmp[monthes - 1];
    delete [] tmp;
    return result;
}
int core_count_limited(int monthes)
{
    return -1;
}
int count_rabbits1(int orginal_num, int monthes)
{
    if (monthes < 25) {
        return orginal_num * core_count(monthes);
    } else {
        return orginal_num * core_count_limited(monthes);
    }
}
int main()
{
    for (int i = 1; i < 10; ++i) {
        printf("the %dth rabbits num is: %d\n", i, count_rabbits1(1, i));
    }
    return 0;
}
