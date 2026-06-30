//立方体的长宽高符合斐波那契数列
//f(1) = 1 f(2) = 2 f(x) = f(x - 1) + f(x - 2)
//有m个箱子，每个箱子都是不同的长宽高
//有n个立方体他们的大小符合斐波那契数列
//判断每一个箱子是否能装下n个大小不同的立方体
//t个用例 n数量 m数量 m行输入 w l h
//输出一个m长度的字符串 0 表示装不下 1 表示可以装下
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

vector<int> arr(11);

struct cube{
    int w;
    int l;
    int h;
};

void fob(int n) {
    arr[1] = 1;
    int a = 1; int b = 2;
    arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        arr[i] = a + b;
        a = b;
        b = arr[i];
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<cube> nums(m);
    string s = string(m, '0');
    int mn = arr[n];
    int mx = arr[n - 1] + arr[n];
    for (int i = 0; i < m; i++) {
        cin >> nums[i].w >> nums[i].l >> nums[i].h;
        int a = nums[i].w; int b = nums[i].l; int c = nums[i].h;
        if (a >= b && a >= c) {
            if (a >= mx && b >= mn && c >= mn) {
                s[i] = '1';
            }
        } else if (b >= a && b >= c) {
            if (b >= mx && a >= mn && c >= mn) {
                s[i] = '1';
            }
        } else if (c >= a && c >= b) {
            if (c >= mx && a >= mn && b >= mn) {
                s[i] = '1';
            }
        }
    }
    cout << s << endl;
}

int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    fob(11);
    while (t--) {
        solve();
    }
    return 0;
}