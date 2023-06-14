class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        //True or false
        if(root->val < 2) return root->val;
        //OR
        else if(root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        //AND
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};
