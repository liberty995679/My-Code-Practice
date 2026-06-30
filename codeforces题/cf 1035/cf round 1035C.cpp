//给定四个正整数 n, l, r, k。你需要找到长度为 n 的、由整数组成的、字典序最小* 的数组 a，使得：
//对于所有 1 ≤ i ≤ n，满足 l ≤ a_i ≤ r。
//a₁ & a₂ & … & aₙ = a₁ ⊕ a₂ ⊕ … ⊕ aₙ，其中 & 表示按位与运算，⊕ 表示按位异或运算。
//如果不存在这样的数组，输出 -1。否则，由于整个数组可能太大而无法输出，请仅输出 aₖ。
//*字典序定义：​ 当且仅当满足以下条件之一时，数组 a 的字典序小于数组 b：
//a 是 b 的前缀，但 a ≠ b；或者
//在 a 和 b 首次不同的位置上，数组 a 的元素小于数组 b 中对应的元素。
//每个测试包含多组测试用例。第一行包含测试用例的数量 t (1 ≤ t ≤ 10⁴)。接下来是对测试用例的描述。
//每组测试用例包含四个正整数 n, l, r, k (1 ≤ k ≤ n ≤ 10¹⁸, 1 ≤ l ≤ r ≤ 10¹⁸)。
//对于每组测试用例，输出 aₖ；如果不存在满足条件的数组，则输出 -1。
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

void solve(){
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2 == 1) { //奇数全一样就行
        cout << l << enl;
        return;
    }
    if (n == 2) {  //2个数是无解的
        cout << -1 << enl;
        return;
    }
    ll x1 = l; ll x2 = 1;  // x & x & y & y == 0  /// x ^ x ^ y ^ y == 0
    while (x2 <= l) x2 <<= 1;  //构造an - 2 和 an - 1是严格大于l的数可以是2的幂
    if (x2 > r) {
        cout << -1 << enl;  
        return;
    } 
    if (k <= n - 2) cout << x1 << enl; //为了使得字典序最小，所以用前面尽量都是l
    else cout << x2 << enl;   
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