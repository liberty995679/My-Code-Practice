//根据排列p，构造排列q，使得gcd(pi, qi)>=3, gcd(pi+1, qi+1)>=3
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
void solve(const vector<int> &p) { //q必须是个1到n的排列
    int n = p.size();
    vector<int> q(n);
    for (int i = 0; i < n; i++) {  //令pq的和为n+1，这样能保证都有解
        q[i] = n + 1 - p[i];
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << q[i];
    }cout << "\n";
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        solve(nums);
    }
    return 0;
}