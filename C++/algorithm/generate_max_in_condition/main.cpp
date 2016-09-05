#include <stdio.h>
#include <vector>

using std::vector;

int maximum(vector<int> s)
{
    int max = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (max < s[i]) {
            max = s[i];
        }
    }
    return max;
}

int generate_with_index(int index, vector<int> tmp,
        int max, int index_value)
{
    int num = 0;
    for (int i = tmp.size() - 1; i >= 0; --i) {
        num *= 10;
        if (i > index) {
            num += tmp[i];
        } else if (i == index) {
            num += index_value;
        } else {
            num += max;
        }
    }
    return num;
}

int generate_with_max(int max, int time)
{
    int num = 0;
    for (int i = 0; i < time; ++i) {
        num *= 10;
        num += max;
    }
    return num;
}

int generate_num(vector<int> s, int num)
{
    vector<int> tmp;
    int left = num;
    for (; left > 0; left /= 10) {
        tmp.push_back(left % 10);
    }
    
    bool flag = false;
    int index = tmp.size() - 1;
    for (int i = tmp.size() - 1; i >= 0; --i) {
        int upper = -1;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] <= tmp[i] && s[j] > upper) {
                upper = s[j];
            }
        }
        printf("upper %d\n", upper);
        if (upper == -1) {
            flag = true;
            break;
        } else if (upper == tmp[i]) {
            index = i;
        } else {
            return generate_with_index(i, tmp, maximum(s), upper);
        }
    }
    printf("flag %s\n", flag?"true":"false");
    if (flag) {
        int upper;
        printf("index %d\n", index);
        for (int i = index; i < tmp.size(); ++i) {
            upper = -1;
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] < tmp[i]) {
                    upper = s[j];
                }
            }
            printf("upper: %d\n", upper);
            if (upper != -1) return generate_with_index(i, tmp, maximum(s), upper);
        }
        printf("generate_with_max\n");
        return generate_with_max(maximum(s), tmp.size() - 1);
    } else return num;
}

int main()
{
    vector<int> s = {2,5};
    printf("%d\n", generate_num(s, 51111));

    vector<int> s1 = {1,2,3,4,5};
    printf("%d\n", generate_num(s1, 12345));

    vector<int> s2 = {5};
    printf("%d\n", generate_num(s2, 11112));
    return 0;
}
