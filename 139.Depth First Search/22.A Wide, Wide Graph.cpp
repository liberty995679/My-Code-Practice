//有一棵树，构造一个新图
//两个节点之间的距离>=k
//对于1到n范围的k,打印连接的连通块数量
//如果没有一对点满足条件，所有点断开,每个点都是独立的
// 树上连通分量问题 - O(n)优化版本
// 核心思想：对于Gk，距离>=k的点会形成一个连通分量，距离<k的点是孤立点
// 连通分量数 = 孤立点数 + 1（如果有非孤立点）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int d1[N], d2[N];  // d1和d2分别表示到直径两端点的距离
int maxd[N];       // maxd[i]表示点i到树中最远点的距离
int n;

// DFS计算从start到所有点的距离，存储在d数组中
void dfs(int u, int fa, int depth, int d[]) {
    d[u] = depth;
    for (auto v : g[u]) {
        if (v != fa) {
            dfs(v, u, depth + 1, d);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    // 读入树的边（注意这里不需要-1，因为题目是1-indexed）
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    // 第一次DFS：从任意点（这里选1）出发，找到最远的点a
    dfs(1, -1, 0, d1);
    int a = 1;
    for (int i = 1; i <= n; i++) {
        if (d1[i] > d1[a]) a = i;
    }
    
    // 第二次DFS：从a出发，找到最远的点b（此时a-b是树的直径）
    dfs(a, -1, 0, d1);
    int b = 1;
    for (int i = 1; i <= n; i++) {
        if (d1[i] > d1[b]) b = i;
    }
    
    // 第三次DFS：从b出发，计算所有点到b的距离
    dfs(b, -1, 0, d2);
    
    // 对每个点，取它到a和b的最大距离，这就是它到树中最远点的距离
    for (int i = 1; i <= n; i++) {
        maxd[i] = max(d1[i], d2[i]);
    }
    
    // 排序，方便统计
    sort(maxd + 1, maxd + n + 1);
    
    // 对每个k，统计有多少点的最大距离 < k（孤立点数量）
    int idx = 1;  // 指向第一个maxd >= k的位置
    for (int k = 1; k <= n; k++) {
        // 找到第一个maxd[idx] >= k的位置
        while (idx <= n && maxd[idx] < k) {
            idx++;
        }
        
        // idx-1是孤立点数量
        // 如果idx <= n，说明有非孤立点，连通分量数 = 孤立点数 + 1
        // 如果idx > n，说明全是孤立点，连通分量数 = n
        int isolated = idx - 1;
        int components = (idx <= n) ? isolated + 1 : n;
        
        cout << components;
        if (k < n) cout << ' ';
    }
    cout << '\n';
    
    return 0;
}