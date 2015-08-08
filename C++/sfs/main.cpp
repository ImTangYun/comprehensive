#include <stdio.h>
#include <stdint.h>
#include "client.h"

int32_t main(int argc, char** argv)
{
    Client client;
    client.init();
    printf("hello test");
    return 0;
}


