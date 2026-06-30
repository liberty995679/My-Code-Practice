//交互题
//读入 n（目标值）。
//你发送命令（如 add 5、mul 3、digit等）。
//评测机返回 1（成功）或 0（失败），失败时 x不变。
//重复直到你认为 x=n，输出 !结束本测试用例。
//总命令数 ≤ 7 条。
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() { //hack版本不需要交互
    ll n, x;
    cin >> n;
    cout << "mul 999999999\n";
    cout.flush();
    cin >> x;
    cout << "digit\n";
    cout.flush();
    cin >> x;   //总和为81
    cout << "add " << n - 81 << '\n';
    cout.flush();
    cin >> x;
    cout << "!\n";
    cout.flush();  //刷新缓冲区
    cin >> x;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}