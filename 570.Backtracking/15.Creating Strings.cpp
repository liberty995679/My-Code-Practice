//输入一个字符串
//生成所有该字符串可以创建的字符串
//输出k个
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> arr;
string s;
int n = 0;

void solve() {
   cin >> s;
   n = s.size();
   sort(s.begin(), s.end());
   do{
      arr.push_back(s);
   } while (next_permutation(s.begin(), s.end()));
   cout << arr.size() << endl;
   for (int i = 0; i < arr.size(); i++) {
      cout << arr[i] << endl;
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}