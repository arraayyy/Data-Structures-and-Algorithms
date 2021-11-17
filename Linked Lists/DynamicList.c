#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct {
    int *elem;
    int count;
    int max;
} AListDynamic;

void insertFirst(AListDynamic *list, int item) {
    if(list->max > list->count) {
        if(list->count != 0) {
            memcpy(list->elem + 1, list->elem, sizeof(int) * list->count);
            //  int i;
            // for(i = list->count - 1; i >= 0; i--) {
            //     list->elem[i + 1] = list->elem[i]; 
            // }
        }
        list->elem[0] = item;
        list->count++;
    } else {
        list->max *= 2;
        list->elem = realloc(list->elem, sizeof(int) * list->max);
        insertFirst(list, item);
    }
}

void insertRear(AListDynamic *list, int item) {
    if(list->max > list->count) {
        list->elem[list->count++] = item;
    } else {
        list->max *= 2;
        list->elem = realloc(list->elem, sizeof(int) * list->max);
        insertRear(list, item);
    }
}

void deleteFront(AListDynamic *list) {
    if(list->count != 0) {
        list->count--;
        memcpy(list->elem, list->elem + 1, sizeof(int) * list->count);
    }
}

void deleteRear(AListDynamic *list) {
    if(list->count != 0) {
        memcpy(list->elem, list->elem, sizeof(int) * --(list->count));
    }
}

int searchList(AListDynamic *list, int item) {
    int i, ndx = -1;

    for(i = 0; i < list->count; i++) {
        if(item == list->elem[i]) {
            ndx = i;
            break;
        }
    }

    return ndx;
}

void display(AListDynamic *list) {
    int i;
    for(i = 0; i < list->count; i++) {
        printf("%d ", list->elem[i]);
    }
    printf("\n");

    if(list->count == 0) {
        printf("EMPTY!\n");
    }
}

int main() {

    AListDynamic L;
 
    L.elem = malloc(sizeof(int) * SIZE);
    L.max = SIZE;
    L.count = 0;

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

    insertFirst(&L, 4);
    display(&L);

    insertFirst(&L, 4);
    display(&L);

    insertFirst(&L, 4);
    display(&L);

    insertFirst(&L, 4);
    display(&L);

    
    int ndx = searchList(&L, 3);
    if(ndx < 0) {
       
        printf("NOT FOUND");
    } else {
        printf("Found at position %d", ndx + 1);
    }

    return 0;
}
