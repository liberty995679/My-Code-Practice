//求|ai - aj|的乘积，输入n个ai，结果对m取模
//鸽巢原理
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve(int n, int m, const vector<int> &a) {
    if (n > m) {  //存在余数相同的情况，则能被m整除,那结果会被整除，余数为0
        cout << 0 << endl;
        return;
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = (ans * abs(a[i] - a[j])) % m;
        }
    }
    cout << (ans + m) % m << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    solve(n, m, arr);
}