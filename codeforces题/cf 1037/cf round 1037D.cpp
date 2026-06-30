//你有 n​ 个赌场，编号从 1​ 到 n。
//每个赌场由三个整数描述：lᵢ、rᵢ​ 和 realᵢ（满足 lᵢ ≤ realᵢ ≤ rᵢ）。
//你初始拥有 k​ 枚硬币。
//只有在当前硬币数量 x​ 满足 lᵢ ≤ x ≤ rᵢ​ 时，你才能在赌场 i​ 玩。
//游玩之后，你的硬币数量将变为 realᵢ。
//你可以按任意顺序访问赌场，且不一定要访问全部。
//每个赌场最多只能访问一次。
//你的任务是找出你能获得的最大最终硬币数量。
//输入
//第一行包含一个整数 t（1 ≤ t ≤ 10⁴）——测试用例的数量。
//每个测试用例的第一行包含两个整数 n​ 和 k（1 ≤ n ≤ 10⁵，0 ≤ k ≤ 10⁹）——赌场的数量和初始硬币数量。
//接下来有 n​ 行。第 i​ 行包含三个整数 lᵢ、rᵢ、realᵢ（0 ≤ lᵢ ≤ realᵢ ≤ rᵢ ≤ 10⁹）——第 i​ 个赌场的参数。
//保证所有测试用例中 n​ 的总和不超过 10⁵。
//输出
//对于每个测试用例，输出一个整数——在最优选择访问赌场顺序后，你能获得的最大硬币数量。
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

struct cas{
    ll left;
    ll right;
    ll real;
};

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<cas> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].left >> a[i].right >> a[i].real;
    }
    sort(a.begin(), a.end(), [](const cas& a, const cas& b){
         return a.left < b.left;
    });
    priority_queue<ll> pq;
    int idx = 0;
    ll cur = k;
    while (true) {
        while (idx < n && a[idx].left <= cur) {  //把所有<= k 的left加进来real
            pq.push(a[idx].real);
            idx++;
        }
        if (!pq.empty()) {
            ll top = pq.top(); pq.pop();
            if (top > cur) {
                cur = top;
            } else {
                continue;
            }
        } else {
            break; //没有可玩的赌场了
        }
    }
    cout << cur << enl;
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