#include <stack>

using namespace std;

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
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            
            curr = stk.top();
            stk.pop();
            
            k--;
            if (k == 0) {
                return curr->val;
            }
            
            curr = curr->right;
        }
        
        return -1;
    }
};

// Runtime1: 11ms, beats 72.91%
// Memory1: 22.99MB, beats 38.94%

// Runtime2: 7ms, beats 93.98%
// Memory2: 22.90MB, beats 38.94%

// Runtime3: 11ms, beats 72.91%
// Memory3: 22.78MB, beats 89.16%