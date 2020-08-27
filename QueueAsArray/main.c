#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef float Data;
typedef struct queue{
Data array[SIZE];
int front,rear,count;
}Queue;
void init(Queue *q){
    q->count=0;
    q->front=0;
    q->rear=0;
}
int isEmpty(Queue q){
    if(q.count==0)
        return 1;
    else
        return 0;
}

int isFull(Queue q){
    if(q.count==SIZE)
        return 1;
    else
        return 0;
}
int enqueue(Queue *q,Data x){
    if(isFull(*q))
        return 0;
    else{
         q->array[q->rear]=x;
    q->rear=(q->rear+1)%SIZE;
        q->count++;
        return 1;
    }

}

int dequeue(Queue *q,Data *x){
    if(isEmpty(*q))
        return 0;
    else{
        *x=q->array[q->front];
        q->front=(q->front+1)%SIZE;
        q->count--;
        return 1;
    }
}

Data getSum(Queue q){
   Data sum=0,x;
   Queue q2;
   init(&q2);
   while(dequeue(&q,&x)){
    sum+=x;
    enqueue(&q2,x);
   }
   while(dequeue(&q2,&x)){

    enqueue(&q,x);
   }
       return sum;


}

int main()
{
    Queue q;
    init(&q);
    enqueue(&q,5);
    enqueue(&q,8);
    enqueue(&q,20);

    Data a1=getSum(q);
        printf("Sum = %f\n",a1);

   Data a;
   if(dequeue(&q,&a))
        printf("Removed value = %f\n",a);
    return 0;
}
