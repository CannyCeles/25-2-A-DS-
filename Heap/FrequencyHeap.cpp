#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 256

// Heap node: stores letter and its frequency
struct HeapNode{
    char letter;
    int freq;
} ;

// Swap two heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down from index i in heap of size n
void heapify(HeapNode heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare left child
    if (left < n) {
        if (heap[left].freq > heap[largest].freq ||
            (heap[left].freq == heap[largest].freq && heap[left].letter > heap[largest].letter)) {
            largest = left;
        }
    }
    // Compare right child
    if (right < n) {
        if (heap[right].freq > heap[largest].freq ||
            (heap[right].freq == heap[largest].freq && heap[right].letter > heap[largest].letter)) {
            largest = right;
        }
    }
    // If largest is not root
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

// Build max heap from array
void buildHeap(HeapNode heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

int main() {
    int k;
    char s[105];
    scanf("%d", &k);
    scanf("%s", s);

    // Count frequency of each character
    int freq[256] = {0};
    for (int i = 0; s[i]; i++) {
        freq[(unsigned char)s[i]]++;
    }

    // Fill heap array with letters that appear
    HeapNode heap[MAX_SIZE];
    int n = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            heap[n].letter = (char)i;
            heap[n].freq = freq[i];
            n++;
        }
    }

    // Build the max heap
    buildHeap(heap, n);

    // Print top k letters
    for (int i = 0; i < k && n > 0; i++) {
        // Print the root of the heap (max freq, max ASCII)
        printf("%c: %d\n", heap[0].letter, heap[0].freq);
        // Move last element to root and heapify
        heap[0] = heap[n - 1];
        n--;
        heapify(heap, n, 0);
    }
    return 0;
}