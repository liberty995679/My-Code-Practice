//倒水问题，输入水壶A的容量，水壶B的容量，目标是B达到水量C
//一共有六种操作
//1.将水壶a装满水，2.将水壶b装满水
//3.将水壶a倒空，4.将水壶b倒空
//5.将a倒入b直到a空或者b满
//6.将b倒入a直到b空或者a满
//fill B
//pour B A
//empty A
//pour B A
//fill B
//pour B A
//最后一行输出success
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, C;
struct  water
{
   int a, b;
   vector<string> steps; //从初始到这个状态的所有操作
};

void bfs() {
   queue<water> que;
   set<pair<int, int>> vis; //记录访问过的状态
   water start;
   start.a = 0; start.b = 0; //初始化为0
   que.push(start);
   vis.insert({0, 0});
   bool found = false;
   while (!que.empty()) {
      water cur = que.front();
      que.pop();
      if (cur.b == C) {
         for (int i = 0; i < cur.steps.size(); i++) {
            cout << cur.steps[i] << endl;
         }
         cout << "success" << endl;
         found = true;
         break;
      }
      {  //操作1
         water next;
         next.a = A;
         next.b = cur.b;  //a装满，b不变
         next.steps = cur.steps; //复制之前的操作
         next.steps.push_back("fill A"); //加上这次操作
         if (vis.find({next.a, next.b}) == vis.end()) {
            vis.insert({next.a, next.b});
            que.push(next);
         }
      }
      {  //操作2
         water next;
         next.b = B;
         next.a = cur.a;  //b装满，a不变
         next.steps = cur.steps; //复制之前的操作
         next.steps.push_back("fill B"); //加上这次操作
         if (vis.find({next.a, next.b}) == vis.end()) {
            vis.insert({next.a, next.b});
            que.push(next);
         }
      }
      {  //操作3
         water next;
         next.a = 0;
         next.b = cur.b;  //a为0，b不变
         next.steps = cur.steps; //复制之前的操作
         next.steps.push_back("empty A"); //加上这次操作
         if (vis.find({next.a, next.b}) == vis.end()) {
            vis.insert({next.a, next.b});
            que.push(next);
         }
      }
      {  //操作4
         water next;
         next.b = 0;
         next.a = cur.a;  //b为0，a不变
         next.steps = cur.steps; //复制之前的操作
         next.steps.push_back("empty B"); //加上这次操作
         if (vis.find({next.a, next.b}) == vis.end()) {
            vis.insert({next.a, next.b});
            que.push(next);
         }
      }
      {  //操作5
         water next;
         next.b = min(cur.a + cur.b, B);
         next.a = cur.a + cur.b - next.b;
         next.steps = cur.steps; //复制之前的操作
         next.steps.push_back("pour A B"); //加上这次操作
         if (vis.find({next.a, next.b}) == vis.end()) {
            vis.insert({next.a, next.b});
            que.push(next);
         }
      }
      {  //操作6
         water next;
         next.a = min(cur.a + cur.b, A);
         next.b = cur.a + cur.b - next.a;
         next.steps = cur.steps; //复制之前的操作
         next.steps.push_back("pour B A"); //加上这次操作
         if (vis.find({next.a, next.b}) == vis.end()) {
            vis.insert({next.a, next.b});
            que.push(next);
         }
      }
   }
}

void solve() {
   while (cin >> A >> B >> C) {
      bfs();
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