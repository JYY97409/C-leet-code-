int TreeHigh(TreeNode* root)
{
    if (nullptr == root)
        return 0;
    int ret1 = TreeHigh(root->left) + 1;
    int ret2 = TreeHigh(root->right) + 1;
    return ret1 > ret2 ? ret1 : ret2;
}
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        if (nullptr == root)
            return true;
        if (nullptr == root->left && nullptr == root->right)
            return true;
        if (std::abs(TreeHigh(root->left) - TreeHigh(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};