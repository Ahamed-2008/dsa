#include<stdio.h>
#include<stdbool.h>

struct Queue{
    int A[10];
    int rear;
    int front;
};

int isFull(struct Queue q){
    if(q.rear == 9){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue q){
    if(q.front == -1 || q.front > q.rear){
        return 1;
    }
    return 0;
}

void reset(struct Queue *q){
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q, int x){
    if(!isFull(*q)){
        if(q->front == -1) q->front++;
        q->rear++;
        q->A[q->rear] = x;
    }
    else{
        printf("The queue is full\n");
    }
}

int dequeue(struct Queue *q){
    int k = q->A[q->front];
    if(!isEmpty(*q)){
        q->front++;
        return k;
    }
    return -1;
}

void Display(struct Queue q){
    for(int i=q.front; i<=q.rear; i++){
        printf("%d ", q.A[i]);
    }
    printf("\n");
}

int main(){
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    int choice;
    int n;

    while(true){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.IsEmpty\n5.IsFull\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &n);
                enqueue(&q, n);
                break;

            case 2: {
                int val = dequeue(&q);
                if (val != -1) {
                    printf("%d dequeued from queue\n", val);
                }else{
                    printf("The queue is Empty\n");
                }
                break;
            }

            case 3:
                Display(q);
                break;

            case 4:
                if(isEmpty(q) == 1) printf("The queue is Empty\n");
                else printf("The queue is not Empty\n");
                break;

            case 5:
                if(isFull(q) == 1) printf("The queue is Full\n");
                else printf("The queue is not Full\n");
                break;
        }
    }

    return 0;
}
