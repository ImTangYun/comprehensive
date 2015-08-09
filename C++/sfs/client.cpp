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
    int32_t fd = ::open(META_STORAGE, O_APPEND);
    // int32_t ret = ::write(fd, &(meta_datas->size()), (int)sizeof(meta_datas->size()));
    int32_t size = meta_datas->size();
    int32_t ret = ::write(fd, &(size), sizeof(meta_datas->size()));
    for (;iter != meta_datas->end(); ++iter) {
        int32_t ret = ::write(fd, (void*)(&(iter->second)), sizeof(MetaNode));
    }
    ::close(fd);
    return 0;
}

