//给一个n，计算子数组和等于x的数量
//输入n 和 x
//输入数组a
//输出结果
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

struct cus_hash{ //数据一样或严格递增，1e5会导致哈希冲突
    size_t operator()(ll x) const { //unordered_map不能用，用map 或者使用这个函数
        return x ^ ( x >> 23);   
    }
};

void solve() {
    ll n, x;
    cin >> n >> x;
    unordered_map<ll, ll, cus_hash> mp;
    mp[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        sum += a;
        ans += mp[sum - x];
        mp[sum]++;
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