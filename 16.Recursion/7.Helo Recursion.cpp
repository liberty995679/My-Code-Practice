//递归，输出数组里的数字总和
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int solve (int n, vector<int> &arr) {
    if (n == 0) return 0;
    return arr[n - 1] + solve(n - 1, arr);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int count = 0;
    while (t--) {
        int n;
        cin >> n;
        count++;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << "Case " << count << ": " << solve(n, nums) <<'\n';
    }
    return 0;
}