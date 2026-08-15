#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == nullptr)
            return result;

        vector<int> left = inorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());

        result.push_back(root->val);

        vector<int> right = inorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());

        return result;
    }
};

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;
    vector<int> result = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";

    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}