
#include <iostream>
using namespace std;
class MinHeap {
public:
    int* heap;
    int size;
    MinHeap(int size) : size(0) {
        heap = new int[size];
    }
    ~MinHeap(){
        delete[] heap;
    }
    void addElement(int value) {
        heap[size] = value;
        size++;
        siftUp(size - 1);
    }
    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                int temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            }
            else {
                break;
            }
        }
    }
    void siftDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            int temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;
            siftDown(smallest);
        }
    }
    void heapify() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }
    void removeMin() {
        if (size == 0) {
            std::cout << "Heap is empty.\n";
            return;
        }
        int temp = heap[0];
        heap[0] = heap[size - 1];
        heap[size - 1] = temp;
        size--;
        siftDown(0);
    }
    void removeElement(int value) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            int temp = heap[index];
            heap[index] = heap[size - 1];
            heap[size - 1] = temp;
            size--;
            siftDown(index);
            siftUp(index);
        }
        else {
            std::cout << "Element not found in the heap.\n";
        }
    }
    void printHeap() {
        for (int i = 0; i < size; i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << "\n";
    }
};
int main()
{
    MinHeap heap(10);
    heap.addElement(5);
    heap.addElement(8);
    heap.addElement(1);
    heap.addElement(3);
    heap.addElement(2);
    heap.removeElement(8);
    heap.printHeap();
}

