#include <iostream>
using namespace std;

template <class T>
class DynArray
{
    T *arr;
    int maxSize;
    int items;

public:
    DynArray() : arr{new T[2]}, maxSize{2}, items{0} {}; // Initalize Array of Size 2

    void insert(int pos, T element)
    {
        if (pos > maxSize) { // Invalid if posn is greater than maxSiz -- do nothing.
            return;
        }
        
        if ((items + 1) > maxSize) // Resize if adding another element makes array too large.
        {
            int tempSize = maxSize;

            while ((items + 1) > tempSize) // increase max size
                tempSize *= 2;

            T *tempArr = new T[tempSize]; // allocate, copy and move new array

            for (int i = 0; i < maxSize; i++)
                tempArr[i] = arr[i];

            delete[] arr; // remember delete[] for pointers not just delete
            arr = tempArr;
            maxSize = tempSize;
        }

        for (int i = items - 1; i >= pos; i--) // shift right
        {
            arr[i + 1] = arr[i];
        }

        arr[pos] = element;
        items += 1;
    }

    void del (int pos)
    {
        if (pos > items) // invalid if posn greater than number of items
        {
            return;
        }

        items -= 1;
        for (int i = pos; i < items; i++) // shift left
        {
            arr[i] = arr[i + 1];
        }
    }

    void print()
    {
        for (int i = 0; i < items; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
};

int main()
{
    DynArray<int> arr;

    arr.insert(0, 1);
    arr.insert(1, 2);
    arr.print();
    arr.insert(2, 3);
    arr.insert(3, 4);
    arr.print();
    arr.insert(0, 5);
    arr.print();
    arr.insert(2, 6);
    arr.print();
    arr.insert(6, 7);
    arr.print();
    arr.del(0);
    arr.print();
    arr.del(5);
    arr.print();
    arr.del(3);
    arr.print();
    arr.del(1);
    arr.del(2);
    arr.print();
    arr.del(1);
    arr.print();
    arr.del(0);
    arr.print();
}

