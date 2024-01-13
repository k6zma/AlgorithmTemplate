#include <iostream>
#include <vector>
#include <string>

struct heap
{
    std::vector<int> data;

    void sift_up(int index)
    {
        while (index != 0 && data[index] > data[(index - 1) / 2])
        {
            int parent_index = (index - 1) / 2;
            if (data[index] > data[parent_index])
            {
                std::swap(data[index], data[parent_index]);
                index = parent_index;
            } else
            {
                break;
            }
        }
    }

    void sift_down(int index, int heap_size)
    {
        while (2 * index + 1 < heap_size)
        {
            int left_child_index = 2 * index + 1;
            int right_child_index = 2 * index + 2;
            int smallest_child_index = left_child_index;

            if (right_child_index < heap_size && data[right_child_index] > data[left_child_index])
            {
                smallest_child_index = right_child_index;
            }

            if (data[index] >= data[smallest_child_index])
            {
                break;
            }

            std::swap(data[index], data[smallest_child_index]);
            index = smallest_child_index;
        }
    }

    void push(int value)
    {
        data.push_back(value);
        sift_up(data.size() - 1);
    }

    void build_heap()
    {
        for (int i = data.size() / 2 - 1; i >= 0; i--)
        {
            sift_down(i, data.size());
        }
    }

    void heap_sort()
    {
        build_heap();

        for (int i = data.size() - 1; i >= 0; i--)
        {
            std::swap(data[0], data[i]);
            sift_down(0, i);
        }
    }

    void print_sorted_heap()
    {
        for (int i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << " ";
        }
    }
};

int main()
{
    int n;
    std::cin >> n;

    heap heap;

    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;

        heap.push(temp);
    }

    heap.heap_sort();
    heap.print_sorted_heap();
}