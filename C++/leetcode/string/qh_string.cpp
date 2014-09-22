// yuntang
// file:qh_string.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <exception>
#include <iostream>
#include "qh_string.h"
using namespace std;
namespace qh
{
    // 
string::string() {
	data_ = safe_alloc(15);
	cap = 15;
	data_[0] = '\0';
	len_ = 0;
}

string::string(const char* s) {
	int length = strlen(s);
	if(s == NULL || length == 0) {
		data_ = safe_alloc(15);
		cap = 15;
		data_[0] = '\0';
		len_ = 0;
		return;
	}
	size_t i;
	if(length > 7) {
		cap = 2 * length;
		data_ = safe_alloc(2 * length);
		for(i = 0; i < length; ++i) {
			data_[i] = s[i];
		}
		data_[i] = '\0';
		len_ = length;
	}else {
		data_ = safe_alloc(15);
		cap = 15;
		len_ = length;
		for(i = 0; i < length; ++i) {
			data_[i] = s[i];
		}
		data_[i] = '\0';
	}
}

string::string(const char* s, size_t len) {
	if(s == NULL || len == 0)	{
		data_ = safe_alloc(15);
		data_[0] = '\0';
		cap = 15;
		len_ = 0;
		return;
	}
	size_t i;
	if(len > 7) {
		cap = 2 * len;
		data_ = safe_alloc(2 * len);
		for(i = 0; i < len; ++i) {
			data_[i] = s[i];
		}
		data_[i] = '\0';
		len_ = len;
	}else {
		data_ = safe_alloc(15);
		cap = 15;
		len_ = len;
		for(i = 0; i < len; ++i) {
			data_[i] = s[i];
		}
		data_[i] = '\0';
	}
}

string::string(const string& rhs) {
	len_ = rhs.size();
	size_t i = 0;
	if(len_ <= 7) {
		data_ = safe_alloc(15);
		cap = 15;
		while(i < len_) {
			data_[i] = rhs.data_[i];
			++i;
		}
		data_[i] = '\0';
	}else{
		data_ = safe_alloc(2 * len_);
		cap = 2 * len_;
		while(i < len_) {
			data_[i] = rhs.data_[i];
			++i;
		}
		data_[i] = '\0';
	}
}

string& string::operator=(const string& rhs) {
	int len_ = rhs.size();
	size_t i = 0;
	if(data_ != NULL) {
		delete [] data_;
	}
	if(len_ <= 7) {
		data_ = safe_alloc(15);
		cap = 15;
		while(i < len_) {
			data_[i] = rhs.data_[i];
			++i;
		}
		data_[i] = '\0';
	}else{
		data_ = safe_alloc(2 * len_);
		cap = 2 * len_;
		while(i < len_) {
			data_[i] = rhs.data_[i];
			++i;
		}
		data_[i] = '\0';
	}
	return *this;
}

string& string::operator=(const char* rhs) {
	int length = strlen(rhs);
	if(rhs == NULL || length == 0)	{
		data_ = safe_alloc(15);
		data_[0] = '\0';
		cap = 15;
		len_ = 0;
		return *this;
	}
	size_t i;
	if(length > 7) {
		cap = 2 * length;
		data_ = safe_alloc(2 * length);
		for(i = 0; i < length; ++i) {
			data_[i] = rhs[i];
		}
		data_[i] = '\0';
		len_ = length;
	}else {
		data_ = safe_alloc(15);
		cap = 15;
		len_ = length;
		for(i = 0; i < length; ++i) {
			data_[i] = rhs[i];
		}
		data_[i] = '\0';
	}
	return *this;
}
//dtor
string::~string(){
	if(cap > 0) delete [] data_;
}

//get
size_t string::size() const {
	return len_;
}
const char * string::data() const {
	return data_;
}
const char* string::c_str() const {
	if(size() == 0) {
		return "";
	}
	return data_;
}
size_t string::capacity() const {
	return cap;
}
// set & get

char &string::operator[](size_t index) {
	if(index >= len_) {
		printf("下标越界了！\n\n");//throw exception("越界了！");
		char *p = "";
		return *p;
	}
	return data_[index];
}
string& string::operator+(const string& rhs) {
	string *temp = new string;
	temp->len_ = size() + rhs.size();
	size_t i = 0;
	if(temp->len_ <= 7) {
		temp->data_ = safe_alloc(15);//new char[15];
		temp->cap = 15;
		while(i < size()) {
			temp->data_[i] = data_[i];
			++i;
		}
		while(i < temp->len_) {
			temp->data_[i] = rhs.data_[i - size()];
			++i;
		}
		temp->data_[i] = '\0';
	}else{
		temp->data_ = safe_alloc(2 * len_);//new char[2 * len_];
		temp->cap = 2 * temp->len_;
		while(i < size()) {
			temp->data_[i] = data_[i];
			++i;
		}
		while(i < temp->len_) {
			temp->data_[i] = rhs.data_[i - size()];
			++i;
		}
		temp->data_[i] = '\0';
	}
	return *temp;
}

void string::reserve(int c) {
	if(c > cap) {
		cap = c;
		char *p = data_;
		data_ = safe_alloc(cap);//new char[cap];
		size_t i;
		for(i = 0; i < size(); ++i) {
			data_[i] = p[i];
		}
		data_[i] = '\0';
		if(p != NULL) delete [] p;
	}
}

char* string::safe_alloc(size_t len) {
	char* temp;
	try {
		temp = new char[len];
	}
	catch(bad_alloc x) {
		cerr << "Allocation failure! \n";
		return NULL;
	}
	return temp;
}
}
