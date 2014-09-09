#include <stdio.h>
#include "auto_ptr.hpp"

using myspace::AutoPtr;

int main()
{
    AutoPtr<char> A(new char());
    *A = 'q';
    printf("%c\n", *A);
    return 0;
}

