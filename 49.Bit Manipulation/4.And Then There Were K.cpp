//n& (n−1) & (n−2) & (n−3) & ... (k) = 0
//输入n，求k
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const ll mod = 1e9;  //其实就是n内的最大2的次方-1
ll mod_pow(ll a, long long n, ll mod) {  //用快速幂，不然会超时
    ll res = 1 % mod; // 防止 mod=1 的情况
    a %= mod;         // 先对底数取模，避免溢出
    while (n > 0) {
        if (n & 1) {               // 如果当前 n 的最低位是 1
            res = (res * a) % mod; // 把当前底数贡献乘进结果
        }
        a = (a * a) % mod; // 底数平方，进入下一位
        n >>= 1;           // 指数右移，相当于 n /= 2
    }
    return res;
}


int solve(int n) {
    int exp = 0;
    while (n) {
        if (n / 2 > 0) exp++;
        n /= 2;
    }
    ll res = mod_pow(2, exp, mod);
    return res - 1;
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
        cout << solve(n) << endl;
    }
    return 0;
}