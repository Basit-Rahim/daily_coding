#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root) {
    if (root == nullptr)
        return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return max(leftH, rightH) + 1;
}

int main() {
    /*
        Example tree:
                1
               / \
              2   3
             / \
            4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Height = " << height(root) << endl;

    return 0;
}
