//伯兰国即将在近期推出名为"Berlandesk"的新型电子邮件服务。网站管理团队希望尽快启动项目，因此邀请您协助开发。
//您需要实现网站注册系统的原型，该系统需遵循以下运作机制：
//每当新用户尝试注册时，需向系统发送包含其用户名的请求。
//若该用户名未存在于系统数据库中，则将其录入数据库并返回OK响应确认注册成功。
//若数据库中已存在该用户名，系统将生成新用户名作为提示返回给用户，同时将该提示名也存入数据库。新用户名按以下规则生成：从1开始依次尝试将数字附加到原用户名后（如name1、name2等），直到找到满足namei在数据库中不存在的最小数字i。
//首行给出整数n（1 ≤ n ≤ 105）。随后n行包含系统请求，每个请求为不超过32个字符的非空行，且仅包含小写拉丁字母。
//输出n行系统响应：成功注册时输出OK；当请求用户名已被占用时，返回生成的新用户名提示。
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

void solve() {
    int n;
    cin >> n;
    string s;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (mp.find(s) != mp.end()) {
            string ans = s + to_string(mp[s]);
            cout << ans << enl;
        } else {
            cout << "OK" << enl;
        }
        mp[s]++;
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