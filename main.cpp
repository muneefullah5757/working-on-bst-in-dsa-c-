#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* Lchild;
    Node* Rchild;

    Node(int value) {
        data = value;
        Lchild = Rchild = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }
    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->Lchild = insert(root->Lchild, value);
        else
            root->Rchild = insert(root->Rchild, value);

        return root;
    }
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->Lchild);
        cout << root->data << " ";
        inorder(root->Rchild);
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->Lchild);
        preorder(root->Rchild);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->Lchild);
        postorder(root->Rchild);
        cout << root->data << " ";
    }
    bool isBST(Node* root) {
        if (!root) return true;
        if (root->Lchild && root->Lchild->data >= root->data)
            return false;
        if (root->Rchild && root->Rchild->data <= root->data)
            return false;

        return isBST(root->Lchild) && isBST(root->Rchild);
    }
};

int main() {
    BST tree;

    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 35);

    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(tree.root);
    cout << endl;

    if (tree.isBST(tree.root))
        cout << "\nThe tree is a valid BST." << endl;
    else
        cout << "\nThe tree is NOT a valid BST." << endl;

    return 0;
}

