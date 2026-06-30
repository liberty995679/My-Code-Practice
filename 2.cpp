#include<bits/stdc++.h>
#include <string>
using namespace std;

void solve() {
    string s,t;
    cin >> s;
    cin >> t;
    s = s + '.';
    t = t + '.';
    vector<string> a1, a2;
    string x = "";
    for (int i=0;i<s.size();i++) {
        if (s[i]!='.') {
            x += s[i];
        } else {
            a1.push_back(x);
            x = "";
        }
    }
    x = "";
    for (int i=0;i<t.size();i++) {
        if (t[i]!='.') {
            x += t[i];
        } else {
            a2.push_back(x);
            x = "";
        }
    }
    int n = s.size();
    vector<int> b1, b2;
    for (string i : a1) {
        int x = stoi(i);
        b1.push_back(x);
    }
    for (string i : a2) {
        int x = stoi(i);
        b2.push_back(x);
    }
    for (int i = 0; i < b1.size(); i++) {
        if (b1[i] > b2[i]) {
            cout << "A" << endl;
            return;
        }
        if (b2[i] > b1[i]) {
            cout << "B" << endl;
            return;
        }
    }
    cout << "Equal" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}