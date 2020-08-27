#include <stdio.h>
#include <stdlib.h>

typedef float Data;
typedef struct node{
Data data;
struct node* next;
}Node;

typedef struct stack{
struct Node* top;
}Stack;


void init(Stack *s){
    s->top=NULL;
}
int isEmpty(Stack s){
    if(s.top==NULL)
        return 1;
    else
        return 0;
}

int push(Stack *s,Data x){
    Node* p;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL)
        return 0;

    else{
        p->data=x;
    p->next=s->top;
    s->top=p;
        return 1;
    }

}

int pop(Stack *s,Data *x){
    if(isEmpty(*s))
        return 0;
    else{
            Node* p=s->top;
        *x=p->data;
        s->top=p->next;
        free(p);
        return 1;
    }
}
Data getSum(Stack s){
   Data sum=0,x;
   Stack s2;
   init(&s2);
   while(pop(&s,&x)){
    sum+=x;
    push(&s2,x);
   }
   while(pop(&s2,&x)){

    push(&s,x);
   }
       return sum;


}

int main()
{
    Stack s;
    init(&s);
    push(&s,5);
    push(&s,8);
    push(&s,20);

    Data a=getSum(s);
        printf("Sum = %f\n",a);
    return 0;
}
