//汉诺塔问题
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>   
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;
int cnt = 0;
vector<pair<int,int>> res;
//把 n 个盘子 从 left 借助 mid 移到 right
void hanoi(int n, int left, int mid, int right) {
    if (n == 0) return;
    hanoi(n - 1, left, right, mid);
    res.push_back({left, right});
    hanoi(n - 1, mid, left, right);
}


void solve() {
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << res.size() << endl;
    for (auto& i: res) {
        cout << i.first << ' ' << i.second << endl;
    }
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