#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const char enl = '\n';

// 计算一个数各位数字的乘积，含0则返回0
ull digitProduct(ull n) {
    if (n == 0) return 0;
    ull p = 1;
    while (n > 0) {
        int d = n % 10;
        if (d == 0) return 0;
        p *= d;
        n /= 10;
    }
    return p;
}

void solve() {
    ull a, b;
    cin >> a >> b;

    string sa = to_string(a), sb = to_string(b);
    int na = sa.size(), nb = sb.size();

    // 核心观察：最优答案一定是"某前缀 + 全9后缀"的形式
    // 因为如果某位不是9，把它后面全换成9乘积只会更大
    // 所以只需枚举两类候选：从上界b往下凑、从下界a往上凑
    vector<ull> cands = {a, b};

    // 类型1：基于上界b，把第i位减小，后面全填9（保证 <= b）
    for (int i = 0; i < nb; i++) {
        for (int d = 1; d < (sb[i] - '0'); d++) {
            string t = sb.substr(0, i) + char('0' + d) + string(nb - i - 1, '9');
            ull v = stoull(t);
            if (v >= a) cands.push_back(v); // 还要在区间内
        }
    }

    // 类型2：基于下界a，把第i位增大，后面全填9（保证 >= a）
    for (int i = 0; i < na; i++) {
        for (int d = (sa[i] - '0') + 1; d <= 9; d++) {
            string t = sa.substr(0, i) + char('0' + d) + string(na - i - 1, '9');
            ull v = stoull(t);
            if (v <= b) cands.push_back(v); // 还要在区间内
        }
    }

    // 类型3：纯9形式（9, 99, 999...），单独补充
    string nines = "";
    for (int len = 1; len <= nb; len++) {
        nines += '9';
        ull v = stoull(nines);
        if (v >= a && v <= b) cands.push_back(v);
    }

    // 遍历所有候选，取乘积最大的那个数
    ull ans = a, bestP = digitProduct(a);
    for (ull c : cands) {
        ull p = digitProduct(c);
        if (p > bestP) {
            bestP = p;
            ans = c;
        }
    }

    cout << ans << enl;
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