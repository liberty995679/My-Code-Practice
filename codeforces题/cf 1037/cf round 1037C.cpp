//你有 n​ 座塔，编号从 1​ 到 n。第 i​ 座塔的高度为 hᵢ。
//在时间 0​ 时，你位于编号为 k​ 的塔上，当前水位为 1。
//每一秒，水位上升 1​ 个单位。在任何时刻，如果水位变得严格大于你所在塔的高度，你就会死亡。
//你拥有一种魔法能力：在时刻 x，你可以开始从塔 i​ 传送到塔 j，这需要 |hᵢ − hⱼ|​ 秒。也就是说，直到时刻 x + |hᵢ − hⱼ|，你都还在塔 i​ 上，而在时刻 x + |hᵢ − hⱼ|，你会移动到塔 j。你可以在刚到达塔 j​ 的同一时刻开始新的传送。
//例如，如果 n = k = 4，h = [4, 4, 4, 2]，那么如果你在时刻 0​ 开始从塔 4​ 传送到塔 1，移动过程如下：
//（注：原文此处应有图示，但文本中未给出具体细节，根据描述可理解过程）
//注意，如果塔 1​ 的高度是 5，你就不能立即传送到它，因为你会在时刻 2​ 被淹没（水位达到 3，而塔 4 高度为 2，在时刻 2 水位 3 > 2，会死）。
//你的目标是在水淹没你之前，到达任意一座具有最大高度的塔。
//判断这是否可能。
//输入
//每个测试包含多个测试用例。
//第一行包含一个整数 t（1 ≤ t ≤ 10⁴）——测试用例的数量。接下来是测试用例的描述。
//每个测试用例的第一行包含两个整数 n​ 和 k（1 ≤ k ≤ n ≤ 10⁵）——塔的数量和你初始所在的塔的编号。
//第二行包含 n​ 个整数 h₁, h₂, …, hₙ（1 ≤ hᵢ ≤ 10⁹）——各塔的高度。
//保证所有测试用例中 n​ 的总和不超过 10⁵。
//输出
//对于每个测试用例，输出一行：
//如果能在水淹没你之前到达具有最大高度的塔，输出 "YES"；否则输出 "NO"。
//你可以以任意大小写形式输出字母。例如，"yEs"、"yes"、"Yes" 和 "YES" 都会被接受为肯定答案。
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<ll> s;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i: a) {
        if (!s.count(i)) {
            pq.push(i);
            s.insert(i);
        }
    }
    ll h = a[k - 1]; //初始的高度
    ll cur = h;
    while (!pq.empty()) {
        ll top = pq.top();
        pq.pop();
        if (top <= h) continue;
        if (h >= abs(top - cur)) {
            cur = top;
        } else {
            break;
        }
    }
    ll mx = *max_element(a.begin(), a.end());
    if (cur == mx) {
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