//输入一个公司的员工数量n，1号是总经理
//接下来n-1个是从2到n的员工的上司
//输出1到n所有员工的下属
#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
const int MAXIN = 2e5 + 1;
vector<int> adj[MAXIN];
vector<bool> visited(MAXIN);
vector<int> res(MAXIN);
int dfs(int u) {
    int subsize = 1;  //初始化子树为1
    for (int v: adj[u]) {
        int childsize = dfs(v);  //遍历所有下属v
        subsize += childsize;   //将v的大小加到u上
    }
    res[u] = subsize - 1; //减去它自己
    return subsize;
}
 
void solve(int n) {
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << (i == n ? "" : " ");
    }cout << endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
    }
    solve(n);
    return 0;
}
