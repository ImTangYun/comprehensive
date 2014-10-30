#include <stdio.h>
#include "vector.hpp"

int main()
{
    vector<int> x;
    for (int i = 0; i < 100; ++i)
        x.push_back(i);
    for (int i = 0; i < 100; ++i) {
        printf("%d\n", x[i]);
    }
    vector<int>::iterator iter = x.begin();
    for (; iter != x.end(); ++iter) {
        printf("iter: %d    ", *iter);
    }
    printf("\n");
    for (int i = 0; i < 40; ++i) {
        x.pop_back();
    }
    for (int i = 0; i < (int)x.size(); ++i) {
        printf("%d\n", x[i]);
    }
    printf("\n");
    return 0;
}
