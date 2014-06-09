#include <stdio.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

void num_to_str(int num, char* str, int buf_length)
{
	snprintf(str, buf_length, "%d", num);
}

int compare(char* str1, char* str2)
{
	if (str2 == NULL || str1 == NULL) return -2;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int length = len2 + len2;
	char tmp1, tmp2;
	int i = 0;
	for (; i < length; ++i) {
		if (i < len1) {
			tmp1 = str1[i];
		} else {
			tmp1 = str2[i - len1];
		}
		if (i < len2) {
			tmp2 = str2[i];
		} else {
			tmp2 = str1[i - len2];
		}
		printf("%c, %c\n", tmp1, tmp2);
		if (tmp2 != tmp1) {
			printf("breaking%c, %c\n", tmp1, tmp2);
			break;
		}
	}
	printf("i: %d, length: %d\n", i, length);
	if (i == length) return 0;
	if (tmp1 > tmp2) return 1;
	return -1;
}

void sort(int *num, int length)
{
	typedef char* p;
	p* str = new p[length];
	for (int i = 0; i < length; ++i) {
		str[i] = new char[12];
		num_to_str(num[i], str[i], 12);
	}

	for (int i = 0; i < length; ++i) {
		delete [] str[i];
	}
	delete [] str;
}

int main()
{

	char num1[] = { '1', '1', '1', '1', '0', '\0' };
	char num2[] = { '1', '1', '1', '1', '1', '\0' };
	cout << compare(num1, num2) << endl;
	return 0;
}
