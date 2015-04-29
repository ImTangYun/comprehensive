#include <stdio.h>

int sum_sq_every_num(int n)
{
	int tem = n;
	int sum = 0;
	while (tem) {
		int last_num = tem - ( tem / 10 ) * 10;
		sum += last_num * last_num;
		tem = tem / 10;
	}
	return sum;
}

bool is_happy_num(int n) 
{
	n = sum_sq_every_num(n);
	if (n == 1) {
		return true;
	}
	bool flag_array[1000];
	for (int i = 0; i < 1000; ++i) {
		flag_array[i] = false;
	}
	while (n) {
		int s = sum_sq_every_num(n);
		printf("%d\n", s);
		if (s == 1) {
			return true;
		}
		if (flag_array[s] == false) {
			flag_array[s] = true;
		} else {
			return false;
		}
		n = s;
	}
}

int main()
{
	is_happy_num(7);
	return 0;
}
