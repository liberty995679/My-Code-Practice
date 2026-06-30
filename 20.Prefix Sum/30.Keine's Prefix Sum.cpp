//n个元素的数组a 可以循环
//a1 a2 a3 ... an , a2 a3 .. an a1 , a3 ... an a1 a2
//求这些前缀和,满足所有si >= 0的数组为好数组
//计算有几个好数组
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <deque>
#include <unordered_map>
#include <set>

using namespace std;
using ll = long long;

void solve() {  //因为数据在 n <= 1e5 , 用下标模拟循环是O(n^2)超时，所以用单调队列
    int n;
    cin >> n;
    vector<int> arr(2 * n + 1);
    vector<int> pre(2  * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }
    int ans = 0;
    deque<int> dq;  //用单调队列找区间内前缀和的最小值
    for (int i = 1; i <= 2 * n; i++) {  //i 代表右边的端点
        while (!dq.empty() && pre[dq.back()] >= pre[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (dq.front() <= i - n) { //区间为n,  右区间为i ，左区间为i - n + 1
            dq.pop_front();  //删除左边
        }
        if (i >= n && i <= 2 * n - 1) {  //从区间n开始判断 pre[r] - pre[l - 1] >= 0 即 pre[r] >= pre[l - 1]
            if (pre[dq.front()] >= pre[i - n])  ans++;
        }
    }
    cout << ans << endl;
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