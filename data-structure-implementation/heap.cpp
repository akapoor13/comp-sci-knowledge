#include <stdio.h>
#include <vector>
using namespace std;

class Heap
{
    vector<int> heap;
    int capacity;

    int parent(int index)
    {
        return (index - 1) / 2;
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

    void heapifyUp(int val)
    {
        int par = parent(i);
        int i = capacity;

        while (0 < par && heap[par] < val)
        {
            heap[i] = heap[par];
            i = par;
            par = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int l = left(i);
        int r = right(i);
        
        while (l<capacity || r<capacity) {
            int largest;

            if (l<capacity && heap[l]>heap[i]) {
                largest = l;
            }

            if (r<capacity && heap[r]>heap[largest]) {
                largest = r;
            }

            if (largest!=i) {
                swap(heap[largest], heap[i]);
                i = largest;
            }

        }
    }

    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(val);
        capacity += 1;
    }

    void del()
    {
        heap[0] = heap[capacity];
        heap.erase(heap.end());
        capacity -= 1;
        
        heapifDown(0);
    }
};