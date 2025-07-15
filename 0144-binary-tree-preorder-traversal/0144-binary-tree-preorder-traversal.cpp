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
    vector<int> preorderTraversal(TreeNode* root) {
        //iterative solution using stack
        //see the algorithm in copy to understand better
        //O(n) tc as it traverses entire row once and O(n) space beacuse of vector
        vector<int>preorder;
        //edge cases
        if(root==NULL)
        return preorder;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            //root ko kaat ke uske preorder vector me add karo
            root=st.top();
            preorder.push_back(root->val);
            st.pop();

            //fir us root ke right aur left wale ko stack me add karo
            if(root->right!=NULL)
            st.push(root->right);
            if(root->left!=NULL)
            st.push(root->left);
        }
        return preorder;
        
    }
};