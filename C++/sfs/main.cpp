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

uint64_t write(char* file_name, Client &client)
{
    if (file_name == NULL) {
        printf("file name is null");
        return -1;
    }
    FILE* fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("file %s did not exist!", file_name);
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int64_t flength = ftell(fp);
    char* buff = new char[flength + 1];
    fseek(fp, 0L, SEEK_SET);
    fread(buff, 1, flength, fp);
    buff[flength] = '\n';
    printf("test.dat:%s\n", buff);
    uint64_t file_id = client.write(buff, flength);
    delete [] buff;
    printf("file %s is wrote as file_id %d\n", file_name, file_id);
    return file_id;
}

int32_t main(int argc, char** argv)
{
    Client client;
    client.init();
    printf("meta data: %s\n", client.to_string().c_str());
    uint64_t file_id = write("test.dat", client);
    int64_t file_length = client.get_length(file_id);
    char *buf = new char[file_length];
    int64_t ret = client.read(file_id, buf, file_length);
    buf[file_length] = '\0';
    printf("file_id:%d,file_length:%d, data:%s\n", (int32_t)file_id,
            (int32_t)file_length, buf);
    client.save_metadata();
    return 0;
}


