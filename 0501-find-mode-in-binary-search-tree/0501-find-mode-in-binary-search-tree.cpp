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
   void preorder(TreeNode* root, unordered_map<int,int>& mp, int& maxFreq){
        if(root == NULL)
            return;
        
    
        mp[root->val]++;
        maxFreq = max(maxFreq, mp[root->val]);
        
    
        preorder(root->left, mp, maxFreq);
        
        
        preorder(root->right, mp, maxFreq);
    }

    vector<int> findMode(TreeNode* root) {
      
        unordered_map<int,int> mp;
        int maxFreq = 0;
        
        preorder(root, mp, maxFreq);
        
        vector<int> ans;
        
        for(auto it : mp){
            if(it.second == maxFreq)
                ans.push_back(it.first);
        }
        return ans;

        
    }
};