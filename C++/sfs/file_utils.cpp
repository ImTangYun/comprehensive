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
     return access(file_name, 0) > 0;
}
