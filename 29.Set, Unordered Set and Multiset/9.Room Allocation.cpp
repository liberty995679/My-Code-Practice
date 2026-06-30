//有一家大酒店，即将有 n 位客人到来。
//每位客人需要一个单人间。
//你知道每位客人的入住日期和退房日期。
//如果第一位客人的退房日期早于第二位客人的入住日期，那么这两位客人可以住在同一个房间。
//问：为了接待所有客人，最少需要多少个房间？
//并且给出一种房间的分配方案。
//输入格式​
//第一行有一个整数 n，表示客人的数量。
//接下来有 n 行，每行描述一位客人。
//每行有两个整数 a 和 b，表示该客人的入住日期和退房日期。
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
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

struct guest{
    int a;
    int b;
    int id;
};

void solve() {
    int n;
    cin >> n;
    vector<guest> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
        arr[i].id = i;
    }
    sort(arr.begin(), arr.end(), [](const guest& a, const guest& b) {
        return a.a < b.a;
    });
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int room = 0;  //房间号
    vector<int> ans(n);  //结果存储
    for (int i = 0; i < n; i++) {
        int got = arr[i].a; int leave = arr[i].b; int idx = arr[i].id;
        if (!pq.empty() && got > pq.top().first) {
            int newroom = pq.top().second;
            pq.push({leave, newroom});
            pq.pop();
            ans[idx] = newroom; //别搞错了位置
        } else {
            room++;
            pq.push({leave, room});
            ans[idx] = room;
        }
    }
    cout << room << enl;
    for (auto it: ans) {
        cout << it << ' ';
    }cout << enl;
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