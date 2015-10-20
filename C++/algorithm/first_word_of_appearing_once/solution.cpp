#include <stdio.h>
#include <string>

using std::string;

char first_char(const string &str)
{
    char hash_table[256] = {0};
    for (int i = 0; i < 256; ++i) {
        hash_table[i] = 0;
    }
    int tmp_index = 0;
    for (int i = 0; i < str.length(); ++i) {
        ++hash_table[str[i]];
        while (hash_table[str[tmp_index]] > 1) {
            ++tmp_index;
            if (tmp_index >= str.length()) {
                return -1;
            }
        }
    }
    return str[tmp_index];
}

int main()
{
    string str = "abcdefambcedfh";
    printf("%c\n", first_char(str));
    return 0;
}
