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
    bool dfs(TreeNode* root , int curr , int targetSum){
        if(!root) return false ;
        curr = curr + root->val ;
        if(!root->left && !root->right && curr == targetSum) return true ; 
        return dfs(root->left , curr , targetSum) || dfs(root->right , curr , targetSum) ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0 ;
        return dfs(root , 0 , targetSum) ;
    }
};
