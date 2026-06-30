//一行包含一个整数 n：顾客的数量。
//接下来 n​ 行，每行描述一位顾客。每行有两个整数 a​ 和 b：分别表示到达日和离开日
//如果第一位顾客的离开日期早于第二位顾客的到达日期，那么这两位顾客可以住在同一个房间
//最少需要多少间房才能安排下所有顾客？并且如何分配房间？
//输出一个整数 k：所需的最少房间数量
//输出一行，包含每位顾客被分配到的房间号，顺序与输入一致
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
#include <map>
#include <set>
using namespace std;
using ll = long long;

struct guest{
    int a;
    int b;
    int id;
};

void solve() {
    int n;
    cin >> n ;
    vector<guest> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
        arr[i].id = i;
    }
    sort(arr.begin(), arr.end(), [](const guest& a, const guest& b){
        return a.a < b.a;
    });
    int room = 0; // 房间号
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//离开时间 房间号
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int get = arr[i].a; int leave = arr[i].b; int idx = arr[i].id;
        if (!pq.empty() && get > pq.top().first) {  //到达时间 > 原离开时间
            int newroom = pq.top().second;  //继承房间号
            pq.push({leave, newroom});
            pq.pop();
            ans[idx] = newroom;  //记录新房间号
        } else {
            room++;
            pq.push({leave, room});
            ans[idx] = room;
        }
    }
    cout << room << endl;
    for (auto it: ans) {
        cout << it << ' ';
    }cout << endl;
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