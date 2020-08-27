#include <stdio.h>
#include <stdlib.h>
typedef float TYPE;
typedef struct node{
    TYPE data;
    struct node* next;
}Node;
typedef struct list{
    Node* start;
}LinkedList;
void init(LinkedList *list)
{
    list->start=NULL;
}
int isEmpty(LinkedList list){
    if(list.start==NULL)
        return 1;
    else
        return 0;
}
int insertFront(LinkedList *list,TYPE x){
    Node* p;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL)
        return 0;

   p->data=x;
   p->next=list->start;
   list->start=p;
   return 1;
}
int insertRear(LinkedList *list,TYPE x){
    Node* p=list->start;
    Node* q;
    q=(Node*)malloc(sizeof(Node));
    if(q==NULL)
        return 0;
    q->next=NULL;
    q->data=x;
    if(p==NULL){
       list->start=q;
    }
    else{
      p=list->start;
      while(p->next!=NULL){
        p=p->next;
      }
      p->next=q;
    }
    return 1;
}
int count(LinkedList list){
    int ctr=0;
    Node* p=list.start;
    while(p!=NULL)
    {
        ctr++;
        p=p->next;
    }
    return ctr;
}


int insertPos(LinkedList *list,TYPE x,int pos){
    int ctr= count(*list);
    if(pos<1 || pos>ctr+1)
    {
        printf("Invalid Position \n");
        return 0;
    }
    else if(pos==1)
        return insertFront(list,x);
    else if(pos==ctr+1)
        return insertRear(list,x);
    else{
            Node* q;
        q=(Node*)malloc(sizeof(Node));
        if(q==NULL)
            return 0;
        q->data=x;
        int i;
        Node* p=list->start;
        for(i=1;i<pos-1;i++)
            p=p->next;
        q->next=p->next;
        p->next=q;
        return 1;
    }
}
void printList(LinkedList list){
    Node* p=list.start;
    if(p==NULL)
        printf("Empty List\n");
    else{
        printf("List Values are:\n");
        while(p!=NULL){
            printf("%f\t",p->data);
            p=p->next;
        }
        printf("\n");
    }
}
int deleteFront(LinkedList *list,TYPE *x){
    Node *p=list->start;
    if(p==NULL)
        return 0;
    else{
        *x=p->data;
        list->start=p->next;
        free(p);
        return 1;
    }
}
int deleteRear(LinkedList *list,TYPE *x){
    Node *p=list->start;
    if(p==NULL) // zero Nodes
        return 0;
    else if(p->next==NULL) // one node
    {
        return deleteFront(list,x);
    }
    else{
        Node *q;
        q=p->next;
        while(q->next!=NULL){
            p=q;
            q=q->next;
        }
        *x=q->data;
        p->next=NULL;
        free(q);
        return 1;
    }
}
int deletePos(LinkedList *list,TYPE *x,int pos){
    int ctr= count(*list);
    if(pos<1 || pos>ctr)
    {
        printf("Invalid Position \n");
        return 0;
    }
    else if(pos==1)
        return deleteFront(list,x);
    else if(pos==ctr)
        return deleteRear(list,x);
    else{
        Node *p=list->start;
        int i;
        for(i=1;i<pos-1;i++)
            p=p->next;

        Node *q=p->next;
        p->next=q->next;
        *x=q->data;
        free(q);
        return 1;
    }
}

int find(LinkedList list,TYPE y){
    Node *p=list.start;
    while(p!=NULL){
        if(p->data==y)
            return 1;
        p=p->next;
    }
    return 0;

}

int getAvg(LinkedList list,float *avg){
    LinkedList l2;
    init(&l2);
    TYPE x,sum=0;
    int ctr=0;
    if(isEmpty(list))
        return 0;

    while(!isEmpty(list)){
        deleteFront(&list,&x);
        insertFront(&l2,x);
        sum+=x;
        ctr++;
    }
    *avg=sum/ctr;
    while(!isEmpty(l2)){
        deleteFront(&l2,&x);
        insertFront(&list,x);
    }
    return 1;
}



int main()
{
    LinkedList l1;
    init(&l1);
    insertFront(&l1,5);
    insertFront(&l1,8);

    insertFront(&l1,30);

    insertRear(&l1,70);

    insertRear(&l1,15);

    insertPos(&l1,55,3);
    float avg;
    if(getAvg(l1,&avg))
        printf("\nAverage = %f\n\n",avg);


    printList(l1);
    TYPE x;
    if(deleteFront(&l1,&x))
        printf("Deleted Value = %f\n",x);
    else{
        printf("Cannot delete from List\n");
    }
    printList(l1);
    if(deleteRear(&l1,&x))
        printf("Deleted Value = %f\n",x);
    else{
        printf("Cannot delete from List\n");
    }
    printList(l1);

    if(deletePos(&l1,&x,2))
        printf("Deleted Value = %f\n",x);
    else{
        printf("Cannot delete from List\n");
    }
    printList(l1);



    return 0;
}
