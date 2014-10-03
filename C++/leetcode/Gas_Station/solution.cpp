/**
 *1. 最朴素的解法是对每一个起点测试, 复杂度为 o(n^2), 太慢了

 2. 一个改进的方法. 依然对每一个起点测试, 但是下一个节点可以利用前一个节点的结果. 复杂度为 o(n), 实现较复杂. 并且, 超时了

 3. (2) 的做法还可以作改进. 改进基于一个 Observation, 假设起点是 i, 走到 j 时, 发现剩下的油不够了. (2) 的做法是从 i+1 开始, 再走. 但是, 从 i+1 ->j 之间的节点, 肯定都之恩能够走到 j. 原因是 gas[i]-cost[i] >= 0, 也就是说经过 i 节点, 对我们来讲是一定有益的, 所以放弃 i 不会对全局有好的影响. 所以下一个起点应该是 j+1

 4. 找到起点后, 需要再验证一下
 */
class Solution {
public:
bool help(vector<int> &gas, vector<int> &cost, int index, int &next, int &count)
{
    int left = 0;
    for (int i = index; i < gas.size(); ++i) {
        left += gas[i];
        left -= cost[i];
        ++count;
        if (i < gas.size() - 1) next = i + 1;
        else next = 0;
        if (left < 0) return false;                                                                               
    }   
    for (int i = 0; i < index; ++i) {
        left += gas[i];
        left -= cost[i];
        next = i + 1;
        ++count;
        if (left < 0) return false;
    }   
    return true;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int count = 0;
    int next = 0;
    int index = 0;
    while (true) {
        if (help(gas, cost, index, next, count)) {
            return index;
        }
        index = next;
        if (count > gas.size()) {
            if (help(gas, cost, index, next, count)) {
                return index;
            }
            break;
        }
    }
    return -1;
}
};
