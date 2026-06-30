//输入n和k代表数据库中的博弈数量和需要分析的范围数
//n个字符WL代表牛队赢了或者输了比赛
//k行i j表示区间
//对于每一个范围打印一个Y或者N
//输出一个由YN组成的字符串
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = (s[i - 1] == 'W' ? 1 : -1); 
    }
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    string res = "";
    while (k--) {
        int i, j;
        cin >> i >> j;
        int ans = prefix[j] - prefix[i - 1];
        if (ans > 0) res += 'Y';
        else res += 'N';
    }
    cout << res << endl;
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