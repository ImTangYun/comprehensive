// yuntang
// file qh_string.h
#ifndef QIHOO_STRING_H_
#define QIHOO_STRING_H_

#include <stdlib.h>

namespace qh
{
class string {
public:
	string();

	string(const char* s);

	string(const char* s, size_t len);

	string(const string& rhs);

	string& operator=(const string& rhs);

	string& operator=(const char* rhs);
	
	string& operator+(const string& rhs);
	
	~string();

	//get
	size_t size() const;
	const char* data() const;
	const char* c_str() const;
	size_t capacity() const;
	char &operator[](size_t index);
	void reserve(int c);
private:
	char*  data_;
	size_t len_;
	size_t cap;

	char* safe_alloc(size_t len);
};
}

#endif


