//有两个排列，里面的元素都是0到n - 1
//数组 b 由数组 a 的元素任意排列组成
//计算一个数组r
//对于所有 i（0≤i≤n−1），有 ri=max(2^pj+2^q(i−j) )
//输出 r 的每个元素对 998244353 取模后的结果
//t个用例 输入长度n 两个排列
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
#include <set>
using namespace std;
using ll = long long;
const int MOD =  998244353;
int N = 1e5 + 5;
ll power(ll a, ll b) {  //快速幂
    ll ans = 1;
    while (b) {
    if (b & 1) ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}
vector<ll> powers(N);
void init() {   //预处理幂次方
    powers[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        powers[i] = powers[i - 1] * 2 % MOD;
    }
}
void solve() { 
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];
    ll mxpidx = 0; ll mxqidx = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] > p[mxpidx]) mxpidx = i; //找两个次方的最大值和坐标
        if (q[i] > q[mxqidx]) mxqidx = i;
        ll ans1 = (powers[p[mxpidx]] + powers[q[i - mxpidx]]) % MOD; //两种情况
        ll ans2 = (powers[p[i - mxqidx]] + powers[q[mxqidx]]) % MOD; //不能直接比 因为取模了
        int t1 = max(p[mxpidx], q[i - mxpidx]);      // 用原始指数比较
        int t2 = max(p[i - mxqidx], q[mxqidx]);      
        ll r;
        if (t1 > t2) r = ans1;
        else if (t1 < t2) r = ans2;
        else {   //最大值相等，则另一个比较
            r = ((q[i - mxpidx] >= p[i - mxqidx]) ? ans1 : ans2);
        }
        cout << r << ' ';
    }cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
    return 0;
}