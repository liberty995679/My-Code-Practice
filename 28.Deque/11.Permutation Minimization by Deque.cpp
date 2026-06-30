//t个用例 输入n
//输入n个数的排列
//在每次将元素加入队列之前，你可以选择将其加入队首或队尾
//求处理完整个排列后，队列中元素字典序最小的可能序列
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
    int n;
    cin >> n; 
    deque<int> deq;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (deq.empty()) {
            deq.push_back(x);
            continue;
        } 
        int y = deq.front();
        if (x < y) deq.push_front(x);
        else deq.push_back(x);
    }
    for (auto it = deq.begin(); it != deq.end(); it++) {
        cout << *it;
        if (it != deq.end()) cout << ' ';
    }cout << enl;
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