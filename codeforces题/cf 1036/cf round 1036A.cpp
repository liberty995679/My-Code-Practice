//定义长度为 m 的数组 b 为“错位排列”，如果它满足以下性质：
//令 c 为一个长度为 m 的数组，使得对所有 1 ≤ i ≤ m，都有 c_i = b_i。
//将 c 按非递减顺序排序。
//如果对所有 1 ≤ i ≤ m，都有 b_i ≠ c_i，那么 b 就是错位排列。
//例如：
//若 b = [4, 8, 3, 1]，排序后 c = [1, 3, 4, 8]。由于在每一个位置 i 上都有 b_i ≠ c_i，因此 b 是错位排列。
//若 b = [3, 2, 1]，排序后 c = [1, 2, 3]。因为 b_2 = c_2，所以 b 不是错位排列。
//给定一个长度为 n 的数组 a。在一次操作中，你可以从 a 中删除一个元素。每次删除后，剩余元素的相对顺序保持不变。
//请判断是否可以执行若干次操作（也可以不执行），使得剩余元素组成的数组是错位排列。
//如果可以，输出任意一个满足条件的剩余数组。剩余数组必须非空。
//t个用例 长度n 数组a
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

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int p = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> b = arr;
    vector<int> res;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (b[i] != arr[i]) {
            p = i;
            res.push_back(arr[i]);
        }
    }
    if (p == -1 || res.size() <= 1) {
        cout << "NO" << enl;
    } else {
        vector<int> c = res;
        sort(c.begin(), c.end());
        for (int i = 0; i < res.size(); i++) {
            if (c[i] == res[i])  {
                cout << "NO" << enl;
                return;
            }
        }
        cout << "YES" << enl;
        cout << res.size() << enl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << ' ';
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