#ifndef QIHOO_STRING_H_
#define QIHOO_STRING_H_

#include <stdlib.h>

namespace qh
{
    class string {
    public:
        //ctor
		//时间复杂度O（15）
		//空间复杂度O（15）
        string();

 		//时间复杂度O（strlen（s））
		//空间复杂度O（strlen（s））
		string(const char* s);

 		//时间复杂度O（strlen（len））
		//空间复杂度O（strlen（len））
        string(const char* s, size_t len);

  		//时间复杂度O（rhs.size()）
		//空间复杂度O（rhs.size()）
        string(const string& rhs);

  		//时间复杂度O（rhs.size()）
		//空间复杂度O（rhs.size()）
        string& operator=(const string& rhs);

 		//时间复杂度O（strlen（rhs））
		//空间复杂度O（strlen（rhs））
        string& operator=(const char* rhs);
 		//时间复杂度O（rhs.size() + size()）
		//空间复杂度O（rhs.size() + size()）
		string& operator+(const string& rhs);

        //dtor
        ~string();

        //get
 		//时间复杂度O（1）
        size_t size() const;
 		//时间复杂度O（1）
        const char* data() const;
 		//时间复杂度O（1）
        const char* c_str() const;
 		//时间复杂度O（1）
		size_t capacity() const;

        // set & get
 		//时间复杂度O（1）
        char &operator[](size_t index);

 		//最好时间复杂度O（1），最差时间复杂度O(size())
		void reserve(int c);
    private:
        char*  data_;
        size_t len_;
		size_t cap;

  		//时间复杂度O（len）
		//空间复杂度O（len）
		char* safe_alloc(size_t len);
    };
}

#endif


