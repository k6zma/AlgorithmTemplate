#include <vector>

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int value) : key(value), height(1), left(nullptr), right(nullptr) {}
};

struct AVLTree {
    Node* root = nullptr;

    int calcHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int calcBalanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return calcHeight(node->left) - calcHeight(node->right);
    }

    void fixHeightNode(Node* node) {
        if (node == nullptr) {
            return;
        }

        int current_subtree_height = std::max(calcHeight(node->left), calcHeight(node->right)) + 1;
        node->height = current_subtree_height;
    }

    Node* smallRightRotate(Node* a) {
        Node* b = a->left;
        a->left = b->right;
        b->right = a;

        fixHeightNode(a);
        fixHeightNode(b);

        return b;
    }

    Node* smallLeftRotate(Node* a) {
        Node* b = a->right;
        a->right = b->left;
        b->left = a;

        fixHeightNode(a);
        fixHeightNode(b);

        return b;
    }

    Node* bigRightRotate(Node* node) {
        node->left = smallLeftRotate(node->left);
        return smallRightRotate(node);
    }

    Node* bigLeftRotate(Node* node) {
        node->right = smallRightRotate(node->right);
        return smallLeftRotate(node);
    }

    Node* balanceNode(Node* node) {
        if (node == nullptr) {
            return node;
        }

        fixHeightNode(node);

        int balance_factor = calcBalanceFactor(node);
        if (balance_factor > 1) {
            int balance_factor_left = calcBalanceFactor(node->left);
            if (balance_factor_left < 0) {
                return bigRightRotate(node);
            } else {
                return smallRightRotate(node);
            }
        } else if (balance_factor < -1) {
            int balance_factor_right = calcBalanceFactor(node->right);
            if (balance_factor_right > 0) {
                return bigLeftRotate(node);
            } else {
                return smallLeftRotate(node);
            }
        }

        return node;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->key) {
            node->left = insert(node->left, value);
        } else if (value > node->key) {
            node->right = insert(node->right, value);
        }

        node = balanceNode(node);

        return node;
    }

    Node* search(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value == node->key) {
            return node;
        } else if (value < node->key) {
            return search(node->left, value);
        } else if (value > node->key) {
            return search(node->right, value);
        }
    }
};