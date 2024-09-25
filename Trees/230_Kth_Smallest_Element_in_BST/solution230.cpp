#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while (!stk.empty() || curr) {
            // Reach the leftmost node of the current node
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            
            // Process the top node from the stack
            curr = stk.top();
            stk.pop();
            
            // Decrement k, and if k reaches 0, we've found our answer
            k--;
            if (k == 0) {
                return curr->val;
            }
            
            // Move to the right subtree
            curr = curr->right;
        }
        
        return -1; // This line is just a safeguard; logically it should never be reached
    }
};
