#include "Person.h"
#include <stdio.h>
#define MAX 100
typedef Person Type;
typedef int Position;
typedef int StackList;

typedef struct {
    Person elem;
    Position next;
} CNode;

typedef struct {
    CNode data[MAX];
    Position avail;
} VSpace;


// initVSpace()
void initVspace(VSpace *vs) {
    int i;
    for(i=MAX-1; i>=0; --i) {
        vs->data[i].next = i-1;
    }
    vs->avail = MAX-1;
} 

// allocSpace()
Position allocSpace(VSpace *vs) {
    Position avail = vs->avail;

    if(avail != -1) {
        vs->avail = vs->data[avail].next;
    }

    return avail;
}
// freeSpace()
void freeSpace(VSpace *vs, Position index) {
    if(index != -1 && index < MAX) {
        strcpy(vs->data[index].elem.name, NULL);
        vs->data[index].elem.sex = '\0';
        strcpy(vs->data[index].elem.city, NULL);
        vs->data[index].next = vs->avail;
        vs->avail = index;
    }
}
// push()

void push(VSpace *vs,   StackList *list, Type item) {
    Position temp = allocSpace(vs);

    if(temp != -1) {
        vs->data[temp].elem = item;
        vs->data[temp].next = *list;
        *list = temp;
    }
}
// pop()

void pop(VSpace *vs, StackList *list) {
    Position temp = *list;

    if(*list != -1) {
        *list = vs->data[*list].next;
        freeSpace(vs, temp);
    }
}   

// peek()
Person peek(VSpace *vs, StackList *list) {
    if(*list != -1) {
        return vs->data[*list].elem;
    } else {
        Person val;
        return val;
    }
}

/************************************************************************************************
 * Create a function that would insert a new person based on the order of the city in ASC order. 
 * Top must always have the smallest value.
 * Utilize the functions push, pop, and peek.
 * HINT: You could use also another stack/temporary stack.
 * **********************************************************************************************/

VSpace sortInsert(VSpace *vs, StackList *list, Person desc) {
   
    push(vs, list, desc);

    VSpace tempStack;
    StackList tempList = -1;


    while(*list != -1) {
        Type tmp = peek(vs,list);
        pop(vs, list);
        Type top = peek(&tempStack, &tempList);
        while(tempList != -1 && strcmp(top.city, tmp.city) >= 0) {
            push(&tempStack, &tempList, top);
            pop(&tempStack, &tempList);
        }
        push(&tempStack, &tempList, tmp);
    }
    return tempStack;
}

/************************************************************************************************
 * Create a function that would extract (remove from the original list) the person living from a
 * specified city.
 * Utilize the concept of stack but will not use the functions push, pop, and peek.
 * HINT: You could use also another stack/temporary stack.
 * **********************************************************************************************/

void extractList(VSpace *vs, StackList *list, String city) {
    
    if(*list != -1) {
        int i;
        for(i = MAX; i > vs->avail; i--) {
            if(strcpy(vs->data[i].elem.city, city) == 0) {
                if(i == MAX) {
                    strcpy(vs->data[i].elem.name, NULL);
                    vs->data[i].elem.sex = '\0';
                    strcpy(vs->data[i].elem.city, NULL);
                    vs->data[i - 1].next = -1;
                } else if(i == vs->avail + 1) {
                    Position temp = *list;
                    if(*list != -1) {
                        *list = vs->data[*list].next;
                        freeSpace(vs, temp);
                    }
                } else if(vs->data[i].next == -1) {
                    strcpy(vs->data[i].elem.name, NULL);
                    vs->data[i].elem.sex = '\0';
                    strcpy(vs->data[i].elem.city, NULL);
                    vs->data[i - 1].next = -1;
                } else {
                    vs->data[i - 1].next = vs->data[i].next;
                    vs->data[i].next = -1;
                    strcpy(vs->data[i].elem.name, NULL);
                    vs->data[i].elem.sex = '\0';
                    strcpy(vs->data[i].elem.city, NULL);
                }
            }
        }
    }
}

// visualization
void vizualizeSpace(VSpace vs) {
    int i;
    printf("%15s | %15s | %15s\n", "INDEX", "ELEM", "NEXT");
    for(i=0; i<MAX; i++) {
        printf("%15d | %15d | %15d\n", i, vs.data[i].elem, vs.data[i].next);
    }
    printf("Available: %d\n", vs.avail);
}

// display
void displayList(VSpace vs, StackList list) {
    int i;
    printf("{");
    for(i=list; i != -1; i = vs.data[i].next) {
        printf("%d ", vs.data[i].elem);
    }
    printf("}\n");
}
