#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode* cur = root;

        while (cur || !stack.empty()) {
            if (cur) {
                res.push_back(cur->val);
                stack.push(cur->right);
                cur = cur->left;
            } else {
                cur = stack.top();
                stack.pop();
            }
        }
        
        return res;
    }
};

// Runtime1: 0ms, beats 100%
// Memory1: 10.20MB, beats 39.38%

// Runtime2: 0ms, beats 100%
// Memory2: 10.02MB, beats 78.24%

// Runtime3: 0ms, beats 100%
// Memory3: 10.01MB, beats 78.24%