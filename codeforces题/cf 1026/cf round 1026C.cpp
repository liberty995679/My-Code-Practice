//你拥有一架无人机
//无人机需要飞过n 个 障碍物赛道
//无人机的高度为hi 当 li <= hi <= ri时，无人机可以通过
//给你一个数组d  di = hi - h(i - 1)
//di 可以为0 或者 1， 如果是-1，需要你手动调节
//如果调节后的数组d 能使得无人机通过所有障碍物则输出d
//否则输出 -1
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

struct dron{
    int l;
    int r;
};
int n;
void solve() { 
    cin >> n;
    vector<int> d(n);
    vector<dron> a(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r;
    bool flag = true;
    vector<int> p;
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == -1) {
            p.push_back(i);
        } else {
            h += d[i];
        }
        while (h < a[i].l) {  // 高度下界不足：把最近的待定改成 1 来拉高
            if (p.empty()) {
                flag = false;
                break;
            }
            d[p.back()] = 1;
            h++;
            p.pop_back();
        }
        if (!flag) break;
        while (h + (int)p.size() > a[i].r) { // 高度上界超出：把最近的待定固定为 0，缩小上界
            if (p.empty()) {
                flag = false;
                break;
            }
            d[p.back()] = 0;
            p.pop_back();
        }
        if (!flag) break;
    }
    if (!flag) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << max(d[i], 0) << ' '; //p没被动过的下标，d[i] 还是 -1，直接输出就错了
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
    while (t--) {
        solve();
    }
    return 0;
}