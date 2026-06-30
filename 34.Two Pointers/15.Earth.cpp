//取数组的一个子数组，里面的数字类型不能超过k，求这个子数组每个数*个数的最大值
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;
using ll = long long;

ll solve(const vector<int> &a, int k) {
    int n = a.size();
    ll cnt = 0;  // 每个数的类型不超过k
    int l = 0;
    unordered_map<int, int> m; //记录每个数的个数
    ll res = 0;
    ll sum = 0;
    for (int r = 0; r < n; r++) {
        if (m[a[r]] == 0) cnt++;   //如果没有，就加一
        sum += a[r];
        m[a[r]]++;
        while (cnt > k) { //如果种类超过k，减少他的数量
            m[a[l]]--;
            sum -= a[l];
            if (m[a[l]] == 0) cnt--;
            l++;
        }
        res = max(res, sum);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(a, k) << endl;
    return 0;
}