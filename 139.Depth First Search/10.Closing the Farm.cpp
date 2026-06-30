//关闭谷仓，判断在关闭谷仓中，农场是否连通
//正向关闭很难处理，因为需要考虑删除节点后的连通性
//逆向思考：倒着来，从所有谷仓都关闭开始，逐个打开谷仓，检查连通性
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
using ll = long long;
const int MAXIN = 3000;
vector<int> arr[MAXIN];
vector<int> g[MAXIN];  //动态建图
vector<bool> visited(MAXIN), closeopen(MAXIN); //谷仓是否开放
vector<int> closeorder(MAXIN);  //关闭顺序
vector<string> res;  //存答案，然后逆序输出
int dfs(int u) {
    visited[u] = true;
    int cnt = 1;
    for (auto v: g[u]) {
        if (closeopen[v] && !visited[v]) {
            cnt += dfs(v);
        }
    }
    return cnt;
}

int main() {
freopen("closing.in", "r", stdin);
freopen("closing.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) cin >> closeorder[i];
    for (int i = n; i > 0; i--) {  //从后往前
        int u = closeorder[i];
        closeopen[u] = true;    //开放这个谷仓
        for (int v: arr[u]) {
            if (closeopen[v]) {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        int total = 0;
        for (int j = 1; j <= n; j++) { //计算开放的谷仓数量
            if (closeopen[j]) total++;
        }
        for(int j = 1; j <= n; j++) visited[j] = false;//每次调用重置visited
        int ans = dfs(u);  //判断u能走多少个点，即能连通的谷仓数量
        if (ans == total) res.push_back("YES");
        else res.push_back("NO");
    }
    reverse(res.begin(),res.end());  //反转
    for (auto &i : res) {
        cout << i << endl;
    }
    return 0;
}