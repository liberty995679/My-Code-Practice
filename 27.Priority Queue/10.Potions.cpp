//有一排药水
//里面有正数也有负数
//你必须从左到右进行喝药水，可以喝也可以不喝
//确保自己的生命是非负数
//计算最多可以喝多少的药水
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

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll health = 0;
    ll cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <n; i++) {
        health += arr[i];
        pq.push(arr[i]); //每一次都尝试喝
        if (health < 0) {  //小于0就把最小的那个踢出来
            while (health < 0 && !pq.empty()) {
                ll top = pq.top(); pq.pop();
                if (top < 0) health -= top;
                else health += top;
            }
        }
    }
    cout << pq.size() << '\n';
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