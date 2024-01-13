struct Node
{
    int key;
    Node* prev;
};

struct Stack
{
    Node* top = nullptr;

    void push(int elem)
    {
        Node* node = new Node();
        node->key = elem;
        node->prev = top;
        top = node;
    }

    int pop()
    {
        Node* node = top;
        int value = node->key;
        top = top->prev;
        return value;
    }

    int apex()
    {
        return top->key;
    }

    bool empty()
    {
        return top == nullptr;
    }
};