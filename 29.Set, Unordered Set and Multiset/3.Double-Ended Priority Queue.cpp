//给定一个多重集合
//依次处理以下 Q 条查询：
//0 x：向 S 中添加一个元素 x
//1：输出 S 中的一个最小元素，并将其从 S 中移除。
//2：输出 S 中的一个最大元素，并将其从 S 中移除。
//保证在处理类型为 1 和 2 的查询时，S 绝对不会为空。
//输入n q 输入q条查询
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
    multiset<int> s;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    while (q--) {
        int t, x;
        cin >> t;
        if (t == 0) {
            cin >> x;
            s.insert(x);
        } else if (t == 1) {
            cout << *s.begin() << enl;
            s.erase(s.begin());
        } else {
            cout << *s.rbegin() << enl;  //反向迭代器 最大值
            s.erase(prev(s.end()));  //erase需要正向迭代器 所以是s.end()的前一个
        }
    }

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