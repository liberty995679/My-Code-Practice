//当n=1,A,当n=2，ABA，当n=3，ABACABA
#include <iostream>
#include <string>

using namespace std;

string solve(int n) {
    if (n == 1) return "A";
    string s = solve(n - 1);
    return s + string(1, n - 1 + 'A') + s;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}