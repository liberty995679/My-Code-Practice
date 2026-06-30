//输入n,输出符合n位的所有二进制的个数
#include <iostream>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll power(int n) {
    ll res = 1;
    while (n--) {
        res = (res * 2) % mod;
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    cout << power(n) << endl;
    return 0;
}