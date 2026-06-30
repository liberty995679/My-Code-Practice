//通过输入的字符串LR区间，来计算最大可获得的分数
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

ll solve(const vector<int> &a, string s) {\
    int n = a.size();
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n ; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    int l = 0;
    int r = n - 1;
    ll ans = 0;
    while (l < r) {
        while (l < r && s[l] == 'R') l++;
        while (l < r && s[r] == 'L') r--;
        if (l < r) {
            ans += prefix[r + 1] - prefix[l];
            l++; r--;
        }
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        string s;
        cin >> s;
        cout << solve(a, s) << endl;
    }
    return 0;
}