#include <iostream>
using namespace std;

typedef struct node{
    float data;
    node* left;
    node* right;
}Node;

typedef Node* BTREE;


int sum=0;
int count=0;

void resetCounters()
{
    sum=0;
    count=0;
}

int getSum(BTREE T)
{
    if(T!=NULL){
        sum +=T->data;
        getSum(T->left);
        getSum(T->right);
    }
    return sum;
}

int getNumber(BTREE T)
{
    if (T==NULL)
        return 0;
    else
        return 1+getNumber(T->left)+getNumber(T->right);

}

void getAverage(BTREE T)
{
    cout<< (getSum(T)+0.0)/getNumber(T)<<endl;
    resetCounters();
}

void inOrder(BTREE T){
    if(T!=NULL){
        inOrder(T->left);
        cout<<T->data<<"\t";
        inOrder(T->right);
    }
}
void preOrder(BTREE T){
    if(T!=NULL){
        cout<<T->data<<"\t";
        preOrder(T->left);
        preOrder(T->right);
    }
}

void postOrder(BTREE T){
    if(T!=NULL){
        postOrder(T->left);
        postOrder(T->right);
        cout<<T->data<<"\t";
    }
}

BTREE insertBST(BTREE T,float x){
    if(T==NULL){
        Node* p=new Node;
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        T=p;
    }
    else if(x>T->data){
        T->right= insertBST(T->right,x);
    }
    else if(x<T->data){
        T->left=insertBST(T->left,x);
    }

    return T;

}

Node* getMax(BTREE T){
    if(T==NULL)
        return NULL;
    else{
        if(T->right==NULL)
            return T;
        else
            return getMax(T->right);
    }

}
Node* getMin(BTREE T){
    if(T==NULL)
        return NULL;
    else{
        if(T->left==NULL)
            return T;
        else
            return getMin(T->left);
    }

}





int main()
{
    BTREE T1,T2,T3;
    T1=NULL;
    T1=insertBST(T1,5);
    T1=insertBST(T1,2);
    T1=insertBST(T1,8);
    T1=insertBST(T1,6);
    inOrder(T1);
    cout<<endl;

    Node* m=getMax(T1);
    if(m==NULL)
        cout<<"Empty Tree\n";
    else
        cout<<"Max= "<<m->data<<endl;

    getAverage(T1);


    return 0;
}

