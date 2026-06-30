//Alice 有一个由 n 个正整数组成的数组 a。该数组满足一个优美的性质：对于每个 1≤i≤n-1，a_i 整除 a_{i+1}。
//Bob 看到了 Alice 的优美数组并心生嫉妒。为了搞破坏，Bob 首先创建一个大小为 n 的数组 b，使得对于每个 1≤i≤n，b_i=a_i。然后，他选择一个正整数 x，并将 b 中的某些元素（可以是零个，也可以是全部）乘以 x。
//形式上，他选择一个（可能是空的）子集 S⊆{1,2,…,n}，并对每个 i∈S，执行 b_i:=b_i⋅x。
//现在给定数组 b，但你不知道数组 a 和所选的数 x。请输出 Bob 可能选择的任意整数 x，使得通过对正确的数组 a 的某个子集元素乘以 x 能得到数组 b。保证答案存在。如果存在多个可能的整数，你可以输出其中任意一个。
//Input
//每个测试包含多组测试用例。第一行给出测试用例的数量 t（1≤t≤2⋅10^5）。接下来是各测试用例的描述。
//每个测试用例的第一行给出一个整数 n（2≤n≤6⋅10^5）——数组 b 的长度。
//每个测试用例的第二行给出 n 个整数 b_1,b_2,…,b_n（1≤b_i≤10^9）——表示数组 b。
//保证数组 b 可以按照题目描述，从某个优美数组 a 和某个正整数 x 得到。
//保证所有测试用例中 n 的总和不超过 6⋅10^5。
//Output
//对于每个测试用例，在一行中输出 x 的任意一个可能值（1≤x≤10^9）。保证至少存在一个 x。
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
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    ll g = 0;
    ll lc = 1;
    for (int i = n - 1; i >= 0; i--) { //所有 b [i] 去掉公共因子后，剩下部分的最小公倍数（LCM）
        g = gcd(g, b[i]);  // 求整个数组的公共 gcd
        lc = lcm(lc, b[i] / g);  // 求去掉公共gcd后的值的 lcm
    }
    cout << lc << enl;
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