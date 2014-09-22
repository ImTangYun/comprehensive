#include <stdio.h>

void permutation(char*ptr, char* input);

int main()
{
	char p[] = "abc";
	char* m;
	permutation(m, p);
	return 0;
}

void permutation(char* ptr, char* input)
{
	if (*ptr == '\0') {
		printf("%s", input);
	} else {
		char* p = ptr;
		printf("%c", *ptr);
		for (; *p != '\0'; ++p) {
			permutation(ptr + 1, input);
			char tmp = *ptr;
			*ptr = *p;
			*p = tmp;
		}
	}
}
