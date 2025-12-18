#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
};

TreeNode* CreateTree(char arr[], int* pi)
{
    char val = arr[(*pi)++];
    if (val == '\0' || val == '#')
        return NULL;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = val;
    root->left = CreateTree(arr, pi);
    root->right = CreateTree(arr, pi);
    return root;
}

void PrevOrder(TreeNode* root)
{
    if (NULL == root)
        return;
    PrevOrder(root->left);
    printf("%c ", root->val);
    PrevOrder(root->right);
}
int main()
{
    char arr[100];
    scanf("%s", arr);
    int i = 0;
    TreeNode* root = CreateTree(arr, &i);
    PrevOrder(root);
    return 0;
}