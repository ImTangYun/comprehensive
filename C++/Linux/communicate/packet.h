//
//
//
//

#ifndef PACKET
#define PACKET
#include <stdint.h>
#include "singleton.h"
#include "channel.h"
class Packet
{
    public:
        Packet():channel_id_(Singleton<Channel>::Instance()->max_id()) {}
        void set_packet(char* data, int64_t data_length)
        { 
            data_ = data; 
            data_length_ = data_length;
        }

        void set_channel_id(int32_t channel_id) {channel_id_ = channel_id;}
        int32_t channel_id() {return channel_id_;}

        char* data() {return data_;}
        int64_t data_length() {return data_length_;}
    private:
        char* data_;
        int64_t data_length_;
        int32_t channel_id_;
};

#endif
