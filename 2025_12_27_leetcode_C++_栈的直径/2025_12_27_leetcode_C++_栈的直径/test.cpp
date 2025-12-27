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

int deep(TreeNode* root)
{
    if (nullptr == root)
        return 0;
    int d1 = deep(root->left) + 1;
    int d2 = deep(root->right) + 1;
    if (d1 > d2)
        return d1;
    else
        return d2;
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (nullptr == root)
            return 0;

        int deep1 = diameterOfBinaryTree(root->left);
        int deep2 = diameterOfBinaryTree(root->right);
        int deep3 = deep(root->left) + deep(root->right);
        if (deep3 > deep1 && deep3 > deep2)
            return deep3;
        if (deep1 > deep3 && deep1 > deep2)
            return deep1;
        if (deep2 > deep3 && deep2 > deep1)
            return deep2;
        return deep3;
    }
};

//leetcode±ê×¼´ð°¸


class Solution {
public:

    int ans;
    int deepth(TreeNode* root)
    {
        if (nullptr == root)
            return 0;
        int L = deepth(root->left);
        int R = deepth(root->right);
        ans = max(ans, L + R);
        return max(L, R) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        deepth(root);
        return ans;
    }
};