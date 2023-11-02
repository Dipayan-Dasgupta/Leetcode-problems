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
    // int dfs(TreeNode* root){
    //     if(root == NULL) return 0;
    //     int left_height = dfs(root->left);
    //     int right_height = dfs(root->right);
    //     return min(left_height , right_height) + 1;
    // }
    int minDepth(TreeNode* root) {
       if(root == NULL) return 0;
        // int left = INT_MAX, right = INT_MAX , ans;
        // if(root->left){
        //     left = dfs(root->left);
        // }
        // if(root->right){
        //     right = dfs(root->right);
        // }
        // //cout<<left;
        // if(root->left == NULL && root->right == NULL) ans = 1;
        // else ans = min(left,right) + 1 ;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(root->left == NULL) return 1 + right;
        if(root->right == NULL) return 1 + left; 
        return min(left , right) + 1 ;
    }
};