//t个用例 n长度 
//有一个n * n的矩阵
//对其中按行的位置进行[l, r]范围的子数组反转
//输出操作数，输出i , l, r   i代表行
//最多 2n 次操作
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;

void solve() {   //无法使用循环右移
    int n;
    cin >> n;
    cout << 2 * (n - 1) << '\n';
    for (int i = 1; i <= n; i++) {
        if (i > 2) {
            cout << i << ' ' << 1 << ' ' << i - 1 << '\n';//i代表行 也代表分割区间
            cout << i << ' ' << i << ' ' << n << '\n'; //每一行的1 - i - n都会反转,保证结果不同
        } else {
            cout << i << ' ' << i << ' ' << n << '\n';
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}