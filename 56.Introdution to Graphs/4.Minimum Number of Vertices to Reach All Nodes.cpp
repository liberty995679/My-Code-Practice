//找度为0的节点
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int cnt0 = 0;
        vector<int> arr(n);
        for (int i = 0; i < edges.size(); i++) {
            arr[edges[i][1]]++;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) res.push_back(i);
        }
        return res;
    }
};