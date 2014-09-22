#include <stdio.h>
#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

string num_to_string(int num);
int num_of_one(int num);
int culaculate(int index, string str_num);
int add_num(string str_num, int index);
int main()
{
	cout << num_of_one(20) << endl;
	return 0;
}

string num_to_string(int num)
{
	char buff[20];
	snprintf(buff, sizeof(buff), "%d", num);
	return buff;
}
int num_of_one(int num)
{
	if (num <= 0) return 0;
	if (num < 10) return 1;
	string str_num = num_to_string(num);
	int result = 0;
	for (int i = 0; i < str_num.size(); ++i) {
		result += culaculate(i, str_num);
	}
	return result;
}
int culaculate(int index, string str_num)
{
	if (index >= str_num.size()) return 0;
	if (str_num[index] == '0') {
		return 0;
	} else if (str_num[index] == '1') {
		return add_num(str_num, index + 1) + 1;
	} else {
		int re = 1;
		for (int i = index + 1; i < str_num.size(); ++i) {
			re *= 10;
		}
		return re;
	}
}
int add_num(string str_num, int index)
{
	int result = 0;
	for (int i = index; i < str_num.size(); ++i) {
		result *= 10;
		result += static_cast<int>(str_num[i] - '0');
	}
	return result;
}
