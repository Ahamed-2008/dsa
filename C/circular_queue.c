#include<stdio.h>

struct cqueue{
    int A[10];
    int front;
    int rear;
    int size;
};

void initQueue(struct cqueue *q, int s){
    q->front = -1;
    q->rear = -1;
    q->size = s;
}

int isEmpty(struct cqueue q){
    if(q.front == -1){
        return 1;
    }
    return 0;
}

int isFull(struct cqueue q){
    if(q.front == (q.rear+1)%q.size){
        return 1;
    }
    return 0;
}

void enqueue(struct cqueue *q, int x){
    if(!isFull(*q)){
        if(q->front == -1){
            q->front = 0;
        }
        q->rear = (q->rear+1)%q->size;
        q->A[q->rear] = x;
    }else{
        printf("The queue is Full\n");
    }
}

void dequeue(struct cqueue *q){
    if(!isEmpty(*q)){
        if(q->front == q->rear){
            q->front = -1;
            q->rear = -1;
        }
        q->front = (q->front+1)%q->size;
    }
}

void display(struct cqueue q){
    if(isEmpty(q)){
        printf("The Queue is Empty\n");
    }else{
        int i = q.front;
        do{
            printf("%d ", q.A[i]);
            i = (i+1)%q.size;
        }while(i != (q.rear+1)%q.size);
        printf("\n");
    }
}

int main(){
    struct cqueue q;
      
      initQueue(&q, 5); 
      
      enqueue(&q, 10);
      enqueue(&q, 20);
      enqueue(&q, 30);
      enqueue(&q, 40);
      enqueue(&q, 50);
      dequeue(&q);
      
      display(q);
}