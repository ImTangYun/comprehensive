#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "client.h"


void test_init_save()
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
}

int32_t main(int argc, char** argv)
{
    Client client;
    char data[] = "hello this is my data";
    uint64_t file_id = client.write(data, strlen(data));
    int64_t file_length = client.get_length(file_id);
    char *buf = new char[file_length + 1];
    int64_t ret = client.read(file_id, buf, file_length);
    buf[file_length] = '\0';
    printf("file_id:%d,file_length:%d, %s\n", (int32_t)file_id,
            (int32_t)file_length, buf);
    return 0;
}


