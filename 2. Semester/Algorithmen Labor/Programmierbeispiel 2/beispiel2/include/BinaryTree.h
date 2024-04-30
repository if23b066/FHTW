#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};


class BinaryTree
{
public:
    Node* root = nullptr;
    int height(Node *root);
    void checkAVL(Node *root, bool &isAVL);
    void printStatistics(Node *root);
    Node *insertNode(Node *root, int data);
    string searchValue(Node* root, int key);
    //bool searchSubtree(Node* treeRoot, Node* subRoot);

private:
    //bool isIdentical(Node* treeRoot, Node* subRoot);
};

#endif // BINARYTREE_H
