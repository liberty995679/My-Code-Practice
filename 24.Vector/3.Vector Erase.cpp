//给定一个整数n 和数组a
//输入一个数x 表示要删除的元素位置 (删除一次)
//输入两个数a 和 b 表示删除的范围 (删除一次)
//输出删除完元素的数组大小
//输出剩余元素
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int x, a, b;
    cin >> x >> a >> b;
    arr.erase(arr.begin() + x - 1);
    arr.erase(arr.begin() + a - 1, arr.begin() + b - 1);
    cout << arr.size() << endl;
    for (const auto& i: arr) {
        cout << i << ' ';
    }cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE   //HakerRank 不能用这个 ，记得注释掉
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}