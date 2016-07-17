class Solution {
public:
void dfs(vector<vector<int>> &res, vector<int>& pre, vector<int>&nums, int k){
    if (k>=nums.size()) return;
    for (int i=k;i<nums.size();i++){
        if (nums[i]!=nums[i-1] || i==k){
            pre.push_back(nums[i]);
            res.push_back(pre);   // for empty set;
            dfs(res,pre,nums,i+1);
            pre.pop_back();
        }
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> pre;
    res.push_back(pre);   // for empty set;
    dfs(res,pre,nums,0);
    return res;
}
};

/*class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> sss={v};

        int section=1; int ending=1;
        int i=0, j=0;

        sort(nums.begin(),nums.end());
        while (1) {
            for (;j<ending;j++) {
                sss.push_back(sss[j]);
                sss.back().push_back(nums[i]);
            }//copy the section and add the current number
            if ((++i)==nums.size()) break;
            else {
                ending+=section;
                if (nums[i]!=nums[i-1]) {section=ending; j=0;}
            }
        }
        return sss;
    }
};