//给定一个数组 a，定义 f(a)为将 a划分成一个或多个子数组的方案数，满足：
//每个元素恰好出现在一个子数组中。
//所有子数组的和相等。
//例如，如果 a = [1, 1]，那么 f(a) = 2，因为有两种划分方式：
//[1, 1]（整个数组作为一个子数组，和为 2）
//[1] + [1]（两个子数组，每个和为 1）
//现在给定两个整数 x和 y，你需要找到 所有​ 长度为 x + y、由 x个 1和 y个 -1组成的数组 a中，f(a)的最小值。
//由于答案可能很大，输出答案对 676767677取模的结果。此外，你还需要构造一个达到该最小值的数组。
//注：数组 b是数组 c的子数组，如果 b可以通过从 c的开头删除若干个（可能为 0 或全部）元素，以及从末尾删除若干个（可能为 0 或全部）元素得到。
//每个测试包含多组测试用例。第一行包含测试用例的数量 t（1 ≤ t ≤ 10^4）。接下来是测试用例的描述。
//每个测试用例的第一行包含两个整数 x和 y（0 ≤ x, y ≤ 2·10^5）。保证 x + y ≥ 1。
//保证所有测试用例的 x之和不超过 2·10^5，y之和不超过 2·10^5。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';
int MOD = 676767677;

void solve() {
    ll x, y;
    cin >> x >> y;
    if (x == y) {  //两个相同最小值是1
        cout << 1 << enl;
        for (int i = 0; i < x; i++) {
            cout << 1 << ' ';
        }
        for (int i = 0; i < y; i++) {
            cout << -1 << ' ';
        }
        cout << enl;
        return;
    }
    ll m = abs(x - y);  //两个不同则要算他的因数 因为s * k = x - y = total,k是段数，计算不同的k
    ll sum = 0;
    for (ll i = 1; i <= sqrt(m); i++) {
        if (m % i == 0) {
            sum++;
            if (i != m / i) {
                sum++;
            }
        }
    }
    cout << sum << enl;
    for (int i = 0; i < x; i++) {
        cout << 1 << ' ';
    }
    for (int i = 0; i < y; i++) {
        cout << -1 << ' ';
    }
    cout << enl;
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