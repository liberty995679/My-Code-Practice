//给定一个整数数组作为输入
//取数组中的最大元素并除以 2（向下取整），然后再次放入数组
//打印数组中的最大元素
//第一行输入一个数字 t，表示数组中的元素数量,
//N,表示整数的数量每个测试用例的第二行包含 N 个用空格分隔的整数。
//对于每个测试用例，按照操作并打印所需的值
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

void culculate(priority_queue<int> pq) {
    while (!pq.empty()) {
        int it = pq.top();
        pq.pop();
        if (it > 0)  {
            cout << it << ' ';
            it /= 2;
            pq.push(it);
        }
    }
}

void solve() {
    int t;
    cin >> t;
    vector<priority_queue<int>> pq(t);
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            pq[i].push(x);
        }
        culculate(pq[i]);
        cout << '\n';
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