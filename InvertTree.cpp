#include <iostream>
#include <queue>
using namespace std;

// Definition of a Tree Node
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

// Function to invert the binary tree
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Swap left and right
    swap(root->left, root->right);

    // Recursively invert left and right subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Print tree using Level Order Traversal
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

int main() {

    // Creating the tree:
    //
    //         4
    //        / \
    //       2   7
    //      / \ / \
    //     1  3 6  9

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Before inversion: ";
    printTree(root);

    invertTree(root);

    cout << "\nAfter inversion: ";
    printTree(root);

    return 0;
}