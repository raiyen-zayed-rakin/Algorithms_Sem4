#include <iostream>
 
using namespace std;
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
 
 
class MaxHeap {
private:
    char* arr;
    int* frequencies;
    int capacity;
    int size;
 
public:
    MaxHeap(int cap) {
        capacity = cap;
        arr = new char[capacity];
        frequencies = new int[capacity];
        size = 0;
    }
 
    ~MaxHeap() {
        delete[] arr;
        delete[] frequencies;
    }
 
    int parent(int i) {
        return (i - 1) / 2;
    }
 
    int leftChild(int i) {
        return (2 * i) + 1;
    }
 
    int rightChild(int i) {
        return (2 * i) + 2;
    }
 
    void insert(char ch, int freq) {
        if (size == capacity) {
            cout << "Heap overflow!" << endl;
            return;
        }
 
        int i = size;
        arr[i] = ch;
        frequencies[i] = freq;
        size++;
 
        while (i != 0 && frequencies[parent(i)] < frequencies[i]) {
            swap(frequencies[i], frequencies[parent(i)]);
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
 
    void heapify(int i) {
        int largest = i;
        int l = leftChild(i);
        int r = rightChild(i);
 
        if (l < size && frequencies[l] > frequencies[largest]) {
            largest = l;
        }
        if (r < size && frequencies[r] > frequencies[largest]) {
            largest = r;
        }
 
        if (largest != i) {
            swap(frequencies[i], frequencies[largest]);
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }
 
    char extractRoot() {
        if (size <= 0) {
            cout << "Heap underflow!" << endl;
            return '\0'; // Return null character
        }
        if (size == 1) {
            size--;
            return arr[0];
        }
 
        char root = arr[0];
        arr[0] = arr[size - 1];
        frequencies[0] = frequencies[size - 1];
        size--;
        heapify(0);
 
        return root;
    }
 
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << "(" << frequencies[i] << ") ";
        }
        cout << endl;
    }
};
 
int main() {
    int capacity = 6;
    MaxHeap maxHeap(capacity);
 
    maxHeap.insert('a', 45);
    maxHeap.insert('b', 13);
    maxHeap.insert('c', 12);
    maxHeap.insert('d', 16);
    maxHeap.insert('e', 9);
    maxHeap.insert('f', 5);
 
    cout << "Max Heap: ";
    maxHeap.display();
 
    cout << "Max Heap - Extracted Root: " << maxHeap.extractRoot() << endl;
 
    cout << "Max Heap after extraction: ";
    maxHeap.display();
 
    return 0;
}