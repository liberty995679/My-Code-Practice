//给你一个整数
//计算1到n当中 出去符合a ^ b的数字还剩多少个数
//例如 1 - 8 ，4 和 8 都属于 2的次方(a >= 2 && b >= 2)
//输入n 输出结果
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
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    ll n;
    cin >> n;
    set<ll> s;
    for (ll i = 2; i <= sqrt(n); i++) {
        ll cur = i * i;
        while (cur <= n) {
            s.insert(cur);
            if (cur > n / i) break; // 防止溢出：如果下一步会超就不乘了
            cur *= i;
        }
    }
    cout << n - s.size() << enl;
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