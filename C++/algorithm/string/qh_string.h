#ifndef QIHOO_STRING_H_
#define QIHOO_STRING_H_

#include <stdlib.h>

namespace qh
{
    class string {
    public:
        //ctor
		//ʱ�临�Ӷ�O��15��
		//�ռ临�Ӷ�O��15��
        string();

 		//ʱ�临�Ӷ�O��strlen��s����
		//�ռ临�Ӷ�O��strlen��s����
		string(const char* s);

 		//ʱ�临�Ӷ�O��strlen��len����
		//�ռ临�Ӷ�O��strlen��len����
        string(const char* s, size_t len);

  		//ʱ�临�Ӷ�O��rhs.size()��
		//�ռ临�Ӷ�O��rhs.size()��
        string(const string& rhs);

  		//ʱ�临�Ӷ�O��rhs.size()��
		//�ռ临�Ӷ�O��rhs.size()��
        string& operator=(const string& rhs);

 		//ʱ�临�Ӷ�O��strlen��rhs����
		//�ռ临�Ӷ�O��strlen��rhs����
        string& operator=(const char* rhs);
 		//ʱ�临�Ӷ�O��rhs.size() + size()��
		//�ռ临�Ӷ�O��rhs.size() + size()��
		string& operator+(const string& rhs);

        //dtor
        ~string();

        //get
 		//ʱ�临�Ӷ�O��1��
        size_t size() const;
 		//ʱ�临�Ӷ�O��1��
        const char* data() const;
 		//ʱ�临�Ӷ�O��1��
        const char* c_str() const;
 		//ʱ�临�Ӷ�O��1��
		size_t capacity() const;

        // set & get
 		//ʱ�临�Ӷ�O��1��
        char &operator[](size_t index);

 		//���ʱ�临�Ӷ�O��1�������ʱ�临�Ӷ�O(size())
		void reserve(int c);
    private:
        char*  data_;
        size_t len_;
		size_t cap;

  		//ʱ�临�Ӷ�O��len��
		//�ռ临�Ӷ�O��len��
		char* safe_alloc(size_t len);
    };
}

#endif


