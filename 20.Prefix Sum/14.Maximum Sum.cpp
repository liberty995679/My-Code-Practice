//贪心加排序，做k次操作，选择删除两个最小值或者一个最大值，使剩余元素和最大
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> num(n);
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        sort(num.begin(), num.end());
        vector<ll> prefix(n + 1, 0), suffix(n + 1, 0);
        for (int i = 0; i < n; i++) {   //前缀和，最小的若干数的和
            prefix[i + 1] = prefix[i] + num[i];
        }
        for (int i = n - 1; i >= 0; i--) { //后缀和，最大的若干数的和
            suffix[n - i] = suffix[n - i - 1] + num[i];
        }
        ll total = prefix[n];  //总和
        ll ans = 0;
        for (int x = 0; x <= k; x++) { //最终一共会删掉：2*x + (k - x) 个数
            ll res = prefix[2 * x] + suffix[k - x];
            ans = max(ans, total - res);   //总和减去要删除的数,取最大值
        }
        cout << ans << '\n';
    } 
    return 0;
}