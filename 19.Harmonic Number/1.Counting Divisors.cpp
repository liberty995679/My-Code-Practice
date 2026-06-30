//对输入的数字，输出它的因子数量
#include <iostream>

using namespace std;
using ll = long long;

int solve(int n) {   //质因数分解法
    int count = 1;
    for (int i = 2; i * i <= n; ++i) { //从2开始
        if (n % i == 0) {   //判断是否为因子
            int exp = 0;   //指数
            while (n % i == 0) {
                n /= i;    //n除以因子,求出它的指数
                exp++;
            }
            count *= (exp + 1);   //每个指数加一互乘
        }
    }
    if (n > 1) count *= 2;  // 如果 n > 1，说明它本身是一个大质数
    return count;
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
        int x;
        cin >> x;
        cout << solve(x) << '\n';
    }
    return 0;
}
