#include <iostream>
using namespace std;

template <class T>
class queueArray {
    int items;
    int maxSize;
    T* queue;

    public:
    queueArray() : items{0}, maxSize{2}, queue{new T[2]} {}

    void insert(T item) {
        if (items+1 > maxSize) {
            int newMax = maxSize * 2;
            T* tempQueue = new T[newMax];
            
            for(int i=0; i<maxSize; i++) 
                tempQueue[i] = queue[i];

            delete[] queue;
            queue = tempQueue;
            maxSize = newMax;
        }

        queue[items] = item;
        items += 1;
    }

    T pop() {
        if (items==0) {
            cout << "empty queue.";       
        }

        T item = queue[0];
        for(int i=1; i<items; i++) 
            queue[i-1] = queue[i];
        items -= 1;

        return item;
    }

    void print() {
        for(int i = 0; i<items; i++) 
            cout << queue[i];

        cout << endl;
    }
};

int main() {
    queueArray<char> q;

    q.insert('a');
    q.insert('b');
    q.insert('c');
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.insert(65);
    q.print();
}