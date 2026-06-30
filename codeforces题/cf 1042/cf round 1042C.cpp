//给定两个大小为 n 的多重集 S 和 T，以及一个正整数 k，你可以对 S 进行任意次（包括零次）以下操作：
//选择 S 中的一个元素 x，删除 S 中一个 x 的出现次数，然后要么将 x 加 k 的结果（x + k）插入 S，要么将 |x − k| 的结果插入 S。
//判断能否通过若干次操作使 S 与 T 相等。两个多重集 S 和 T 相等，当且仅当每个元素在 S 和 T 中出现的次数相同。
//输入格式​
//每个测试包含多个测试用例。第一行包含一个整数 t（1 小于等于 t 小于等于 10 的 4 次方）—— 测试用例数量。接下来是各测试用例的描述。
//每个测试用例的第一行包含两个整数 n 和 k（1 小于等于 n 小于等于 2 乘 10 的 5 次方，1 小于等于 k 小于等于 10 的 9 次方）—— 分别是 S 的大小和常数 k。
//第二行包含 n 个整数 S[1], S[2], ..., S[n]（0 小于等于 S[i] 小于等于 10 的 9 次方）—— S 的元素。
//第三行包含 n 个整数 T[1], T[2], ..., T[n]（0 小于等于 T[i] 小于等于 10 的 9 次方）—— T 的元素。
//保证所有测试用例的 n 之和不超过 2 乘 10 的 5 次方。
//输出格式​
//对于每个测试用例，如果可能使 S 等于 T，输出 "YES"，否则输出 "NO"。
//答案大小写均可，例如 "yEs"、"yes"、"Yes" 和 "YES" 均视为肯定回答。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
	ll n, k; 
	cin >> n >> k;
	vector<ll> s(n), t(n); 
	map<ll, ll> t1;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		ll y1 = x % k;
		ll y2 = k - x % k;
		t1[min(y1, y2)]++;
	}
	map<ll, ll> mp; //存余数
	for (int i = 0; i < n; i++) {
		ll x1 = s[i] % k;
		ll x2 = k - s[i] % k;
		mp[min(x1, x2)]++;
	}
	if (mp == t1) cout << "YES" << enl;  //判断unordered_mao相等直接用等号
	else cout << "NO" << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}