//输入长度n 和目标k
//输入数组a
//计算数组a的区间和等于k的数量
//输出这个数
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


void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll cnt = 0;
    unordered_map<ll, ll> mp;//mp 里存的应该是“之前的前缀和”
    vector<ll> s(n + 1); //前缀和
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + arr[i - 1];
    }
    mp[0] = 1; //s[r] = k  ⇒ s[r] - k = 0
    for (int r = 1; r <= n; r++) {
        cnt += mp[s[r] - k];   // s[r] - s[l - 1] == k -> s[r] - k == s[l - 1]
        mp[s[r]]++;    //只要是s[r] - k存在说明s[l - 1]存在说明成立 有解
    }
    cout << cnt << enl;
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