//第 i 个孩子至少想要得到 aᵢ 颗糖果
//给队首的孩子 m 颗糖果
//如果这个孩子仍然没有拿到足够数量的糖果，就让他去队尾
//否则，这个孩子就可以回家
//第一行包含两个整数 n, m (1 ≤ n ≤ 100; 1 ≤ m ≤ 100)。
//第二行包含 n 个整数 a₁, a₂, ..., aₙ (1 ≤ aᵢ ≤ 100)。
//输出一个整数，表示最后一个回家的孩子的编号
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

void solve() {
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> que;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        que.push({i, x});
    }
    while (que.size() > 1) {
        auto it = que.front();
        int candy = it.second;
        que.pop();
        if (candy > m) {
            candy -= m;
            que.push({it.first, candy});
        }
    }
    cout << que.front().first << endl;
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