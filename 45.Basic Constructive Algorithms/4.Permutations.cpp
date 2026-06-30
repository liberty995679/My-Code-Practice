//构造一个美丽排列，任意两个相邻元素的差值不为1，如果没有输出NO SOLUTION
#include <iostream>
#include <vector>    

using namespace std;
typedef long long ll;

void solve(int n) {
    vector<int> a(n);
    if (n == 3 || n == 2) {
        cout << "NO SOLUTION" << endl;
        return;
    } 
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    vector<int> odd, even;
    for (int i = 0; i < n; i += 2) {
        odd.push_back(a[i]);
    }
    for (int i = 1; i < n; i += 2) {
        even.push_back(a[i]);
    }
    even.insert(even.end(), odd.begin(), odd.end());
    for (const auto &i: even) {
        cout << i << ' ';
    }cout << endl;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    solve(n);
    return 0;
}