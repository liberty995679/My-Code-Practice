//t个例子 输入n
//判断n中是否存在 a b c 三个不同的数
// 2 <= a b c 且 a * b * c == n
//如果存在 输出YES和一组结果 否则输出NO
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                arr.push_back(i);
                if (n / i != i) arr.push_back(n / i);
            }
        }
        int an, bn, cn;
        bool flag = false;
        for (int a: arr) {
            for (int b: arr) {
                if (a != b && n % (a * b) == 0) { //a b 不相等
                    int c = n / (a * b);
                    if (c >= 2 && a != c && b != c) {
                        flag = true;
                        an = a; bn = b; cn = c;
                    }
                }
            }
        }
        if (!flag) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << an << ' ' << bn << ' ' << cn << '\n';
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}