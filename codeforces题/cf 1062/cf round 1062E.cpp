//t个用例 n长度，k个传送器， x表示范围,数组ai
//Khba 有 n个朋友，他们分别站在一条线段上的位置,每个位置都在区间 [0,x]内。
//他们都要来找 Khba。他的一个朋友 Isamatdin 给了他 k个传送器。
//每个朋友会走向离自己最近的传送器（选择最短距离）。一旦朋友到达某个传送器，Khba 和朋友就可以瞬间相遇。
//但 Khba 很累，会在朋友们走过来时睡觉。现在他想选择 k个传送器的位置，
//这些位置必须互不相同且在 [0,x]范围内，使得第一个到达传送器的朋友所花的时间尽可能大。
//假设所有朋友移动速度相同。
//因为 Khba 不擅长计算，你需要输出这 k个传送器的位置
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

ll k, x , n;
vector<ll> arr;

bool check(ll d) {
    ll cnt = 0;
    ll last = -1; // 记录上一个被统计过的坐标
    if (arr[0] - d >= 0) {
        cnt += arr[0] - d - 0 + 1;  //找区间内的元素数 [0, arr[0] - d]
        last = arr[0] - d;
    }
    if (cnt >= k) return true;
    for (ll i = 1; i < n; i++) {  //中间区间
        ll left = max(last + 1, arr[i - 1] + d); // 关键修改：避免端点重复
        ll right = arr[i] - d;
        if (left <= right) {
            cnt += right - left + 1;
            last = right;
        }
        if (cnt >= k) return true;
    }
    ll left = max(last + 1, arr[n - 1] + d); // 关键修改
    if (left <= x) {  //尾区间
        cnt += x - left + 1;
    }
    return cnt >= k;
}

void solve() {
    cin >> n >> k >> x;
    arr.assign(n, 0);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll l = 0; ll r = x + 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ll d = l;
    vector<ll> ans;
    ll last = -1; // 记录上一个被存入答案的坐标
    for (ll i = 0; i <= arr[0] - d && ans.size() < k; i++) {
        ans.push_back(i);
        last = i;
    }
    for (ll i = 1; i < n; i++) {
        ll L = max(last + 1, arr[i - 1] + d); // 关键修改
        ll R = arr[i] - d; 
        for (ll j = L; j <= R && ans.size() < k; j++) {
            ans.push_back(j);
            last = j;
        }
    }
    ll L = max(last + 1, arr[n - 1] + d); // 关键修改
    for (ll i = L; i <= x && ans.size() < k; i++) {
        ans.push_back(i);
        last = i;
    }
    for (const auto& it: ans) {
        cout << it << ' ';
    }cout << '\n';
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