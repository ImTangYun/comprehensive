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

void write(char* buf, int64_t length, Client &client)
{
    uint64_t file_id = client.write(buf, length);
    printf("write file_id %d\n", file_id);
}

int32_t main(int argc, char** argv)
{
    Client client;
    client.init();
    char buff[100];
    printf("meta data: %s\n", client.to_string().c_str());
    for (int i = 0; i < 10; ++i) {
        int length = snprintf(buff, 100, "this is the %dth data", i);
        write(buff, length, client);
    }
    printf("meta data: %s\n", client.to_string().c_str());
    int64_t file_length = client.get_length(27);
    char *buf = new char[file_length + 1];
    int64_t ret = client.read(5, buf, file_length);
    buf[file_length] = '\0';
    printf("file_id:%d,file_length:%d, data:%s\n", (int32_t)5,
            (int32_t)file_length, buf);
    client.save_metadata();
    return 0;
}


