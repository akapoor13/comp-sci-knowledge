#include <stdio.h>
#include <vector.h>
using namespace std;

class Heap
{
    vector<int> heap;
    int capacity;

    int parent(int index)
    {
        return (index - 1) / 2
    }

    int left(int parent)
    {
        return parent * 2 + 1;
    }

    int right(int parent)
    {
        return (parent + 1) * 2;
    }

    int getMax()
    {
        return heap.at(0);
    }

    void heapifyUp(int i)
    {
        int par = parent(i);

        while (0 < par && heap[par] < heap[i])
        {
            int temp = heap[par];
            heap[par] = heap[i];
            heap[i] = temp;

            i = par;
            par = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int left = left(i);
        int right = right(i);
        
        while (left<capacity || right<capacity) {
            if left>capacity left=capacity;
            if right>capacity right=capacity;

            if (heap[i]<heap[left]) {
                temp = heap[left];
                heap[left] = heap[i];
                heap[i] = temp;

                i = left;
            } else if (heap[i] < heap[right]) {
                temp = heap[right];
                heap[right] = heap[i];
                heap[i] = temp;
            } else {
                return;
            }

            left = left(i);
            right = right(i);
        }
    }

    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(capacity);
        capacity += 1;
    }

    void delete (int index)
    {
        heap.erase(heap.begin());
        capcity -= 1;
        heapifDown(0);
    }
};