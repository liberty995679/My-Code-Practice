//有 N个一次性工作可供选择。
//如果你接下第 i个工作并完成它，你会在开始做它的那一天起经过 Ai天后，获得奖励 Bi
//你每天最多只能接并完成一个工作。
//已经做过的工作不能再次接取。
//求在从今天起不超过 M天的时间内，你能获得的最大总奖励。
//你可以从今天就开始工作。
//输入n m n长度的a n长度的b
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
#include <map>
#include <set>
using namespace std;
using ll = long long;

struct work {
    ll a;
    ll b;
};

ll culculate(const vector<work>& a, int m) {
    int n = a.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0;
    for (int i = 0; i < n; i++) {  
        pq.push(a[i].b);
        sum += a[i].b;
        while (pq.size() > a[i].a + 1) {  //a[i].a是最晚开始时间从0开始，所以有a + 1天也就是最多a + 1的工作
            sum -= pq.top();
            pq.pop();
        }
    }
    return sum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<work> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a;
        arr[i].a  = m - arr[i].a;
        cin >> arr[i].b;
    }
    vector<work> use;
    for (int i = 0; i < n; i++) {
        if (arr[i].a >= 0) use.push_back(arr[i]);
    }
    sort(use.begin(), use.end(), [](const work& a, const work& b){
        return a.a < b.a;
    });
    ll res = culculate(use, m);
    cout << res << '\n';
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