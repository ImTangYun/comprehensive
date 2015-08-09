#include <stdint.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unordered_map>
#include "common.h"
#include "client.h"

using std::unordered_map;
Client::Client()
{
    meta_datas = new unordered_map<uint64_t, MetaNode>();
}

int32_t Client::init()
{
    int32_t fd = ::open(META_STORAGE, O_RDONLY);
    int32_t size;
    MetaNode meta_node;
    ::read(fd, &size, sizeof(size));
    for (int32_t j = 0; j < size; ++j) {
        ::read(fd, &meta_node, sizeof(meta_node));
        (*meta_datas)[meta_node._file_id] = meta_node;
    }
    printf("file num is: %d\n", size);
    return 0;
}

int32_t Client::write(char* buffer, int64_t length)
{

    return 0;
}

int32_t Client::get_length(uint64_t file_id)
{

    return 0;
}

int32_t Client::read(uint64_t file_id, char* buffer, int64_t &length)
{

    return 0;
}
int32_t Client::save_metadata()
{
    unordered_map<uint64_t, MetaNode>::iterator iter = meta_datas->begin();
    int32_t fd = ::open(META_STORAGE, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    // int32_t ret = ::write(fd, &(meta_datas->size()), (int)sizeof(meta_datas->size()));
    int32_t size = meta_datas->size();
    printf("meta_datas size:%d\n", size);
    int32_t ret = ::write(fd, &(size), sizeof(size));
    for (;iter != meta_datas->end(); ++iter) {
        int32_t ret = ::write(fd, (void*)(&(iter->second)), sizeof(MetaNode));
    }
    ::close(fd);
    return 0;
}

