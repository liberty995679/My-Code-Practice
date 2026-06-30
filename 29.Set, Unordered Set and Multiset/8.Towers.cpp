//你按顺序得到 n 个立方体，你的任务是用它们来搭塔。
//每当两个立方体上下叠放时，上面的立方体必须比下面的立方体小。
//你必须按给定的顺序处理这些立方体。
//对于每个立方体，你既可以选择把它放在某个已有塔的顶部，也可以选择新建一个塔。
//问：在满足规则的前提下，最少需要搭多少个塔？
//n个立方体数量 然后输入边长
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
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    cin >> n;
    multiset<int> s;
    for (int i = 0; i < n;i++) {
        int x; cin >> x;
        auto it = s.upper_bound(x);  //找第一个>x的，也就是最小的塔顶
        if (it != s.end()) {
            s.erase(it);
            s.insert(x);
        } else {
            s.insert(x);
        }
    }
    cout << s.size() << enl;
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