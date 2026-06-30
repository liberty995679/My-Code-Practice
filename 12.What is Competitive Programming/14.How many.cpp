//满足 a+b+c≤S 和 
//a×b×c≤T 的非负整数三元组(a,b,c)(a,b,c) 有多少个？
//输入的是s 和 t
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void solve() {
    int s, t;
    cin >> s >> t;
    int cnt = 0;
    for (int a = 0; a <= s; a++) {
        for (int b = 0; b <= s; b++) {
            for (int c = 0; c <= s; c++) {
                if (a + b + c <= s && a * b * c <= t) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
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