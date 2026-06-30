//给定一个大小为 n 的数组 a 和一个参数 k，如果满足以下条件，则称数组 b 是酷的：
//对于每个 i 从 k 到 n，子数组 [a{i-k+1}, a{i-k+2}, …, a_i] 是 [b{i-k+1}, b{i-k+2}, …, b_i] 的一个重排。
//给定两个大小为 n 的数组 a 和 b，以及一个整数 k。数组 a 保证是一个排列。数组 b 只包含从 1 到 n 的整数，以及 -1。
//判断是否可以替换 b 中的所有 -1 为 1 到 n 之间的某个整数，使得 b 关于 k 是酷的。
//排列：长度为 n 的排列是由 1 到 n 的不同整数按任意顺序排列组成的数组。例如 [2,3,1,5,4] 是排列，但 [1,2,2] 不是（2 出现两次），[1,3,4] 也不是（n=3 但出现了 4）。
//输入：
//每个测试包含多个测试用例。第一行包含测试用例数量 t (1≤t≤10^4)。接下来是测试用例的描述。
//每个测试用例的第一行包含两个整数 n 和 k (1≤k≤n≤2×10^5)。
//第二行包含 n 个整数 a_1, a_2, …, a_n (1≤a_i≤n)。在这个版本中，保证 1 到 n 的每个数恰好出现一次。
//第三行包含 n 个整数 b_1, b_2, …, b_n (1≤b_i≤n 或 b_i=-1)。
//保证所有测试用例的 n 之和不超过 2×10^5。
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    unordered_map<int, int> pos, cnt; //记录a的位置，还有b的数量
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i< n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        if (i >= k) {  //超过k的部分减去
            if (b[i - k] != -1) {
                cnt[b[i - k]]--;
            }
        }
        if (b[i] != -1) {  //bi不是-1
            cnt[b[i]]++;
            if (cnt[b[i]] > 1) {
                cout << "NO" << enl;
                return;
            }
            int p = pos[b[i]];  //要么位置没变，要么原始位置和新位置都在 [n-k, k-1] 的自由排列区内
            if (p != i && !(p >= n - k && p <= k - 1 && i >= n - k && i <= k - 1)) { // a[i - k + 1] -> a[i] == k
                cout << "NO" << enl;  //中间可以换的区间为 n - k, k - 1
                return;
            }
        }
    }
    cout << "YES" << enl;
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