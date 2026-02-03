#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

struct Node *last;

void create(int A[], int n) {
    struct Node *t;
    
    // 1. Create the first node
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first; // 'last' starts at the beginning

    // 2. Link the rest of the nodes
    for (int i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        
        last->next = t; // Link the previous node to this new node
        last = t;       // Move 'last' to the new node
    }
}

int findMax(struct Node *p){
    struct Node *temp;
    temp = p;
    int max = -32768;
    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void Display(struct Node *p) {
    struct Node *temp = p;
    while (p != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int Add(struct Node *p){
    int sum = 0;
    struct Node *temp = p;
    while (temp != NULL){
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

void addtofront(struct Node *p, int x){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = p;
    first = temp;
}

void addtoend(struct Node *p, int x){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    last->next = temp;
    last = temp;
}

int search(struct Node *p, int x){
    int i=-1;
    int k=0;
    struct Node *temp;
    temp = p;
    while(temp != NULL){
        i++;
        if(temp->data == x){
            return i;
        }
        temp = temp->next;
        k++;
    }  
    return -1;
}

void deleteLast(struct Node *p){
    struct Node *temp;
    temp = p;
    while(temp != NULL){
        if (temp->next == last){
            temp->next = NULL; 
            free(last);
        }
        temp = temp->next;
    }
    last = temp;
}

void deleteValue(int x) {
    struct Node *p = first;
    struct Node *q = NULL;

    // Case 1: The list is empty
    if (first == NULL) return;

    // Case 2: The node to delete is the first node
    if (p->data == x) {
        first = first->next;
        free(p);
        return;
    }

    // Case 3: Search for the node containing x
    while (p != NULL && p->data != x) {
        q = p;      // Move q to where p is
        p = p->next; // Move p to the next node
    }

    // If p is not NULL, it means we found the value
    if (p != NULL) {
        q->next = p->next; // Link previous node to the one after p
        free(p);           // Free the memory of the node containing x
    } else {
        printf("Value %d not found in the list.\n", x);
    }
}
int count(struct Node *p){
    int i = 0;
    struct Node *temp;
    temp = p;
    while(temp != NULL){
        i++;
        temp = temp->next;
    }
    return i;
}

void insert(struct Node *p, int pos, int x){
    if(pos > count(first)) printf("Invalid Position\n");
    else{
    printf("Element %d Inserted at position %d\n", x, pos);
    int i=0;
    struct Node *q;
    struct Node * temp;
    temp = p;
    while(i<pos){
        q = temp;
        temp = temp->next;
        i++;
    }
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    q->next = t;
    t->next = temp;
    t->data = x;
}
}

//Reversing a linked by reversing the links
void Reverse(struct Node *t){
    struct Node *p;
    struct Node *q = NULL;
    struct Node *r = NULL;
    p = t;
    while (p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main() {
    int A[5] = {3, 5, 7, 10, 15};
    create(A, 5);
    addtofront(first, 2);
    addtoend(first, 17);
    deleteValue(5);
    insert(first, 4, 12);
    Reverse(first);
    Display(first);
    printf("\n");
    printf("Sum: %d", Add(first));
    printf("\n");
    printf("Maximum element: %d\n", findMax(first));
    printf("Index of 7: %d\n", search(first, 7));
    printf("Count: %d\n", count(first));
    return 0;
}