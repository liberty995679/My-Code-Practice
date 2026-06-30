//对a数组，求b数组的每个数大于等于a数组数的个数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<int> &a, int n) {
    int l = 0; int r = a.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= n) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int res = solve(a, b[i]);
        cout << res << (i == m - 1 ? '\n' : ' ');
    }
    return 0;
}