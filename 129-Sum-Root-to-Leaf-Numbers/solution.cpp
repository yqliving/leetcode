/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:
    void dfs(TreeNode* node, int &res, int cur)   //如果是 int res，返回0，加上& 结果正确
    {
        if(!node) return; //if it is an empty node, return
        cur = cur*10+node->val; // update the current value from root to the current node 
        if(!node->left && !node->right)
        {  //if it is a leaf node
            res +=cur; //update the result
            return;
        }
        dfs(node->left,  res, cur); // recursively process the left subtree
        dfs(node->right, res, cur);// recursively process the right subtree
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int res=0;
        dfs(root, res, 0);
        return res;
    }
    
};