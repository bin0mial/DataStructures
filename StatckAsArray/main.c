#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef float Data;
typedef struct stack{
Data array[SIZE];
int top;
}Stack;
void init(Stack *s){
    s->top=-1;
}
int isEmpty(Stack s){
    if(s.top==-1)
        return 1;
    else
        return 0;
}

int isFull(Stack s){
    if(s.top==SIZE-1)
        return 1;
    else
        return 0;
}
int push(Stack *s,Data x){
    if(isFull(*s))
        return 0;
    else{
        s->array[++s->top]=x;
        return 1;
    }

}

int pop(Stack *s,Data *x){
    if(isEmpty(*s))
        return 0;
    else{
        *x=s->array[s->top--];
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
