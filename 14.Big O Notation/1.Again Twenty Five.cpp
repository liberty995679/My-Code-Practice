//输入n,输出5的n次方的最后两位
#include <iostream>

using namespace std;
using ll = long long;

const int mod = 100;

ll power(ll a, ll n) {  //快速幂
    ll res = 1;
    a %= mod; //底数取模
    while (n) {
        if (n & 1) res = (res * a) % mod; //如果最后一位是1,把当前底数乘到结果里
        a = (a * a) % mod;  //底数平方并取模
        n >>= 1;  //指数除以2
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ll n;
    cin >> n;
    cout << power(5,n) << endl;
    return 0;
}