## LeetCode 542.01: Matrix

### Problem

[Problem link](https://leetcode-cn.com/problems/01-matrix/)

### Solution description

BFS(or Dijkstra), see all connected 0 region as a super node.

Note that I initialize the vector in a complicated way.

**Official initialization**

```cpp
int m = matrix.size(), n = matrix[0].size();
vector<vector<int>> dist(m, vector<int>(n));
vector<vector<int>> seen(m, vector<int>(n));
```

**My rubbish initialization**

```cpp
for (int i = 0; i < xmax; ++i) {
    retMat.push_back(vector<int>());
    for (int j = 0; j < ymax; ++ j) {
        retMat[i].push_back(0);
    }
}
```

### File structure

 - `sol.cpp`: baseline solution
 - `testcases\..`: testcases

### Run testcases

No testcase for this problem.

### Performance

| Solution             | Link         | Runtime | Memory Usage |
| ------------------------ | ------- | ------------ | ------------ |
| BFS | [Sol.cpp](sol.cpp) | 168ms | 28.7MB |
|          |      |         |              |

