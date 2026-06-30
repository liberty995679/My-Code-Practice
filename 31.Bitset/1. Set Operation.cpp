//给你 N个集合，第 i个集合记为 S(i)，它包含 C(i)个元素（这里的“集合”与数学中定义的“集合”不完全相同，一个集合中可能包含两个相同的元素）。每个元素用一个 1 到 10000 之间的正整数表示。
//现在有一些查询需要回答。每个查询是判断两个给定的元素 i和 j是否至少同时属于一个集合（即是否存在一个编号 k（1≤k≤N），
//使得元素 i属于 S(k)且元素 j也属于 S(k)）。
//输入​
//输入的第一行包含一个整数 N（1≤N≤1000），表示集合的数量。
//接下来 N行，每行开头是一个数 C(i)（1≤C(i)≤10000），后面跟着 C(i)个数，
//用空格分隔，表示这个集合中的元素（这 C(i)个数彼此之间可以相同）。
//第 N+2行包含一个整数 Q（1≤Q≤200000），表示查询的数量。
//接下来 Q行，每行包含一对数 i和 j（1≤i,j≤10000，且 i可以等于 j），表示需要判断的两个元素。
//输出​
//对于每个查询，在一行中输出：如果存在这样的 k，则输出 "Yes"；否则输出 "No"。
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
const char enl = '\n';

void solve() {
	int n; cin >> n;
	vector<set<int> > arr(n);
	map<int, vector<int> > pos;
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		while (m--) {
			int x; cin >> x;
			pos[x].push_back(i);
		}
	}
	int q; cin >> q;
	while (q--) {   //两个集合是否有交集 优先想排序和双指针
		int a, b;
		cin >> a >> b;
		bool flag = false;
		vector<int> a_nums = pos[a];
		vector<int> b_nums = pos[b];
		int i = 0; int j = 0;
		while (i < a_nums.size() && j < b_nums.size()) {
			if (a_nums[i] == b_nums[j]) {
				flag = true;
				break;
			}
			if (a_nums[i] < b_nums[j]) {
				i++;
			} else {
				j++;
			}
		}
		if (flag) cout << "Yes" << enl;
		else cout << "No" << enl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}