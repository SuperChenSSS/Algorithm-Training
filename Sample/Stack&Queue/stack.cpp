#include<iostream>
using namespace std;

int top;//栈顶指针
int maxTop;//最大栈顶指针
int *s;

bool IsEmpty(){return top == -1;}
bool IsFull(){return top == maxTop;}
bool Top(int &x)
{
    if(IsEmpty()){
        cout<<"Empty"<<endl;
        return false;
    }
    x = s[top];
    return true;
}
bool Push(int x)
{
    if(IsFull()){
        cout<<"Overflow"<<endl;
        return false;
    }
    s[++top] = x;
    return true;
}
bool Pop()
{
    if(IsEmpty()){
        cout<<"Underflow"<<endl;
        return false;
    }
    top--;
    return true;
}
void Clear(){top = -1;}
void SeqStack(int mSize)
{
    maxTop = mSize - 1;
    s = new int[mSize];
    top = -1;
}
int main()
{
    int mSize,elem;
    cout<<"Enter how many elements:";
    cin>>mSize;
    SeqStack(mSize);
    cout<<"Enter the element you want to push:"<<endl;
    cin>>elem;
    Push(elem);
    Push(9);
    cout<<s[top]<<" ";
    Pop();
    cout<<s[top]<<" "<<endl;
    Pop();
    cout<<*s<<endl;
    Clear();
    return 0;    
}