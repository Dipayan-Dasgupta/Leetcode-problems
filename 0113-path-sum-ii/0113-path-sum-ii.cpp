/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans ;
    vector<int> path ;
    void dfs(TreeNode* root , int targetSum){
        if(!root) return ;
        if(targetSum == root->val && !root->left && !root->right){
            path.push_back(root->val) ;
            ans.push_back(path) ;
            path.pop_back() ;
            return ;
        }
        path.push_back(root->val) ;
        dfs(root->left , targetSum - root->val) ;
        dfs(root->right , targetSum - root->val) ;
        path.pop_back() ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root , targetSum) ;
        return ans ;
    }
};