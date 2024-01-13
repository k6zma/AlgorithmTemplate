struct Node
{
    Node* next = nullptr;
    int value;
};

struct Queue
{
    Node* head = nullptr;
    Node* tail = nullptr;

    void push(int value)
    {
        Node* element = new Node;
        element->value = value;

        if (tail == nullptr && head == nullptr)
        {
            head = element;
            tail = element;
        } else
        {
            tail->next = element;
            tail = element;
        }

    }

    int pop()
    {
        Node* tmp = head->next;
        int tmp_value = head->value;

        if (head->next != nullptr)
        {
            head = tmp;
        } else {
            head = nullptr;
            tail = nullptr;
        }

        return tmp_value;
    }

    int top()
    {
        return head->value;
    }

    bool empty()
    {
        return head == nullptr;
    }
};