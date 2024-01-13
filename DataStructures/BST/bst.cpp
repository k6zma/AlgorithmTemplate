#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node* root = nullptr;

    Node* insert(Node* node, int key) {
        if (node == nullptr) {

            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        return node;
    }

    Node* min(Node* x) {
        if (x->left == nullptr) {
            return x;
        }

        return min(x->left);
    }

    Node* del(Node* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = del(node->left, key);
        } else if (key > node->key) {
            node->right = del(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                return temp;
            }

            Node* temp = min(node->right);

            node->key = temp->key;
            node->right = del(node->right, temp->key);
        }

        return node;
    }

    Node* merge(Node* node1, Node* node2) {
        if (node2 == nullptr) {
            return node1;
        }

        node1 = insert(node1, node2->key);
        node2 = del(node2, node2->key);

        return merge(node1, node2);
    }

    void inorderTraversal(Node* node, std::vector<int>& temp_vector) {
        if (node != nullptr) {
            inorderTraversal(node->left, temp_vector);
            temp_vector.push_back(node->key);
            inorderTraversal(node->right, temp_vector);
        }
    }

    void preorderTraversal(Node* node, std::vector<int>& temp_vector) {
        if (node != nullptr) {
            temp_vector.push_back(node->key);
            preorderTraversal(node->left, temp_vector);
            preorderTraversal(node->right, temp_vector);
        }
    }

    void postorderTraversal(Node* node, std::vector<int>& temp_vector) {
        if (node != nullptr) {
            postorderTraversal(node->left, temp_vector);
            postorderTraversal(node->right, temp_vector);
            temp_vector.push_back(node->key);
        }
    }
};