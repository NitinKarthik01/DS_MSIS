#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "bst.h"


BST bst_new()
{
    BST tree = {NULL, 0};
    return tree;
}

static TreeNode * make_new_node(int32_t key)
{
    TreeNode *tnode = (TreeNode *)malloc(sizeof(TreeNode));
    tnode -> key = key;
    tnode -> left = tnode -> right = NULL;
    return tnode;
}

BST * best_add(BST *tree, int32_t key)
{
    TreeNode *root, *parent;
    root = parent = tree -> root;

    while(root!=NULL && root->key!=key)
    {
        parent = root;
        if(key<root->key)
        {
            root = root->left;
        }
        else if(key>root->key)
        {
            root = root->right;
        }
    }

    if(root==NULL)
    {
        TreeNode *tnode = make_new_node(key);
        if (parent == NULL)
        {
            tree -> root = tnode;
        }
        else if(key < parent -> key)
        {
            parent -> left = tnode;
        }
        else if(key > parent -> key)
        {
            parent -> right = tnode;
        }
        ++ tree->mass;
    }
    return tree;
}

uint32_t bst_find(int32_t key, BST *tree)
{
    TreeNode *root = tree -> root;

    while(root!=NULL)
    {
        if(key<root->key)
        {
            root = root->left;
        }
        else if(key>root->key)
        {
            root = root->right;
        }
        else{
            break;
        }
    }
    return root!=NULL;
}

uint32_t bst_mass(BST *tree)
{
    return tree->mass;
}

static uint32_t _height_(TreeNode *tnode)
{
    uint32_t height;
    uint32_t lheight, rheight;

    if(tnode == NULL)
    {
        height = 0;
    }
    else
    {
        lheight = _height_(tnode -> left);
        rheight = _height_(tnode -> right);

        if(lheight > rheight)
        {
            height = lheight + 1;
        }
        else
        {
            height = rheight + 1;
        }
    }

    return height;
}

uint32_t bst_height(BST *tree)
{
    return _height_(tree->root);
}

static void _inorder_ (TreeNode *tnode)
{
    if(tnode)
    {
        _inorder_(tnode->left);
        printf("%d", &tnode->key);
        _inorder_(tnode->right);
    }
}

BST * bst_traversal_inorder_recursive (BST * tree)
{
    _inorder_(tree -> root);
    return tree;
}

static void _preorder_ (TreeNode *tnode)
{
    if(tnode)
    {
        printf("%d", &tnode->key);
        _preorder_(tnode->left);
        _preorder_(tnode->right);
    }
}

BST * bst_traversal_preorder_recursive (BST * tree)
{
    _preorder_(tree->root);
    return tree;
}

static void _postorder_ (TreeNode *tnode)
{
    if(tnode)
    {
        _postorder_(tnode->left);
        _postorder_(tnode->right);
        printf("%d", &tnode->key);
    }
}

BST * bst_traversal_postorder_recursive (BST * tree)
{
    _postorder_(tree -> root);
    return tree;
}

static TreeNode* find_min(TreeNode *tnode)
{
    if(tnode -> left == NULL)
    {
        return tnode;
    }

    else
    {
        return find_min(tnode -> left);
    }
}

static TreeNode* bst_delete(BST *tree, TreeNode *tnode, int32_t key)
{
    TreeNode *temp;
    if(tnode == NULL)
    {
        return tnode;
    }
    else if(key < tnode -> key)
    {
        tnode -> left = bst_delete(tree, tnode ->  left, key);
    }

    else if(key > tnode -> key)
    {
        tnode -> right = bst_delete(tree, tnode -> right, key);
    }

    else if(tnode -> right && tnode -> left)
    {
        temp = find_min(tnode -> right);
        tnode -> key = temp -> key;
        tnode -> right = bst_delete(tree, tnode -> right, key);
    }

    else
    {
        temp = tnode;
        if(tnode -> left  == NULL)
        {
            tnode = tnode -> right;
        }
        else
        {
            tnode = tnode -> left;
        }
    }
    free(temp);
    -- tree->mass;
    return tnode;

}
