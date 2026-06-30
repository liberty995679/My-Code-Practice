//双指针,求两数之和等于x，输出输出两数的坐标从1开始
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve(const vector<ll> &a, ll x) {
    int n = a.size();
    vector<pair<ll, int>> b;
    for (int i = 0; i < n; i++) b.push_back({a[i], i + 1}); // 保存原索引（从1开始）
    sort(b.begin(), b.end());  //排序
    int l = 0, r = n - 1;
    while (l < r) {
        ll sum = b[l].first + b[r].first;
        if (sum == x) {
            cout << b[l].second << " " << b[r].second << "\n";
            return;
        }
        if (sum < x) l++;
        else r--;
    }
    cout << "IMPOSSIBLE\n";
}
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    solve(a, x);
    return 0;
}