#include <vector>

struct Queue
{
    struct Node
    {
        int value;
    };

    std::vector<Node> elements;
    int head_index = 0;

    void push(int value)
    {
        Node element;
        element.value = value;
        elements.push_back(element);
    }

    int pop()
    {
        int tmp_value = elements[head_index].value;
        head_index++;

        if (head_index >= elements.size())
        {
            elements.clear();
            head_index = 0;
        }

        return tmp_value;
    }

    int top()
    {
        return elements[head_index].value;
    }

    bool empty()
    {
        return head_index >= elements.size();
    }
};
