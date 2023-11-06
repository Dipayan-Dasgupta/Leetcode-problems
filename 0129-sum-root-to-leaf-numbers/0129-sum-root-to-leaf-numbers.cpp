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
      int sum = 0 ; 
      //vector<int> ans ;
      int ans = 0 ;
public:
    void dfs(TreeNode* root){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL){
            sum = (sum * 10) + root->val ;
            ans = ans + sum ;
            sum = (sum - root->val) / 10 ;
            cout<<ans<<" ";
            return ;
        }
        else{
            sum = (sum * 10) + root->val;
        }
        dfs(root->left);
        dfs(root->right);
        sum = (sum - root->val)/ 10 ;
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0 ;
        //int sum = 0 ;
        dfs(root);
        return ans;
    }
};