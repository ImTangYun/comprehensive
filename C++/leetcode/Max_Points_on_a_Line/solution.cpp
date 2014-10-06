//
//分析：
//
//任意一条直线都可以表述为
//
//y = ax + b
//
//假设，有两个点(x1,y1), (x2,y2)，如果他们都在这条直线上则有
//
//y1 = kx1 +b
//
//y2 = kx2 +b
//
//由此可以得到关系，k = (y2-y1)/(x2-x1)。即如果点c和点a的斜率为k, 而点b和点a的斜率也为k，可以知道点c和点b也在一条线上。
//
//取定一个点points[i], 遍历其他所有节点, 然后统计斜率相同的点数，并求取最大值即可
//注意：
//0、points中重复出现的点。
//
//1、int maxNum = 0;
//
//初始化，以防points.size() ==0的情况。
//
//2、mp[INT_MIN] = 0;
//
//保证poins中只有一个结点，还有points中只有重复元素时，mp中没有元素。这两种极端情况。
//
//3、int duplicate = 1;
//
//duplicate记录重复点的数量，初始化为1，是因为要把当前的点points[i]加进去。
//
//4、float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
//
//计算斜率，如果直线和y轴平行，就取INT_MAX,否则就取(float)(points[j].y - points[i].y)/(points[j].x - points[i].x)
//
//一开始把(float)(points[j].y - points[i].y)/(points[j].x - points[i].x)写做(float)((points[j].y - points[i].y)/(points[j].x - points[i].x))一直就不对，后来才想明白，注意注意！
//
//


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int bigest = 0;
        if (points.size() <= 2) return points.size();
        unordered_map<float, int> tmp;
        int ret = 0;
        int rep = 1;
        for (int i = 0; i < points.size(); ++i) {
            bigest = 0;
            tmp.clear();
            rep = 1;
            for (int j = 0; j < points.size(); ++j) {
                if (j == i) continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++rep;
                    continue;
                }
                if (points[i].x == points[j].x) ++bigest;
                else {
                    float k = (float)(points[i].y - points[j].y) / (float) (points[i].x - points[j].x);
                    tmp[k]++;
                }
            }
            if (bigest == 0 && tmp.size() == 0) return rep;
            if (bigest + rep > ret) ret = bigest + rep;
            unordered_map<float, int>::iterator iter = tmp.begin();
            for (; iter != tmp.end(); ++iter) {
                if (iter->second + rep > ret) ret = iter->second + rep;
            }
        }
        return ret;
    }
};
