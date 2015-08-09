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
    printf("meta data: %s\n", client.to_string().c_str());
    client.save_metadata();
    Client client1;
    client1.init();
    printf("meta data: %s\n", client1.to_string().c_str());
    printf("hello test\n");
    return 0;
}


