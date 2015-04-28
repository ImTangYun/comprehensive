#include <stdio.h> 
#include <vector>
using std::vector;
int prime_count(const int n) 
{
	int count = 0;
	for (int i = 2; i < n; ++i) {
		bool flag = false;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				flag = true;
				break;
			}
		}
		if (!flag) ++count;
	}
	return count;
}

int prime_count2(int n)
{
	if (n < 2) return 0;
	if (n == 2) return 1;
	vector<int> temp;
	int count = 1;
	temp.push_back(2);
	for (int i = 3; i < n; ++i) {
		bool flag = false;
		for (int j = 0; j < temp.size(); ++j) {
			if (i % temp[j] == 0) {
				flag = true;
				//printf("%d is not prime\n", i);
				break;
			}				
			if (temp[j] * temp[j] > i) {
				break;
			}

		}
		if (flag == false) {
			++count;
			//printf("%d is prime\n", i);
			temp.push_back(i);
		}
	}
	return count;
}

int main() 
{
	printf("prime of 10 is: %d\n", prime_count2(150000));
}
