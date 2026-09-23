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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        auto check=[&](auto&& self,TreeNode* left,TreeNode* right)->bool{
            if(left==nullptr&&right==nullptr) return true;
            if(left==nullptr||right==nullptr) return false;
            if(left->val!=right->val) return false;
            return self(self,left->right,right->left)&&self(self,left->left,right->right);
        };
        return check(check,root->left,root->right);
    }
};
