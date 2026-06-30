//磨牙齿
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solve(cnost vector<int> &a,const vector<int> &b, int x, int r) {
    int l = 0;
    while (l < r) {
        int mid 
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> u(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> d[i];
    }
    int right = *max_element(u.begin(), u.end()) + *max_element(d.begin(), d.end());

    return 0;
}