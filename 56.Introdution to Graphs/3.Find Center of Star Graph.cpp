//找中心节点
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> arr(n + 2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                arr[edges[i][j]]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n + 2; i++) {
            if (arr[i] == n) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};