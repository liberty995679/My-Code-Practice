//你正在用智能手机在一个流行的社交网络上发消息。你的手机屏幕最多显示 k 个最近与朋友的聊天会话。初始时屏幕是空的（即显示的会话数为 0）。
//每个会话是你和某个朋友之间的对话。你和任意一个朋友最多只有一个会话，因此每个会话由唯一的朋友 ID 确定。
//你突然拥有了预知未来的能力。你知道今天你会收到 n 条消息，第 i 条消息来自朋友 ID 为 idi（1 ≤ idi ≤ 10^9）。
//如果你收到的消息来自的朋友的会话已经在屏幕上显示，那么什么都不会发生：屏幕上的会话顺序不变，你只是阅读消息并继续等待新消息。
//否则（即屏幕上还没有与该朋友 idi 的会话）：
//首先，如果屏幕上已显示的会话数等于 k，则移除最后一个（第 k 位的）会话。
//现在屏幕上的会话数一定小于 k，并且与朋友 idi 的会话不在屏幕上。
//与朋友 idi 的会话会出现在屏幕的第一个（最顶部）位置，其他已显示的会话都向下移动一个位置。
//你的任务是，在处理完所有 n 条消息后，输出屏幕上显示的会话列表（按屏幕上的显示顺序）
//输入n 和 k 输入n长度的数组a
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
const char enl = '\n';

void solve() {
    int n, k;
    cin >> n >> k;
    deque<ll> deq;
    unordered_map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (mp.find(x) == mp.end() || mp[x] == 0) {
            deq.push_front(x);
            mp[x]++;
        } 
        if (deq.size() > k) {
            mp[deq.back()] = 0;
            deq.pop_back();
        }
    }
    cout << deq.size() << enl;
    for (auto i: deq) {
        cout << i << ' ';
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