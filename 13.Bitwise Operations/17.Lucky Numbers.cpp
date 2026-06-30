//找一个不小于n的超级幸运数字
//只包含4和7且这两个个数相同
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

vector<ll> ans; // 存放所有构造出来的超级幸运数字

void dfs(int n, int cnt4,string s) {
    if (n == s.size()) {
        if (cnt4 == 0) {
            ans.push_back(stoll(s));  //字符串转long long
        }
        return;  // 到达叶子节点后必须 return
    }
    if (cnt4 > 0) { // 放一个 '4'，剩余 '4' 的数量减 1
        dfs(n, cnt4 - 1, s + '4');
    }
    if (s.size() + cnt4 < n) {    // 已经使用的字符数量 + 还必须放的 '4' 的数量
        dfs(n, cnt4, s + '7');  // 剩余的位置数量 > 必须放的 '4' 数量
    }
}

void solve() {
    int n;
    cin >> n;
    string s = "";
    for (int i = 2; i <= 10; i += 2) {
        dfs(i, i / 2, s);
    }
    sort(ans.begin(), ans.end());
    auto it = lower_bound(ans.begin(), ans.end(), n);
    cout << *it << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}