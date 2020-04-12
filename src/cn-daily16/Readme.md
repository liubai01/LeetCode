## LeetCode 面试题 16.03. 交点

### Problem

[Problem link](https://leetcode-cn.com/problems/intersection-lcci/)

### Solution description

I am not doing very well in this task. For the thoughts of divide and conquer, I split it to too many trivial cases. The linear algebra solution is better. My method is too complicated to describe here.



I highly suggest this [solution(cpp)](https://leetcode-cn.com/problems/intersection-lcci/solution/wo-jue-de-wo-yi-jing-hen-nu-li-liao-ke-yi-jiao-zhu/) version:

```c++
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define det(a, b, c, d) (a*d-b*c)
class Solution{
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        //auto [x1, y1] = start1, [x2, y2] = end1, [x3, y3] = start2, [x4, y4] = end2;
        double x1 = start1[0], y1 = start1[1];
        double x2 = end1[0], y2 = end1[1];
        double x3 = start2[0], y3 = start2[1];
        double x4 = end2[0], y4 = end2[1];

        //double d = det(x1 - x2, x4 - x3, y1 - y2, y4 - y3);
        double d = (x1 - x2)*(y4 - y3) - (x4 - x3)*(y1 - y2);
        //double p = det(x4 - x2, x4 - x3, y4 - y2, y4 - y3);
        double p = (x4 - x2)*(y4 - y3) - (x4 - x3)*(y4 - y2);
        //double q = det(x1 - x2, x4 - x2, y1 - y2, y4 - y2);
        double q = (x1 - x2)*(y4 - y2) - (x4 - x2)*(y1 - y2);
        cout << "d:" << d << ", q:" << q << ", p:" << p << '\n';
        //相交不共线
        if(d != 0){
            double lam = p/d, eta = q/d;
            cout << "lam:" << lam << ", eta:" << eta << '\n';
            if (lam<0 || lam>1 || eta<0 || eta>1) return {};
            return {lam * x1 + (1 - lam) * x2, lam * y1 + (1 - lam) * y2};
        }
        //不相交
        if( p != 0 || q != 0) return {};
        //共线
        double t1 = min(max(y1,y2), max(y3,y4)), t2 = max(min(y1,y2), min(y3,y4)), tx2 = max(min(x1,x2), min(x3,x4));
        cout << t1 << ',' << t2 << '\n';
        if(t1>=t2)
            return {tx2, t2};
        
        return {};
    }
};
```



### File structure

 - `sol.cpp`: baseline solution
 - `testcases\..`: testcases

### Run testcases

```powershell
# On Windos(GCC) 5.3.0)
g++ .\testcases\test01.cpp -o test01.exe -std=c++0x
```

Modify `../sol.cpp`  in `test01.cpp` to apply testcases on different solutions.

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| dive and conquer | [sol.cpp](sol.cpp) | 4ms | 11.5MB |
| linear algebra | [py](https://leetcode-cn.com/problems/intersection-lcci/solution/wo-jue-de-wo-yi-jing-hen-nu-li-liao-ke-yi-jiao-zhu/) | N/A | N/A |

