#include<iostream>
using namespace std;
const int MAXSIZE = 10;
typedef struct queue{
    int data[MAXSIZE];
    int front;
    int rear;
    int size;
}Q;

Q* Create(){
    Q* q = new Q[sizeof(Q)];
    if(!q){
        printf("No Room\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}
int IsFull(Q* q)
{
    return q->size == MAXSIZE;
}

void Push(Q* q,int item){
    if(IsFull(q)){
        cout<<"Queue is full!\n";
        return;
    }
    q->rear++;
    q->rear %= MAXSIZE;
    q->size++;
    q->data[q->rear] = item;
}
int IsEmpty(Q* q){
    return q->size == 0;
}

int Pop(Q* q){
    if(IsEmpty(q)){
        cout<<"Empty!"<<endl;
        return -1;
    }
    q->front++;
    q->front %= MAXSIZE;//0 1 2 3 4 5
    q->size--;
    return q->data[q->front];
}

void Print(Q* q){
    if(IsEmpty(q)){
        cout<<"Empty"<<endl;
        return;
    }
    printf("Print Elements:\n");
    int index = q->front;
    for(int i=0;i<q->size;i++){
        index++;
        index %= MAXSIZE;
        cout<<" "<<q->data[index];
    }
    cout<<"\n";
}

int main()
{
    Q* q = Create();
    for(int i=1;i<=9;i++)
        Push(q,i);
    Print(q);
    Pop(q);
    Print(q);
    Pop(q);
    Print(q);
    return 0;
}