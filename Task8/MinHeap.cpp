#include <iostream>

using namespace std;
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
class MinHeap {
private:
    char* arr;
    int* frequencies;
    int capacity;
    int size;

public:
    MinHeap(int cap) {
        capacity = cap;
        arr = new char[capacity];
        frequencies = new int[capacity];
        size = 0;
    }

    ~MinHeap() {
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

        while (i != 0 && frequencies[parent(i)] > frequencies[i]) {
            swap(frequencies[i], frequencies[parent(i)]);
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int smallest = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < size && frequencies[l] < frequencies[smallest]) {
            smallest = l;
        }
        if (r < size && frequencies[r] < frequencies[smallest]) {
            smallest = r;
        }

        if (smallest != i) {
            swap(frequencies[i], frequencies[smallest]);
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    char extractRoot() {
        if (size <= 0) {
            cout << "Heap underflow!" << endl;
            return '\0';
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
    MinHeap minHeap(capacity);

    minHeap.insert('a', 45);
    minHeap.insert('b', 13);
    minHeap.insert('c', 12);
    minHeap.insert('d', 16);
    minHeap.insert('e', 9);
    minHeap.insert('f', 5);

    cout << "Min Heap: ";
    minHeap.display();

    cout << "Min Heap - Extracted Root: " << minHeap.extractRoot() << endl;

    cout << "Min Heap after extraction: ";
    minHeap.display();

    return 0;
}
