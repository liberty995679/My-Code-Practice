//你现在身处一个地下城，里面有 n把剑，同时有 m只怪物。
//第 i把剑的伤害为 ai，第 i只怪物的生命值为 bi
//一把伤害为 x的剑能杀死生命值为 y的怪物，当且仅当 x≥y。
//当你用一把伤害为 x的剑杀死了第 i只怪物后，这把剑会消失。
//如果 ci>0，你会获得一把新的剑，其伤害为 max(x,ci)；如果 ci=0，则不会获得新剑。
//现在你想知道，最多可以杀死多少只怪物。
//注意：每只怪物最多只能被杀死一次。
//t个用例 n m 输入n长度的a m长度的b 和 c
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

struct mons{
    ll b;
    ll c;
};

ll culculate(multiset<ll> &a,const vector<mons>& h_c, const vector<mons>& hn_c) {
    ll res = 0;
    for (int i = 0; i < h_c.size(); i++) {
        auto it = a.lower_bound(h_c[i].b);
        if (it != a.end()) {
            ll newsword = max(*it, h_c[i].c);//新剑
            a.erase(it);
            a.insert(newsword);
            res++;
        }
    }
    for (int i = 0;i < hn_c.size(); i++) {
        auto it = a.lower_bound(hn_c[i].b);
        if (it != a.end()) {
            a.erase(it);
            res++;
        }
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<ll> a;  //用multiset存剑，自动排序且可以重复
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a.insert(x);  //优先使用小攻击的剑
    }
    vector<mons> arr(m);
    for (int i = 0; i < m; i++) cin >> arr[i].b;
    for (int i = 0; i < m; i++) cin >> arr[i].c;
    vector<mons> has_c, hasn_c; //把能换剑和不能换剑分开
    for (const auto& i: arr) {
        if (i.c > 0) has_c.push_back(i);
        else hasn_c.push_back(i);
    }
    auto cmp = [](const mons& a, const mons& b) {return a.b < b.b; }; //按血量升序
    sort(has_c.begin(), has_c.end(), cmp);
    sort(hasn_c.begin(), hasn_c.end(), cmp);
    ll res = culculate(a, has_c, hasn_c);
    cout << res << '\n';
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