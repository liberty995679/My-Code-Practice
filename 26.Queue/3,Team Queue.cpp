//t个团队 每个团队n个人 然后输入每个人
//有t个团队的人正在排一个长队
//ENQUEUE：编号为X的人进入长队。
//DEQUEUE：长队队首出队。
//STOP：停止模拟
//对于每组测试数据，先打印一句"Scenario #k"，k是第几组数据。
//对于每个DEQUEUE指令，输出出队的人的编号
//t == 0 退出
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

int k = 1;

void solve(int t) {
    vector<queue<int>> que(t);
    queue<int> team;  //大团队顺序
    unordered_map<int, int> mp;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n; 
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            mp[a] = i;
        }
    }
    string s;
    cout << "Scenario #" << k++ << '\n';
    while (cin >> s) {
        if (s == "STOP") break;
        if (s == "ENQUEUE") {
            int x; cin >> x;
            int idx = mp[x];
            if (que[idx].empty()) {
                team.push(idx); //存团队顺序
            }
            que[idx].push(x);
        } else {
            int teamidx = team.front();
            int cur = que[teamidx].front();  //输出该团队第一个人
            que[teamidx].pop();
            if (que[teamidx].empty()) { //如果大团队里小团队没人了
                team.pop();
            }
            cout << cur << '\n';
        }
    }
    cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    while (cin >> t) {
        if (t == 0) break;
        solve(t);
    }
    return 0;
}