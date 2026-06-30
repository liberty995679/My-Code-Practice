//一个长度为n的数组，它的数组和能够被k整除，求数组中最大数的最小值
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int ceil(int a, int b) {
    return (a % b == 0) ? (a / b) : (a / b + 1);
}

int solve(int n, int k) {
    int x = (k - n % k) % k; //要添加的数
    int res = ceil(x, n);
    return 1 + res;
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
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}