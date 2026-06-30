//t个用例 n数组长度
//规定将数组a划分成不同的连续段b
//并且bi 中有的数 在 bi+1中必须有
//例如 1 2 ，则bi + 1可以是 1 2 3而bi + 2 可以是 1 2 3 2
//尽可能让它划分的数组更大
//输出它最大能划分的数量
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
vector<int> tag_num(2e5 + 5); // 记录当前子段统计时的标记
int tag = 0;
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> prefix;
    unordered_map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!mp.count(arr[i])) {
            cnt++;
            mp[arr[i]]++;
        }
        prefix.push_back(cnt);  //统计前缀不同元素的数量
    }
    tag++;
    int goal = prefix[n - 1];
    int res = 0; int cnt1 = 0;
    for (int i = n - 1; i >= 0; i--) { //从后面开始找
        if (tag_num[arr[i]] != tag) {
            tag_num[arr[i]] = tag; 
            cnt1++;
        }
        if (cnt1 == goal) {  //[i, end] 的元素数 == [0, end] 的元素数
            res++;
            cnt1 = 0;
            tag++;
            if (i > 0) goal = prefix[i - 1];
        }
    }
    cout << res << '\n';
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