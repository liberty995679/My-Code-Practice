//给定一个长度为 n的排列 p。你可以执行以下操作任意次：
//选择一段长度为 3 的子数组（subarray），然后删除其中的最小元素或最大元素。
//例如，对于排列 [2,4,5,3,1]，你可以选择子数组 [2,4,5]（它是原数组的一个连续段），因为 5=max(2,4,5)，所以可以删除 5，得到数组 [2,4,3,1]。
//你也可以选择删除 2，因为 2=min(2,4,5)。
//对每个 i从 1到 n，求出包含数字 pi​ 的可达数组的最小长度。
//注意：这个问题需要对每个 i独立求解。
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

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << 1 << enl;
    } else {
        for (int i = 0; i < n; i++)  {
            cout << 2 << ' ';
        }cout << enl;
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