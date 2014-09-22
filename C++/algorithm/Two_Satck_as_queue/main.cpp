#include <stdio.h>
#include "queue.h"

using myspace::queue;
int main()
{
    queue<int> q;
    for (int i = 0; i < 10; ++i) {
        q.push(i);
    }
    int x = 5;
    while (x) {
        printf("out: %d\n", q.top());
        q.pop();
        --x;
    }
    printf("+++++++++\n");
    for (int i = 10; i < 20; ++i) {
        q.push(i);
    }
    while (!q.empty()) {
        printf("out: %d\n", q.top());
        q.pop();
    }
    return 0;
}
