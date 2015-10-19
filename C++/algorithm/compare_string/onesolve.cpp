/*
 *  我们可以对短字串进行轮询（此思路的叙述可能与网上的一些叙述有出入，因为我们最好是应该把短的先存储，那样，会降低题目的时间复杂度），把其中的每个字母都放入一个Hashtable里(我们始终设m为短字符串的长度，那么此项操作成本是O(m)或8次操作)。然后轮询长字符串，在Hashtable里查询短字符串的每个字符，看能否找到。如果找不到，说明没有匹配成功，轮询长字符串将消耗掉16次操作，这样两项操作加起来一共只有8+16=24次。
 *      当然，理想情况是如果长字串的前缀就为短字串，只需消耗8次操作，这样总共只需8+8=16次。
 *
 *          或如梦想天窗所说： 我之前用散列表做过一次，算法如下：
 *           1、hash[26]，先全部清零，然后扫描短的字符串，若有相应的置1，
 *            2、计算hash[26]中1的个数，记为m 
 *             3、扫描长字符串的每个字符a；若原来hash[a] == 1 ，则修改hash[a] = 0，并将m减1；若hash[a] == 0，则不做处理 
 *              4、若m == 0 or 扫描结束，退出循环。
 *
 */
#include <stdio.h>
#include <string>

using std::string;

bool compare(const string &str1, const string str2)
{
    if (str1.length() <= 0 || str2.length() <= 0)
        return false;
    int hash_table[26];
    for (int i = 0; i < 26; ++i) {
        hash_table[i] = 0;
    }
    int count = 0;
    for (int i = 0; i < str2.length(); ++i) {
        if (hash_table[i] == 0) ++count;
        hash_table[str2[i] - 'a'] = 1;
    }
    for (int i = 0; i < str1.length(); ++i) {
        if (hash_table[str1[i] - 'a'] == 1) {
            --count;
            if (count <= 0) return true;
            hash_table[i] = 0;
        }
    }
    return false;
}

int main()
{
    printf("%s\n", compare("abccbaabccbbbcvvsjl", "abc")?"true":"false");
    printf("%s\n", compare("abccbaabccbbbcvvsjl", "abcd")?"true":"false");
    return 0;
}
