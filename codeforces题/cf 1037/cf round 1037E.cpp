//给定两个长度为 n 的数组 p 和 s，其中 p 是某个数组 a 的前缀最大公约数，s 是同一个数组 a 的后缀最大公约数。换句话说，如果数组 a 存在，那么对于每个 1≤i≤n，都应满足以下等式：
//pi = gcd(a1, a2, …, ai)
//si = gcd(ai, ai+1, …, an)
//请判断是否存在这样的数组 a，使得给定的数组 p 和 s 可以被得到。
//gcd(x,y) 表示整数 x 和 y 的最大公约数。
//输入
//第一行包含一个整数 t (1≤t≤10^4) —— 测试用例的数量。
//每个测试用例包含三行：
//第一行包含一个整数 n (1≤n≤10^5) —— 数组的长度。
//第二行包含 n 个整数 p1, p2, …, pn (1≤pi≤10^9) —— 数组元素。
//第三行包含 n 个整数 s1, s2, …, sn (1≤si≤10^9) —— 数组元素。
//保证所有测试用例的 n 之和不超过 10^5。
//输出
//对于每个测试用例，如果存在数组 a 可以得到给定的 p 和 s，输出 "Yes"，否则输出 "No"。
//字母大小写不限，例如 "yEs"、"yes"、"Yes"、"YES" 均可被视为肯定答案。
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

ll gcd(ll a, ll b) {
    while (b) {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> p(n), s(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    if (n == 1) {
        if (p[0] != s[0]) cout << "NO" << enl;
        else cout << "YES" << enl;
        return;
    }
    if (p.back() != s[0]) {  //前缀最后一个是总gcd 后缀第一个是总gcd 两个得相等
        cout << "NO" << enl;
        return;
    }
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = lcm(p[i], s[i]);  //构造则是俩者的lcm
    } 
    vector<ll> pre(n), suf(n);
    ll g = a[0];
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]); 
        pre[i] = g;
    }
    g = a[n - 1];
    suf[n - 1] = g;
    for (int i = n - 2; i >= 0; i--) {
        g = gcd(g, a[i]);
        suf[i] = g;
    }
    if (pre == p && suf == s) { //两者必须严格相等
        cout << "YES" << enl;
    } else {
        cout << "NO" << enl;
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