//以带表头结点单链表实现相关操作
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node{
    //结点定义
    int element;
    struct node *link;
}Node;

void CreatLink(Node *first,int n);
//创建带表头结点单链表，采用后置链表生成法
void InsertLink(Node *first,int pos,int x);
//带表头结点单链表pos位置插入值为x的新结点
void DeleteLink(Node *first,int pos);
//删除带表头结点单链表pos位置上的结点
void PrintLink(Node *first);
//输出带表头结点单链表中的值
Node *FindLink(Node *first,int x);
//查找带表头结点单链表中是否存在值为x的结点

int main()
{
    Node *first,*p;
    int size,pos1,pos2,x,key,n = 1;
    first = new Node[sizeof(Node)];//设置创建函数的参数
    first->link = NULL;
    while(n)
    {
        printf("**************单链表操作**************\n");
        printf("*********** 1. 创 建 链 表 ***********\n");
        printf("*********** 2. 插 入 结 点 ***********\n");
        printf("*********** 3. 删 除 结 点 ***********\n");
        printf("*********** 4. 查 找 链 表 ***********\n");
        printf("*********** 0. 结 束 程 序 ***********\n");
        printf("请输入你的选择:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("\n请输入预创建单链表的结点数:\n");
                scanf("%d",&size);
                CreatLink(first,size);//调用创建
                PrintLink(first);//调用输出
                break;
            case 2:
                printf("\n请输入插入结点的位置和结点的值x：\n");//设置插入函数的参数
                scanf("%d%d",&pos1,&x);
                InsertLink(first,pos1,x);//调用插入
                PrintLink(first);//调用输出
                break;
            case 3:
                printf("\n请输入删除结点的位置：\n");
                //设置删除函数的参数
                scanf("%d",&pos2);
                DeleteLink(first,pos2);//调用删除
                PrintLink(first);
                break;
            case 4:
                printf("\n请输入想要查找的key:\n");
                scanf("%d",&key);
                p = FindLink(first,key);
                if(p)
                    printf("\n查找成功！\n");
                else
                    printf("\n查找失败！\n");
                break;
            case 0:
                cout<<"欢迎您的使用，再见~"<<endl;
                break;
        }
    }
    return 0;
}

void CreatLink(Node *first,int n){
    int i;
    Node *p,*s;//p始终指向表尾位置，s用于建立新结点
    p = first;
    printf("\n请输入单链表结点的值：\n");
    for(i=1;i<=n;i++){
        s = (Node *)malloc(sizeof(Node));//创建新结点，书上用NewNode2函数实现
        scanf("%d",&s->element);
        s->link = NULL;
        p->link = s;
        p = s;
    }
}

void InsertLink(Node *first,int pos,int x){
    //带表头结点的单链表pos位置插入值为x的新结点
    int i;
    Node *p,*q;
    p = first;
    i = 0;
    while((i<pos-1)&&(p!=NULL))//p指向插入点前一个结点，过程与书上setpos函数类似
    {
        p = p->link;
        i++;
    }
    q = (Node *)malloc(sizeof(Node));
    //创建新结点，书上用NewNode1函数实现
    q->element = x;//进行插入
    q->link = p->link;
    p->link = q;
}

void DeleteLink(Node *first,int pos){
    //删除带表头结点单链表pos位置上的结点
    int i;
    Node *p,*q;
    p = first;
    i = 0;
    while((i<pos-1)&&(p->link!=NULL)){
        //p指向插入点前一个结点，过程与书上setpos函数类似
        p = p->link;
        i++;
    }
    q = p->link;//进行删除
    p->link = q->link;
    free(q);
}

void PrintLink(Node *first){
    //输出带表头结点单链表的值
    Node *p;
    printf("\n当前单链表为：\n");
    p = first->link;
    while(p){
        printf("%d ",p->element);
        p = p->link;
    }
    printf("\n");
}

Node *FindLink(Node *first,int x){
    //查找带表头结点单链表中是否存在值为x的结点
    Node *p;
    p = first->link;
    while((p->element!=x)&&(p!=NULL))
        p = p->link;
    return p;
}