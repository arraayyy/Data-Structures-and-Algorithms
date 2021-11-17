#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct {
    int arr[SIZE];
    int count;
} ArrayList;


void insertFirst(ArrayList *list, int item) {   // address of ArrayList is passed
    if(SIZE > list->count) {                   // if array is not full yet
        if(list->count != 0) {                //  and if it is not empty
            memcpy(list->arr + 1, list->arr, sizeof(int) * list->count);   // transfer array elements to the next index
        }
        list->arr[0] = item;   // place item as the first element
        list->count++;        // increment count, bcs of insertion
    }
}

void insertRear(ArrayList *list, int item) {   
    if(SIZE > list->count) {                // if array is not full yet
        list->arr[list->count++] = item;   //   add to the last
    }
}

void deleteFront(ArrayList *list) {
    if(list->count != 0) {           // if the earray is not empty
        memcpy(list->arr, list->arr + 1, sizeof(int) * --(list->count));  // overwrite first element with the succeeding elements
    }
}

void deleteRear(ArrayList *list) {
    if(list->count != 0) {
        memcpy(list->arr, list->arr, sizeof(int) * --(list->count)); //  copy the array, excluding the last element
    }
}

void display(ArrayList *list) {
    int i;
    for(i = 0; i < list->count; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");

    if(list->count == 0) {
        printf("EMPTY!\n");
    }
}

int searchList(ArrayList *list, int item) {
    int i, ndx = -1;

    for(i = 0; i < list->count; i++) {
        if(item == list->arr[i]) {
            ndx = i;
            break;
        }
    }

    return ndx;
}

int main() {

    ArrayList L = {{2, 3, 5},
                    3};

    insertFirst(&L, 4);
    display(&L);

    insertRear(&L, 8);
    display(&L);

    insertFirst(&L, 10);
    display(&L);

    deleteFront(&L);
    display(&L);

    deleteRear(&L);
    display(&L);
    
    int ndx = searchList(&L, 3);
    if(ndx < 0) {
       
        printf("NOT FOUND");
    } else {
        printf("Found at position %d", ndx + 1);
    }

    return 0;
}
