//输入数组b，判断是否存在数组a，满足b[i]=a[i],b[n+1]=a1+...+an,b[n+2]=x,否则输出-1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
void solve(const vector<ll> &b) {
    int N = b.size();
    ll b_sum = 0;
    for (ll i : b) {
        b_sum += i;
    }
    ll a_sum = b[N - 1]; //最大的数
    ll x1 = b_sum - 2 * a_sum;
    for (int i = 0; i < N; i++) {
        if (b[i] == x1) {   //找到x可能的值，验证剩余数的和是否等于asum
            ll time_sum = 0;
            for (int j = 0; j < N; j++) {
                if (j != i && j != N - 1) {
                    time_sum += b[j];
                }
            }if (time_sum == a_sum) {
                bool first = true;
                for (int j = 0; j < N; j++) {
                    if (j == i || j == N - 1) continue;
                    if (!first) cout << ' ';
                    cout << b[j];
                    first = false;
                }cout << endl;
                return;
            }
        }
    }
    ll a_sum1 = b[N - 2];  //次大的数
    ll x2 = b_sum - 2 * a_sum1;
    for (int i = 0; i < N; i++) {
        if (b[i] == x2) {   //找到x可能的值，验证，剩余数的和是否等于asum
            ll time_sum = 0;
            for (int j = 0; j < N; j++) {
                if (j != i && j != N - 2) {
                    time_sum += b[j];
                }
            }if (time_sum == a_sum1) {
                bool first = true;
                for (int j = 0; j < N; j++) {
                    if (j == i || j == N - 2) continue;
                    if (!first) cout << ' ';
                    cout << b[j];
                    first = false;
                }cout << endl;
                return;
            }
        }
    }
    cout << "-1\n";
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
        vector<ll> b(n + 2);
        for (int i = 0; i < n + 2; i++) cin >> b[i];
        sort(b.begin(), b.end());
        solve(b);
    }
    return 0;
}