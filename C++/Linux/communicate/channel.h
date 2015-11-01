//
//
//
#ifndef CHANNEL
#define CHANNEL
#include <stdint.h>
#include <pthread.h>
class Channel
{
    public:
        Channel():max_id_(0)
        {
            pthread_mutex_init(&mutex_, NULL); 
        }
        int32_t GenerateNewId()
        {
            pthread_mutex_lock(&mutex_);
            ++max_id_;
            pthread_mutex_unlock(&mutex_);
            return max_id_;
        }
        int32_t max_id() { return max_id_; }
        int32_t ChannelNum() { return max_id_ + 1; }
    private:
        int32_t max_id_;
        pthread_mutex_t mutex_;
};
#endif
