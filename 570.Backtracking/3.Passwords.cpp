//两个 6×5 的字母表（6 行，每行 5 个字母）
//每一列只能选 同时出现在两张表同一列 的字母
//求按字典序排序后的第 k 个“合法密码”
//如果不存在第 k 个，就输出 NO
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;
vector<string> ans;
vector<set<char>> res(5);
vector<vector<bool>> vis;
string s = "";
void dfs(int p) {
    if (p == 5) {
        ans.push_back(s);
        return;
    }
    for (char c: res[p]) {
        s.push_back(c);
        dfs(p + 1);
        s.pop_back();
    }
} 

void solve() {
    int t;
    cin >> t;
    while (t--) {
        s.clear();
        ans.clear();
        for (int i = 0; i < 5; i++) res[i].clear();
        int k;
        cin >> k;
        vector<string> a(6), b(6);
        for (int i = 0; i < 6; i++) cin >> a[i];
        for (int i = 0; i < 6; i++) cin >> b[i];
        for (int i = 0; i < 5; i++) {
            for (int v = 0; v < 6; v++) {
                for (int j = 0; j < 6; j++) {
                    if (a[j][i] == b[v][i] ) {
                        res[i].insert(a[j][i]);
                    }
                }
            }
        }
        dfs(0);
        if (ans.size() < k) cout << "NO" << endl;
        else cout << ans[k - 1] << endl;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);      
#endif
    ios::sync_with_stdio(false);            
    cin.tie(nullptr);
    solve();
    return 0;
}