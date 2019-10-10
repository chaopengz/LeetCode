//
// Created by cpz on 2019-09-05.
//


class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return nullptr;

        Node *last_node = nullptr;

        inOrder(root, last_node);

        Node *first_node = last_node;
        while (first_node && first_node->left)
            first_node = first_node->left;
        first_node->left = last_node;
        last_node->right = first_node;

        return first_node;
    }

    //mid-travel
    void inOrder(Node *root, Node *&last_node) {
        if (!root)
            return;

        //left
        if (root->left)
            inOrder(root->left, last_node);

        //current
        if (last_node)
            last_node->right = root;
        root->left = last_node;

        last_node = root;

        //right
        if (root->right)
            inOrder(root->right, last_node);

    }
};