//有一个迷宫，上下左右四个方向
//主角通过箭头移动到迷宫外就是获救
//否则就是困在迷宫里
//输出在对所有 ? 方向任意赋值后
//能使“永远困在迷宫里”的起点格子数量的最大可能值。
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>    //把所有逃出迷宫的格子找出来
#include <string>
using namespace std; //剩下的就是答案
using ll = long long;        
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string c[n + 1];
        for (int i = 1; i <= n; i++) cin >> c[i], c[i] = "-" + c[i];
        vector<pair<int , int>> jda[n + 2][m + 2]; //反向邻接图，i,j到i-1,j,则jda[i-1][j]存i,j
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (c[i][j] == 'U') jda[i - 1][j].push_back({i, j});
                if (c[i][j] == 'R') jda[i][j + 1].push_back({i, j});
                if (c[i][j] == 'D') jda[i + 1][j].push_back({i, j});
                if (c[i][j] == 'L') jda[i][j - 1].push_back({i, j});
            }
        }
        int vis[n + 2][m + 2] = {};
        queue<pair<int, int>> q;  //q 一开始存的就是“迷宫外一圈所有格子”作为 BFS 的起点。
        for(int j = 0 ; j <= m+1 ; j++) vis[0][j] = 1 , q.push({0 , j});
        for(int i = 1 ; i <= n+1 ; i++) vis[i][0] = 1 , q.push({i , 0});
        for(int j = 1 ; j <= m+1 ; j++) vis[n+1][j] = 1 , q.push({n+1 , j});
        for(int i = 1 ; i <= n ; i++) vis[i][m+1] = 1 , q.push({i , m+1});
        while(q.size()){  //从“迷宫外面”开始做一次反向 BFS，把所有 一定能逃出迷宫 的格子标记出来。
            auto [i , j] = q.front();
            q.pop();
            for(auto [a , b] : jda[i][j]){
                if(vis[a][b] == 0){
                    vis[a][b] = 1;
                    q.push({a , b});
                }
            }
        }
        for(int i = 1 ; i <= n ; i++){  //如果一个 ? 的四个邻居（上、右、下、左）都已经是可到达的（vis = 1），
            for(int j = 1 ; j <= m ; j++){ //  那么这个 ? 也会被标记为可到达vis[i][j] = 1
                if(c[i][j] == '?' &&
                vis[i-1][j] && vis[i][j+1] && vis[i+1][j] && vis[i][j-1]) vis[i][j] = 1;
            }
        }
        int ans = n * m;  //统计还没有被访问到的格子数量
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(vis[i][j] == 1) ans -= 1;  //从外部可到达就减一
            }
        }  //总数去除所有能到达的格子数就是答案
        cout << ans << endl;
    }
    return 0;
}