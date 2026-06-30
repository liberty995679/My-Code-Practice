//递归，回文数组
#include <iostream>
#include <vector>
using namespace std;

bool solve (int a, int n, vector<int> &arr) {
    if (a >= n) return true;
    if (arr[a] != arr[n]) {
        return false;
    } 
    return solve(a + 1, n - 1, arr);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (solve(0, n - 1, arr)) cout << "YES" << endl;
     else cout << "NO" << endl;
    return 0;
}