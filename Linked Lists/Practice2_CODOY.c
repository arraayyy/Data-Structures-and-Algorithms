#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *elem;
    int count;
    int max;
} ArrayList;

void findMode(ArrayList arr);
int findRange(ArrayList arr);
float findMedian(ArrayList arr);
float findMean(ArrayList arr);
void insertFirst(ArrayList *list, int item);
void deleteItem(ArrayList *list, int item);
void displayStatistics(ArrayList arr);

int main() {

    int i;
    ArrayList arr;

    printf("How many numbers will you input? ");
    scanf("%d", &arr.count);
    
    arr.max = arr.count;

    arr.elem = malloc(sizeof(int) * arr.count);

    printf("Enter the %d values: ", arr.count);
    for(i = 0; i < arr.count; i++) {
        scanf("%d", &(arr.elem[i]));
    }
    
    displayStatistics(arr);
    

    int option, item;

    
    do{
        printf("\nEnter 1 to Add\nPress 2 to Delete\nPress 0 to Exit\nChoice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
                printf("Enter the number: ");
                scanf("%d", &item);

                insertFirst(&arr, item);
                displayStatistics(arr);
                break;
            
        case 2:
             printf("Enter the number: ");
             scanf("%d", &item);

            deleteItem(&arr, item);
            displayStatistics(arr);
            break;
        }
    } while (option != 0);
  
    

    return 0;
}

void findMode(ArrayList arr) {

    int maxCount = 0, i, j;
    int countArr[arr.count]; // frequency array
    for(i = 0; i < arr.count; i++) {  
        int cnt = 0;
        for(j = i; j < arr.count; j++) {       // matches instances of an element on that index until the last element
            if(arr.elem[i] == arr.elem[j]) {   
                cnt++;
            }
        }

        countArr[i] = cnt;    // assigning element count to frequency array on the same index

        if(cnt > maxCount) {  // getting new max count
            maxCount = cnt;  
        }
    }

    printf("\nMode: ");
    for (i = 0; i < arr.count; i++) {
        if (countArr[i] == maxCount) {    // if same value
            printf("%d ", arr.elem[i]);
        }
    }
}

int findRange(ArrayList arr) {

    int min, max, i;
    
    max = min = arr.elem[0];

    for(i = 1; i < arr.count; i++) {
        if(max < arr.elem[i]) {
            max = arr.elem[i];
        }
        if(min > arr.elem[i]) {
            min = arr.elem[i];
        }
    }

    return max - min;
}

float findMedian(ArrayList arr) {

    int length, i, j;
    
    for(i = 0; i < arr.count; i++) {
        for(j = i; j < arr.count; j++) {
            if(arr.elem[i] > arr.elem[j]) {
                int temp;
                temp = arr.elem[i];
                arr.elem[i] = arr.elem[j];
                arr.elem[j] = temp;
            }
        }
    }

    float median;

    if(arr.count % 2 == 0) {
        median = (arr.elem[(arr.count / 2) - 1] + arr.elem[arr.count / 2]) / 2;
    } else {
        median = arr.elem[arr.count / 2];
    }

    return median;
}

float findMean(ArrayList arr) {

    int sum = 0;
    float mean;
    int i;

    for(i = 0; i < arr.count; i++) {
        sum += arr.elem[i];
    }
    
    mean = (float)sum / (float)arr.count;

    return mean;
}

void insertFirst(ArrayList *list, int item) {
    if(list->max > list->count) {
        if(list->count != 0) {
            memcpy(list->elem + 1, list->elem, sizeof(int) * list->count);
        }
        list->elem[0] = item;
        list->count++;
    } else {
        list->max *= 2;
        list->elem = realloc(list->elem, sizeof(int) * list->max);
        insertFirst(list, item);
    }
}

void deleteItem(ArrayList *list, int item) {

    int i;

    for(i = 0; i < list->count; i++) {
        if(list->elem[i] == item) {
            memcpy(list->elem + i, list->elem + i + 1, sizeof(int) * (list->count)--);
            break;
        }
    }
}

void displayStatistics(ArrayList arr) {
    findMode(arr);
    printf("\nRange: %d", findRange(arr));
    printf("\nMedian: %.1f", findMedian(arr));
    printf("\nMean: %.2f\n", findMean(arr));
}


