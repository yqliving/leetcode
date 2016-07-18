class Solution {
    public:
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> temp;
    dfs(res, temp, 1, k, n);
    return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& temp, int start, int k, int n) {
        if (k == 0 && n == 0) {
            res.push_back(temp);
            return;
        }
        if (start > 9 || start > n) return;
        temp.push_back(start);
        dfs (res, temp, start + 1, k - 1, n - start);
        temp.pop_back();
        dfs (res, temp, start + 1, k, n);
    }
};


