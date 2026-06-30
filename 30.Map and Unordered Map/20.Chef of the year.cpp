//来自世界各地的厨师每年都会聚集参加一次国际大会。每位厨师代表某个国家。请注意，一个国家可以由多位厨师代表。
//他们各自向观众展示自己最拿手的菜肴。之后，观众会向一个秘密且安全的邮件服务器发送电子邮件，邮件主题是他们希望选为“年度厨师”的厨师姓名。
//你将获得所有邮件的主题列表。请找出其所属厨师获得最多选票的国家，以及获得最多选票、当选“年度厨师”的厨师。
//注意 1​
//如果有多个国家获得了相同的最高票数，则在这些国家中选择字典序较小的那个作为胜出者。
//同样地，如果有多个厨师获得相同的最高票数，则选择字典序较小的厨师作为“年度厨师”。
//注意 2​
//字符串 A = a₁a₂…aₙ 在以下两种情况下被认为是字典序小于字符串 B = b₁b₂…bₘ 的：
//存在某个索引 i ≤ min{n, m}，使得对于所有 1 ≤ j < i 都有 aⱼ = bⱼ，并且 aᵢ < bᵢ；
//A 是 B 的真前缀，即 n < m 且对于所有 1 ≤ j ≤ n 都有 aⱼ = bⱼ。
//字符串中字符的比较基于它们的 ASCII 码。
//可参考 C 语言中的 strcmp函数，或 C++ 中 string数据结构的 <比较器了解详情。
//输入​
//第一行包含两个空格分隔的整数 N 和 M，分别表示厨师人数和邮件数量。
//接下来的 N 行，每行包含两个空格分隔的字符串，分别表示厨师的姓名和他所代表的国家。
//再接下来的 M 行，每行包含一个字符串，表示一封邮件的主题。
//输出​
//输出两行。
//第一行应输出其所属厨师获得最多选票的国家的名称。
//第二行应输出当选“年度厨师”的厨师的姓名。
#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;
using vi = vector<int>;
const char enl = '\n';

void solve() {
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> country;
	unordered_map<string, string> cook;
	for (int i = 0; i < n; i++) {
		string play, city;
		cin >> play >> city;
		cook[play] = city;
	}
	unordered_map<string, int> a, b; //国家投票和厨师投票
	int mx_a = 0; int mx_b = 0;
	for (int i = 0; i < m; i++) {
		string x;
		cin >> x; //获得投票的人
		string s = cook[x];
		a[s]++;
		b[x]++;
		mx_a = max(mx_a, a[s]);
		mx_b = max(mx_b, b[x]);
	}
	vector<string> ans1, ans2;
	for (auto it: a) {
		if (it.second == mx_a) ans1.push_back(it.first);
	}
	for (auto it: b) {
		if (it.second == mx_b) ans2.push_back(it.first);
	}
	sort(ans1.begin(), ans1.end());
	sort(ans2.begin(), ans2.end());
	cout << ans1[0] << enl;
	cout << ans2[0] << enl;
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