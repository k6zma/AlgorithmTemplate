#include <vector>

struct Stack
{
    std::vector<int> elements;

    void push(int elem)
    {
        elements.push_back(elem);
    }

    int pop()
    {
        int value = elements.back();
        elements.pop_back();
        return value;
    }

    int apex()
    {
        return elements.back();
    }

    bool empty()
    {
        return elements.empty();
    }
};
