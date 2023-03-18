#include <iostream>

class PriorityQueue
{
    int size;
    int *tab;
    int MAX_SIZE;

    int get_parent_idx(int current_idx) { return (current_idx - 1) / 2; }

public:
    PriorityQueue()
    {
        MAX_SIZE = 100;
        tab = new int[MAX_SIZE];
        size = 0;
    }

    void insert(int element_to_add)
    {

        tab[size] = element_to_add;
        size++;
        int current_idx = size - 1;
        int parent_idx = get_parent_idx(current_idx);

        while (current_idx > 0 && tab[parent_idx] < element_to_add)
        {
            std::swap(tab[parent_idx], tab[current_idx]);
            current_idx = parent_idx;
            parent_idx = get_parent_idx(current_idx);
        }
    }

    int get_root()
    {
        if (size > 0)
        {
            return tab[0];
        }
        throw -1;
    }

    void remove_root()
    {
        std::swap(tab[0], tab[size - 1]);
        size--;
        int index = 0;
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        while (left_child < size)
        {
            int smaller_child = left_child;
            if (right_child < size && tab[right_child] < tab[left_child])
            {
                smaller_child = right_child;
            }
            if (tab[index] <= tab[smaller_child])
            {
                break;
            }
            std::swap(tab[index], tab[smaller_child]);
            index = smaller_child;
            left_child = 2 * index + 1;
            right_child = 2 * index + 2;
        }
    }
};
