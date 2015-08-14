#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#include "file_utils.h"
int32_t FileUtils::get_file_size(const char* file_name)
{
    if (!is_exists_file(file_name)) {
        return -1;
    }
    struct stat tbuf;
    stat(file_name, &tbuf);
    return tbuf.st_size;
}

bool FileUtils::is_exists_file(const char* file_name)
{
    printf("%s's access %d\n", file_name, access(file_name, F_OK));
    return (access(file_name, F_OK) == 0);
}

int32_t FileUtils::write(char* buff, int64_t length, char* file_name)
{
    if (is_exists_file(file_name)) {
        printf("file %s exists!\n", file_name);
        return -1;
    }
    FILE* fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("open %s failed!\n", file_name);
        return -2;
    }
    int32_t ret = fwrite(buff, 1, length, fp);
    return ret;
}
