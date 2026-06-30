//一场锦标赛有 n名选手参加，选手 i的力量值为 ai
//当剩余选手人数多于 k时，重复以下步骤：
//随机选择两名剩余的选手；
//力量较低的选手被淘汰；
//如果两人力量相同，则随机淘汰其中一人。
//给定整数 j和 k（1≤j,k≤n），判断选手 j是否有办法成为最后剩下的 k名选手之一
//t个用例 n长度 j选手 k名选手
//输入数组a
//如果可以输出 YES 否则输出NO
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
    int n, j, k;
    cin >> n >> j >> k;
    int cnt = 0;
    vector<int> arr(n);
    for (int &i: arr) cin >> i;
    if (k > 1) {  //当k大于1的时候， aj 可能永远都抽不到，因为是随机的
        cout << "YES" << enl;
        return;
    } else if (k == 1) {  //当k == 1的时候 只有aj 是最大值才能活下来
        int mx = *max_element(arr.begin(), arr.end());
        cout << (arr[j - 1] == mx ? "YES" : "NO") << enl;
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