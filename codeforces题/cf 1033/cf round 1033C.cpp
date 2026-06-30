//Harshith 在一棵神树（Divine Tree）下修炼，终于在竞赛编程中获得了顿悟。
//一棵神树是一棵有根树*，共有 n个节点，编号从 1到 n。
//节点 v的“神圣值”（divineness）d(v)定义为：从根到节点 v的唯一简单路径上，所有节点编号的最小值。
//Aryan 作为一个求知若渴的竞赛程序员，请求 Harshith 传授这份知识。
//Harshith 同意的条件是：给 Aryan 两个正整数 n和 m
//让他构造一棵有 n个节点的神树，使得整棵树的神圣值之和恰好为 m，即 i=1-n∑d(i) = m
//如果无法构造这样的树，Aryan 必须报告“不可能”。
//渴望知识的 Aryan 向你求助，希望你能帮他完成这个任务。作为他的好朋友，请你帮他解决这个问题。
//*树是一个无环的连通图。有根树是一棵树，其中一个顶点被特别指定为根。
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
    ll n, m;
    cin >> n >> m;
    ll min_sum = n;
    ll max_sum = (n + 1) * n / 2;
    //范围之外无解
    if (m < min_sum || m > max_sum) {
        cout << -1 << enl;
        return;
    }
    vector<ll> d(n + 1);
    ll sum = 0;  //记录前面和
    for (int i = 1; i <= n; i++) {
        ll mx = n - i + 1; //i能取到的最大值
        ll remain = m - sum;  //还差多少满足m
        if (remain >= mx + (n - i) * 1) { //如果i可以用最大值而剩下的用1
            d[i] = mx;
        } else {
            d[i] = remain - (n - i); //取不到，差值减去n - i 个1,就是减去右边的1
        }
        sum += d[i];
    }
    // d 的结果应该是 3 1 1 1这种
    vector<ll> ans(n + 1);
    set<ll> s; //存用不到的数
    for (int i = 1; i <= n; i++) s.insert(i);
    for (int i = 1; i <= n; i++) {
        if (i == 1 || d[i] < d[i - 1]) { //开头或者 当前值比前者更小
            ans[i] = d[i];
            s.erase(d[i]);
        } else { //相同时 ， 1 1 1这种 从后往前添加
            auto it = prev(s.end());
            ans[i] = *it;
            s.erase(it);
        }
    }
    // 输出根节点
    cout << ans[1] << enl;
    // 输出边（链结构）
    for (int i = 2; i <= n; i++) {
        cout << ans[i - 1] << ' ' << ans[i] << enl;
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