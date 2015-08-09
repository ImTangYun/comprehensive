#include <stdio.h>
#include <stdint.h>
#include "client.h"

int32_t main(int argc, char** argv)
{
    Client client;
    unordered_map<uint64_t, MetaNode>* meta_datas = client.get_meta_datas();
    for (uint64_t i = 0; i < 10; ++i) {
        MetaNode metanode(i, (int64_t)i * 10, 10);
        (*meta_datas)[i] = metanode;
    }
    client.save_metadata();
    // client.init();
    printf("hello test");
    return 0;
}


