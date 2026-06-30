//给你一串数字，任务就是把它们按从小到大的顺序排好。
//输入格式
//第一行是一个整数 N，表示数字的个数。
//接下来 
//N 行，每行一个整数，代表列表中的元素。
//输出格式
//输出 N 行，每行一个整数，按非递减顺序排列。
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
#include <bitset>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (auto i:arr) {
		cout << i << enl;
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