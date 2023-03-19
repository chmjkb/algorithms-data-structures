#include <iostream>

const int MAX_SIZE = 30;

class PriorityQueue
{
    int size;
    int *tab;
    int MAX_SIZE;

    int get_parent_idx(int current_idx) { return (current_idx - 1) / 2; }

    int get_left_child_idx(int parent_idx)
    {
        return 2 * parent_idx + 1;
    }

    int get_right_child_idx(int parent_idx)
    {
        return 2 * parent_idx + 2;
    }

public:
    PriorityQueue(int max_size) : MAX_SIZE(max_size)

    {
        tab = new int[MAX_SIZE];
        size = 0;
    }

    int get_size()
    {
        return size;
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
        throw 1;
    }

    void remove_root()
    {
        if (size == 0)
        {
            throw 1;
        }

        tab[0] = tab[size - 1];
        size--;

        int current_idx = 0;
        int left_child_idx = get_left_child_idx(current_idx);
        int right_child_idx = get_right_child_idx(current_idx);

        while (left_child_idx < size)
        {
            int max_child_idx = left_child_idx;

            if (right_child_idx < size && tab[right_child_idx] > tab[left_child_idx])
            {
                max_child_idx = right_child_idx;
            }

            if (tab[current_idx] < tab[max_child_idx])
            {
                std::swap(tab[current_idx], tab[max_child_idx]);
                current_idx = max_child_idx;
                left_child_idx = get_left_child_idx(current_idx);
                right_child_idx = get_right_child_idx(current_idx);
            }
            else
            {
                break;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << tab[i] << " " << std::endl;
        }
    }
};

int main()
{
    PriorityQueue priority_queue(MAX_SIZE);
    priority_queue.insert(60);
    priority_queue.insert(10);
    priority_queue.insert(12);
    priority_queue.insert(40);
    priority_queue.insert(50);
    priority_queue.insert(45);
    priority_queue.insert(90);
    priority_queue.insert(-5);
    priority_queue.insert(22);
    // priority_queue.print();

    // Test
    int size = priority_queue.get_size();
    std::cout << size << std::endl;
}