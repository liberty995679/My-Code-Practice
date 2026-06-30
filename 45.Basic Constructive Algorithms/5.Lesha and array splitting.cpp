//将数组分段，使其子数组和为非零，并输出坐标，否则输出0
#include <iostream>
#include <vector>

using namespace std;

void solve(const vector<int> &a) {
    int n = a.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) { 
        prefix[i + 1] = prefix[i] + a[i];
    }
    if (prefix[n] != 0) {   //总和不为0
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << ' ' << n << endl;
        return;
    }
    if (prefix[n] == 0) {   //总和为0，找不为0的位置进行分割
        bool flag = false;
        for (int i = 1; i < n + 1; i++) {
            if (prefix[i] != 0) {
                flag = true;
                if (prefix[n] - prefix[i] != 0) {
                        cout << "YES" << endl;
                        cout << 2 << endl;
                        cout << 1 << ' ' << i << endl;
                        cout << i + 1 << ' ' << n << endl;
                        return;
                }
            }
        }
        if (!flag) {  //总和为0，且每一段都是0
            cout << "NO" << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    solve(a);
    return 0;
}