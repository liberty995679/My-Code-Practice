//快速排序
//在这里，A是表示一副牌的数组，并且根据数字执行比较操作。
//您的程序还应报告给定输入（实例）的输出的稳定性。
//这里，“输出的稳定性”意味着具有相同值的牌在输出中的顺序与它们在输入（实例）中的顺序相同。
//输入
//第一行包含一个整数n，表示牌的数量。
//以下行中给出了n张牌。每张牌在一行中给出，由一个字符和一个整数对表示，两者之间用一个空格分隔。
//输出
//在第一行中，以与输入相同的方式打印此输出的稳定性（"稳定"或"不稳定"）。
//在接下来的行中，以与输入相同的方式打印排列好的牌。
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

int Partition(vector<pair<char, int>> &a, int p, int r) {
	auto x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j].second <= x.second) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

void quicksort(vector<pair<char, int>> &a, int p, int r) {
	if (p < r) {
		int q = Partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<pair<char, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	 // 用稳定排序得到"标准答案"
    vector<pair<char, int>> stable_sorted = arr;
    stable_sort(stable_sorted.begin(), stable_sorted.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
	 return a.second < b.second; });
	quicksort(arr, 0, n - 1);
	if (stable_sorted == arr) {
		cout << "Stable" << enl;
	} else {
		cout << "Not stable" << enl;
	}
	bool flag = false;
	for (auto it: arr) {
		cout << it.first << ' ' << it.second << enl;
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