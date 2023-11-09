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
private:
   long long int mod = 1e9 + 7 ;
   long long int total_sum = 0 ;
   long long int ans = 0 , value ;

public:
    long long int find_sum(TreeNode* root){
        if(!root) return 0 ;
        total_sum += root->val ;
        find_sum(root->left) ;
        find_sum(root->right) ;
        return total_sum ;
    }

    long long int dfs(TreeNode* root){
       if(!root) return 0 ;
       int l_sum = dfs(root->left) ;
       int r_sum = dfs(root->right) ;
       value = root->val + l_sum + r_sum ;
       ans = max(ans , value * (total_sum - value));
       return value ;
    }

    int maxProduct(TreeNode* root) {
        total_sum = find_sum(root) ;
        dfs(root) ;
        return ans % mod ;
    }
};