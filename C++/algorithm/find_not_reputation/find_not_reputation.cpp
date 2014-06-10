#include <stdio.h>

char find_not_reputation(char* string)
{
	if (string == NULL) return '\0';
	int table[256];
	for (int i = 0; i < 256; ++i) {
		table[i] = 0;
	}
	char* p = string;
	while (*p != '\0') {
		++table[static_cast<int>(*p)];
		++p;
	}
	p = string;
	while (*p != '\0') {
		if (table[static_cast<int>(*p)] == 1) {
			return *p;
		}
		++p;
	}
	printf("flag\n");
	return '\0';
}

int main(int args, char**argv)
{
	if (args != 2) {
		printf("usage: %s string\n", argv[0]);
		return 0;
	}
	char re = find_not_reputation(argv[1]);
	if (re == '\0') {
		printf("all char have reputation! %s\n", argv[1]);
		return 0;
	}
	printf("the first char that not reputation is %c\n", re);
	return 0;
}
