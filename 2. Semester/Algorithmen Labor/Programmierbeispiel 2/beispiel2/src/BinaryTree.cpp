#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <set>
#include <stack>
#include <string>

#include "BinaryTree.h"

using namespace std;

int BinaryTree::height(Node *root)
{
    if (root == nullptr)
        return -1;
    return 1 + max(height(root->left), height(root->right));
}

void BinaryTree::checkAVL(Node *root, bool &isAVL)
{
    if (root == nullptr)
        return;

    int balanceFactor = height(root->right) - height(root->left);

    cout << "bal(" << root->data << ") = " << balanceFactor;
    if (balanceFactor > 1 || balanceFactor < -1)
    {
        cout << " (AVL violation!)";
        isAVL = false;
    }
    cout << endl;

    checkAVL(root->left, isAVL);
    checkAVL(root->right, isAVL);
}

void BinaryTree::printStatistics(Node *root)
{
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int sum = 0;
    int count = 0;

    // Traverse the tree to find min, max, and sum
    // You can use any traversal technique (preorder, inorder, postorder)
    // Here, inorder traversal is used
    stack<Node *> s;
    Node *current = root;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();

        minVal = min(minVal, current->data);
        maxVal = max(maxVal, current->data);
        sum += current->data;
        count++;

        current = current->right;
    }

    // Calculate average
    double avg = static_cast<double>(sum) / count;

    // Print statistics
    cout << "min: " << minVal << ", max: " << maxVal << ", avg: " << avg << endl;
}

Node *BinaryTree::insertNode(Node *root, int data)
{
    if (root == nullptr)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

string BinaryTree::searchValue(Node* root, int key) {
    // Basisfall: Wenn der Baum leer ist oder das gesuchte Element nicht gefunden wird
    if (root == nullptr) {
        return to_string(key) + " not found!";
    }
    // Wenn der gesuchte Wert gefunden wird
    if (root->data == key) {
        return to_string(key) + " found";
    }
    // Wenn der Wert kleiner ist als die Wurzel, suche im linken Teilbaum
    if (key < root->data) {
        string result = searchValue(root->left, key);
        // Wenn der Wert gefunden wurde, füge die Wurzel zu dem Ergebnis hinzu
        if (result != to_string(key) + " not found!") {
            return result + " " + to_string(root->data);
        }
    }
    // Wenn der Wert größer ist als die Wurzel, suche im rechten Teilbaum
    else {
        string result = searchValue(root->right, key);
        // Wenn der Wert gefunden wurde, füge die Wurzel zu dem Ergebnis hinzu
        if (result != to_string(key) + " not found!") {
            return result + " " + to_string(root->data);
        }
    }
    // Wenn der Wert nicht gefunden wurde
    return to_string(key) + " not found!";
}

/*bool BinaryTree::isIdentical(Node* treeRoot, Node* subRoot) {
        if (treeRoot == nullptr && subRoot == nullptr) {
            return true;
        }
        if (treeRoot == nullptr || subRoot == nullptr) {
            return false;
        }
        return (treeRoot->data == subRoot->data) &&
               isIdentical(treeRoot->left, subRoot->left) &&
               isIdentical(treeRoot->right, subRoot->right);
    }

bool BinaryTree::searchSubtree(Node* treeRoot, Node* subRoot) {
        if (treeRoot == nullptr) {
            return false;
        }
        if (treeRoot == subRoot) {
            return isIdentical(treeRoot, subRoot);
        }
        return searchSubtree(treeRoot->left, subRoot) || searchSubtree(treeRoot->right, subRoot);
    }
*/
