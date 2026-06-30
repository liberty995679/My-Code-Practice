//两名无聊的士兵正在玩卡牌对战游戏。他们的牌堆由恰好n张牌组成，编号从1到n，且所有牌面数值都不相同。
//他们以某种方式分配了这些卡牌，双方持有的卡牌数量可能不同。然后他们开始玩类似"战争"的卡牌游戏。
//游戏规则如下：每轮会发生一次对决。双方各自从牌堆顶部抽出一张牌放在桌面上。
//牌面数值较大的一方赢得本次对决，并将两张牌收入自己牌堆底部。
//具体来说，获胜方会先将对手的牌放入牌堆底部，再放入自己的牌。如果在某轮结束后某一方的牌堆被抽空，则该方判负，另一方获胜。
//你需要计算总共会发生多少次对决，并预测最终获胜者，或者判断游戏是否会无限进行下去
//输入整数n 表示卡牌总数
//输入k1 输入k1个整数
//输入k2 输入k2个整数
//若有玩家获胜，则输出2个整数，其中第一个数表示游戏结束前的对决次数，第二个数为1或2表示获胜玩家。
//若游戏将无限进行，则输出 - 1。
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
    int k1, k2;
    cin >> k1;
    deque<int> player1, player2;
    int x;
    for (int i = 0 ; i < k1 ; i++) {
        cin >> x;
        player1.push_back(x);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        cin >> x;
        player2.push_back(x);
    }
    int cnt = 0;
    while (!player1.empty() && !player2.empty()) {
        if (cnt > 10000) break;
        int x1 = player1.front(); player1.pop_front();
        int x2 = player2.front(); player2.pop_front();
        if (x1 > x2) {
            player1.push_back(x2);
            player1.push_back(x1);
        } else {
            player2.push_back(x1);
            player2.push_back(x2);
        }
        cnt++;
    }
    if (cnt > 10000) {
        cout << -1 << enl;
    } else {
        cout << cnt << ' ';
        cout << (player2.empty() ? 1 : 2) << enl;
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