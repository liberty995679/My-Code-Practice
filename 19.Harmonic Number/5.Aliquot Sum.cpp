//计算一个数的因子总和，比较它与原数
//根据大小分别输出abundant,deficient,perfect
#include <iostream>

using namespace std;

int solve(int a) { 
    int total = 1;
    if (a == 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            total += i;
            if (i != a / i) total += (a / i);
        }
    }
    return total;
}

void panduan(int n, int a) {
    if (a > n) cout << "abundant" << '\n';
    else if (a < n) cout << "deficient" << '\n';
    else cout << "perfect" << '\n';
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r",  stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = solve(n);
        panduan(n, a);
    }
}