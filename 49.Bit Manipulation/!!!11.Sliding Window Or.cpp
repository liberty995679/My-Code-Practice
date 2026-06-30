//x,a,b,c  ,数组内为x1, x2=(a*x1 + b) % c, x3=(a*x2+b) %c...
//对长度为k的窗口进行或运算,然后对结果进行异或运算
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    int max_bit = 0;
    int t = c; 
    while (t > 0) {
        max_bit++;
        t >>= 1;
    }
    vector<ll> arr(n), res;
    arr[0] = x;
    for (ll i = 1; i < n; i++) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }
    vector<ll> last_index(32, -1);
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (int bit = 0; bit < max_bit; bit++) {
            if (arr[i] & (1 << bit)) {
                last_index[bit] = i;  //记录每一位上次的位置
            }
        }
        if (i >= k - 1) { //窗口满了
            int left = i + 1 - k; //窗口最左边的位置
            ll cur_or = 0;
            for (int bit = 0; bit < max_bit; bit++) {
                if (last_index[bit] >= left) { //如果大于左边，则在窗口内
                    cur_or |= (1 << bit);
                }
            }
            ans ^= cur_or;
        }
    }
    cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}