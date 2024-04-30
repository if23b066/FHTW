#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>

#include "BinaryTree.h"

using namespace std;

bool isIdentical(Node* treeRoot, Node* subRoot) {
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

bool searchSubtree(Node* treeRoot, Node* subRoot) {
        if (treeRoot == nullptr) {
            return false;
        }
        if (treeRoot == subRoot) {
            return isIdentical(treeRoot, subRoot);
        }
        return searchSubtree(treeRoot->left, subRoot) || searchSubtree(treeRoot->right, subRoot);
}

int main(int argc, char *argv[])
{
    BinaryTree tree;

    // Check if a filename is provided as a command-line argument
    if (argc < 2){
        cerr << "Not enough arguments!";
        return 1;
    }

    if (argc > 3){
        cerr << "To many arguments!";
        return 1;
    }

    // Open the file
    ifstream bt_file(argv[1]);

    // Check if the file is opened successfully
    if (!bt_file.is_open())
    {
        cerr << "Failed to open the file.\n";
        return 1;
    }

    // Initialize a set to keep track of unique values
    set<int> seenValues_bt;

    // Read the values from the file to count unique values
    int value_bt;
    int uniqueCount_bt = 0;
    while (bt_file >> value_bt)
    {
        if (seenValues_bt.insert(value_bt).second)
        {
            ++uniqueCount_bt;
        }
    }

    // Reset file position
    bt_file.clear();
    bt_file.seekg(0, ios::beg);

    // Initialize an array to store the unique values
    int binTreeVals[uniqueCount_bt];

    // Read the values from the file and populate the array
    int index_bt = 0;
    while (bt_file >> value_bt)
    {
        if (seenValues_bt.erase(value_bt) > 0)
        {
            binTreeVals[index_bt++] = value_bt;
        }
    }

    // Close the file
    bt_file.close();

    int n = sizeof(binTreeVals) / sizeof(binTreeVals[0]);

    for (int i = 0; i < n; i++)
    {
        tree.root = tree.insertNode(tree.root, binTreeVals[i]);
    }

    if (argc == 2){
        bool isAVL;

        tree.checkAVL(tree.root, isAVL);

        if (isAVL)
        {
            cout << "AVL: yes" << endl;
        }
        else
        {
            cout << "AVL: no" << endl;
        }
        tree.printStatistics(tree.root);
    }else{
        ifstream search_file(argv[2]);
        if (!search_file.is_open()) {
            cerr << "Error opening file: " << argv[2] << endl;
            return 1;
        }
        int lineCount = 0;
        string line;
        while (getline(search_file, line)) {
            lineCount++;
        }

        search_file.clear(); // Clear any error flags
        search_file.seekg(0, ios::beg);

        cout<<lineCount<<endl;
        if(lineCount==1){

            int searchKey;
            if (!(search_file >> searchKey)) {
                cout<<lineCount<<endl;
                cerr << "Error reading search key from file: " << argv[2] << endl;
                return 1;
            }
            string result = tree.searchValue(tree.root, searchKey);
            cout << result << endl;
            search_file.close();
        }else{
            BinaryTree subtree;

            // Read the values from the file to count unique values
            int value_st;
            int uniqueCount_st = 0;
            set<int> seenValues_st;
            while (search_file >> value_st)
            {
                if (seenValues_st.insert(value_st).second)
                {
                    ++uniqueCount_st;
                }
            }

            // Reset file position
            search_file.clear();
            search_file.seekg(0, ios::beg);

            int subTreeVals[uniqueCount_st];

            int index_st = 0;
            while (search_file >> value_st)
            {
                if (seenValues_st.erase(value_st) > 0)
                {
                    subTreeVals[index_st++] = value_st;
                }
            }

            search_file.close();

            int s = sizeof(subTreeVals) / sizeof(subTreeVals[0]);

            for (int i = 0; i < s; i++)
            {
                subtree.root = subtree.insertNode(subtree.root, subTreeVals[i]);
            }

            if(searchSubtree(tree.root, subtree.root)){
                bool isAVL;
                cout <<subtree.root->data<<endl;
                subtree.checkAVL(subtree.root, isAVL);
                cout<<searchSubtree(tree.root, subtree.root)<<endl;
                cout<<"Subtree found"<<endl;
            }else{
                bool isAVL;
                cout <<subtree.root->data<<endl;
                subtree.checkAVL(subtree.root, isAVL);
                cout<<searchSubtree(tree.root, subtree.root)<<endl;
                cout<<"Subtree not found!"<<endl;
            }
        }
    }

    return 0;
}
