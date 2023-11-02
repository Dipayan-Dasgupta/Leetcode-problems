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
    int ans = 0 ;
public:
    pair<int , int> dfs(TreeNode* root){
        if(!root) return {0 , 0} ;
        pair<int , int> l = dfs(root->left) ;
        pair<int , int> r = dfs(root->right) ;
        int cnt = l.first + r.first + 1 ;
        int avg = (l.second + r.second + root->val) / cnt ;
        if(root->val == avg){
            ans = ans + 1 ;
        }
        return {cnt , l.second + r.second + root->val} ;
    }
    int averageOfSubtree(TreeNode* root) {
        if(!(root->left) && !(root->right)) return 1 ;
        dfs(root) ;
        return ans ;
    }
};
