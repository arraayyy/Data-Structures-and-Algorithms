#include <stdio.h>

#define MAX 10

typedef struct {
    int heap[MAX];
    int count;
} MaxHeap;

// INITIALIZE MAXHEAP
void init(MaxHeap *mxheap) {
    int i;

    for (i = 0; i < MAX; i++) {
        mxheap->heap[i] = NULL;
    }

    mxheap->count = 0;
}

// RETURN PARENT INDEX
int parent(int index) {
    return (index - 1) / 2;
}

// RETURN LEFT CHILD INDEX
int lchild(int index) {
    return 2 * index + 1;
}

// RETURN RIGHT CHILD INDEX
int rchild(int index) {
    return 2 * index + 2;
}

// SWAP TWO ELEMENTS IN MAXHEAP
void swap(MaxHeap *mxheap, int current, int parent) {
    int temp;

    temp = mxheap->heap[current];
    mxheap->heap[current] = mxheap->heap[parent];
    mxheap->heap[parent] = temp;
}

// INSERT ELEMENT IN MAXHEAP
void insert(MaxHeap *mxheap, int val) {
    int i;

    if(mxheap->count == MAX) {
        printf("\nHeap is full");
        return;
    }

    mxheap->count++;
    i = mxheap->count - 1;
    mxheap->heap[i] = val;

    while(i != 0 && mxheap->heap[parent(i)] < mxheap->heap[i]) {
        swap(mxheap, i, parent(i));
        i = parent(i);
    }
}

// DELETE MAX ELEMENT FROM MAXHEAP
void deleteMax(MaxHeap *mxheap) {
    int i, child;

    if (mxheap->count == 0) {
        printf("\nHeap is empty");
        return;
    }

    mxheap->heap[0] = mxheap->heap[mxheap->count - 1];
    mxheap->count--;

    i = 0;
    while (lchild(i) < mxheap->count) {
        child = lchild(i);
        if (rchild(i) < mxheap->count && mxheap->heap[rchild(i)] > mxheap->heap[child]) {
            child = rchild(i);
        }

        if (mxheap->heap[i] < mxheap->heap[child]) {
            swap(mxheap, i, child);
            i = child;
        } else {
            break;
        }
    }
}

// VISUALIZE MAXHEAP
void visualize(MaxHeap mxheap) {
    int i;

    for (i = 0; i < mxheap.count; i++) {
        printf("%d ", mxheap.heap[i]);
    }
}

// MAIN FUNCTION
int main() {
    MaxHeap mxheap;
    int choice, val;

    init(&mxheap);

    while (1) {
        printf("\n1. Insert\n2. Delete Max\n3. Visualize\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(&mxheap, val);
                break;
            case 2:
                deleteMax(&mxheap);
                break;
            case 3:
                visualize(mxheap);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
