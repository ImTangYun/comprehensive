//
//
//
#include <string>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <map>
#include "skip_list.h"

using namespace std;
using namespace lab;

class TimeCounter
{
    public:
        TimeCounter():capacity_(10)
        {
            gettimeofday(&starttime_,0);
        }
        TimeCounter(int capacity):capacity_(capacity)
        {
            gettimeofday(&starttime_,0);
        }
        double GetTimeCosts(int num)
        {
            if (num >= times_.size() && times_.size() > 0) {
                num = times_.size();
            } else {
                return 0;
            }
            return times_[num - 1];
        }
        void AddNow()
        {
            struct timeval endtime;
            gettimeofday(&endtime,0);
            double timeuse = 1000000*(endtime.tv_sec - starttime_.tv_sec)
                + endtime.tv_usec - starttime_.tv_usec;
            timeuse /=1000;
            times_.push_back(timeuse);
        }
    private:
        vector<double> times_;
        int capacity_;
        struct timeval starttime_;
};

void ordered_insert(int32_t* keys, int32_t length,
        skip_list<int32_t, int32_t> &t_sk_list);
void map_insert(int32_t* keys, int32_t length,
        map<int32_t, int32_t> &map_);
void disordered_insert();

void ordered_remove();
void disordered_remove();

void find();

#define BENCH_SIZE (1000000)
// #define SKIP_LIST_TEST
int main()
{
    int32_t* keys = new int32_t[BENCH_SIZE];
    int32_t i = 0;
    for (; i < BENCH_SIZE; ++i) {
        keys[i] = i;
    }
    TimeCounter time_counter;
    printf("begining\n");
#ifdef SKIP_LIST_TEST
    printf("skip_list test\n");
    skip_list<int32_t, int32_t> t_sk_list;
    ordered_insert(keys, BENCH_SIZE, t_sk_list);
#else
    printf("map test\n");
    map<int32_t, int32_t> map_;
    map_insert(keys, BENCH_SIZE, map_);
#endif
    time_counter.AddNow();
    printf("ordered insert %d para cost %.02fms\n",
            BENCH_SIZE, time_counter.GetTimeCosts(1));

    return 0;
}


void ordered_insert(int32_t* keys, int32_t length,
        skip_list<int32_t, int32_t> &t_sk_list)
{
    for (int32_t i = 0; i < length; ++i) {
        t_sk_list.add(keys[i], 0);
    }
}
void map_insert(int32_t* keys, int32_t length,
        map<int32_t, int32_t> &map_)
{
    for (int32_t i = 0; i < length; ++i) {
        map_[keys[i]] = 0;
    }
}
