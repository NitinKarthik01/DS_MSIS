#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include<stdint.h>

typedef struct _tree_node_ TreeNode;
typedef struct _bst_ BST;

struct _tree_node_
{
    int32_t key;
    TreeNode *left;
    TreeNode *right;
};

struct _bst_
{
    TreeNode *root;
    uint32_t mass;
};

BST bst_new();
BST * best_add(BST *tree, int32_t key);
uint32_t bst_find(int32_t key, BST *tree);
uint32_t bst_mass(BST *tree);
uint32_t bst_height(BST *tree);
BST * bst_traversal_inorder_recursive (BST * tree);
BST * bst_traversal_preorder_recursive (BST * tree);
BST * bst_traversal_postorder_recursive (BST * tree);

#endif // BST_H_INCLUDED
