#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        inorder(root, output);
        return output;
    }

private:
    void inorder(TreeNode* root, vector<int>& output) {
        if (root == nullptr) {
            return;
        }
        
        inorder(root->left, output);   // Traverse the left subtree
        output.push_back(root->val);   // Visit the root
        inorder(root->right, output);  // Traverse the right subtree
    }
};

// Time Complexity:
// Space Complexity:

// Runtime1: 0ms, beats 100%
// Memory1: 10.08MB, beats 70.03%