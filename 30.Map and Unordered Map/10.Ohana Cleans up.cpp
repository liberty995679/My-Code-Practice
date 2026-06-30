//松前绪花（Ohana Matsumae）正在尝试打扫一个房间，这个房间被划分为一个 n×n 的方格网格。
//每个方格最初要么是干净的，要么是脏的。绪花可以横扫（sweep）网格的列。她的扫帚非常奇怪：如果她扫过干净的方格，它会变脏；如果她扫过脏的方格，它会变干净。她想要横扫某些列，使得完全干净的行的数量最大化。不允许只扫一列的一部分，绪花只能扫整列。
//返回她能够使其完全干净的最大行数。
//第一行输入是一个整数 n (1 ≤ n ≤ 100)。
//接下来的 n 行将描述房间的状态。第 i 行包含一个长度为 n 的二进制字符串，表示房间的第 i 行的状态。
//如果该行第 j 个字符是 '1'，则表示第 i 行第 j 列的方格是干净的；如果是 '0'，则表示它是脏的。
//输出应只包含一行，一个整数，表示可能达到的完全干净的行的最大数量。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int ans = 0;
    for (auto it: mp) {
        ans = max(ans, it.second);
    }
    cout << ans << enl;
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