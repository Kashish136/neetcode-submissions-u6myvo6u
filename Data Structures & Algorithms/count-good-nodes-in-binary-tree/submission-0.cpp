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
     int count = 0;
    TreeNode* start;

    void preorder(TreeNode* root){

        if(root == NULL) return;

        if(isvalid(start, root))
            count++;

        preorder(root->left);
        preorder(root->right);
    }

    bool isvalid(TreeNode* root, TreeNode* node){

        if(root == NULL) return false;

        if(root == node) return true;

        if(root->val > node->val)
            return false;

        return isvalid(root->left, node) || isvalid(root->right, node);
    }

    int goodNodes(TreeNode* root) {

        start = root;
        preorder(root);

        return count;
    }
};
