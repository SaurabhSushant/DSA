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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

       

        vector<vector<int>>ans;
         if(root==NULL)
        return ans;

        queue<TreeNode*>q;
        q.push(root);  //it will input node not just node->val as its queue<TreeNode*> but it vector below will take int
        bool lefttoright=true;

        while(!q.empty()){
            //first check what is the length of that row i.e the length of the current queue
            int size=q.size();
            //then create  avector to be inserdted in vectors of vectors
            vector<int>v(size);
            //now fill the vector
            for(int i=0;i<size;i++){
                //first store the node then pop it
                TreeNode* node=q.front();
               
                q.pop();

                
                int index=lefttoright?i:size-i-1;

                //now fill teh vector and then fill queue with next nodes
                v[index]=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                


            }
            lefttoright=!lefttoright;
//now push the vector in vector of vectors
ans.push_back(v);

        }
        return ans;
        
    }
};