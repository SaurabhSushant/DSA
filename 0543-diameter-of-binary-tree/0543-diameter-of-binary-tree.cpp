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
    int height(TreeNode* node){
        if(node==NULL)
        return 0;

        int m=height(node->left);
        int n=height(node->right);
        int s=max(m,n) +1; //1 for including root node in height
        return s;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //this is O(n2 solution)
        //in skew trees the solution can be only in left subtree or teh right subtree
        if(root==NULL)
        return 0;
       //jada nahi sochne ka.ya to left subtree me hi dimatere nikal jaega ya right subtree me ya dono me sum krna hoga.aur fir teeno me jo max hoga wahi ans hojaega. 
        int l=diameterOfBinaryTree(root->left);   //ye to bas traversak ke liye hai,baaki distance to calculate height wale function call se hora hai. 
         int r=diameterOfBinaryTree(root->right);
         int p=height(root->left)+height(root->right); //idk why in this question they dont include no of nodes in path but one less so dont include + 1 here.now i know.because 1 is included two timws in right and left subtrees whereas only one time it must be included.its really confusing so just try diffeent option whichever runs the test cases.

         int m=max(l,max(r,p));
         return m;


        
    }
};