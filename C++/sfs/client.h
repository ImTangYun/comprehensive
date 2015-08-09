#ifndef _CLIENT_H_
#define _CLIENT_H_
#include <stdint.h>
#include <unordered_map>

using std::unordered_map;
struct MetaNode
{
    uint64_t _file_id;
    int64_t _start;
    int64_t _length;
    MetaNode()
    {
    
    }
    MetaNode(uint64_t file_id, int64_t start, int64_t length)
    {
        _file_id = file_id;
        _start = start;
        _length = length;
    }
};
class Client
{
    public:
        Client();

        int32_t init();

        int32_t write(char* buffer, int64_t length);

        int32_t get_length(uint64_t file_id);

        int32_t read(uint64_t file_id, char* buffer, int64_t &length);
        int32_t save_metadata();
        
        // for test
        unordered_map<uint64_t, MetaNode>* get_meta_datas()
        {
            return meta_datas;
        }

    private:
        unordered_map<uint64_t, MetaNode> *meta_datas;
        MetaNode latest_data;
};

#endif
