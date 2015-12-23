//
//
//
#include <string>
#include <stdint.h>
#include <iostream>
#include "skip_list.h"

using namespace std;
using namespace lab;

void rand_test(int32_t num)
{
    skip_list<int32_t, int32_t> sk;
    int32_t levels[16];
    for (int32_t i = 0; i < 16; ++i) levels[i] = 0;
    for (int32_t i = 0; i < num; ++i) {
        ++levels[sk.generate_random_level(MAX_LEVEL)];
    }
    for (int32_t i = 0; i < 16; ++i) {
        cout << "level " << i << " times:" << levels[i] << endl;
    }
}

int main()
{
    skip_list<int32_t, int32_t> sl;
    for (int32_t i = 1; i < 250; ++i) {
        sl.add(i, i);
        // sl.dump();
    }

    skip_list<int32_t, int32_t>::iterator iter = sl.begin();
    for (; iter != sl.end(); ++iter) {
        printf("key: %d value: %d\n", iter->key_, *(iter->value_));
    }

    iter = sl.find(100);
    if (iter == sl.end()) {
        cout << "not found 100" << endl;
    } else {
        cout << "value of key 100 is " << *(iter->value_) << endl;
    }
    iter = sl.find(1000);
    if (iter == sl.end()) {
        cout << "not found 1000" << endl;
    } else {
        cout << "value of key 1000 is" << *(iter->value_) << endl;
    }

    cout << "sl contains 123?" << sl.contains(123) << endl;
    cout << "sl contains 1234?" << sl.contains(1234)<< endl;
    sl.remove(123);
    cout << "sl contains 123?" << sl.contains(123) << endl;

    int32_t size = sl.size();
    iter = sl.find(100);
    cout << "size: " << size << ",value of key 100 is " << *(iter->value_) << endl;
    sl.add(100, 1001);
    size = sl.size();
    iter = sl.find(100);
    cout << "size: " << size << ",value of key 100 is " << *(iter->value_) << endl;
    rand_test(100000);
    return 0;
}


