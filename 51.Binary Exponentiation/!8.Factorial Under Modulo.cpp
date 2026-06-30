//高效计算阶乘,输出答案对 998,244,353 取模
//没有权限提交，所以不知道对不对
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 998244353;

void solve(int n) {
    vector<ll> arr(n + 1);
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        arr[i] = (arr[i - 1] * i) % MOD;
    }
    cout << arr[n] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    solve(n);
    return 0;
}