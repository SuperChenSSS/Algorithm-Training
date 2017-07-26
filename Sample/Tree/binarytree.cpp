#include<stdio.h>
#include<stdlib.h>

typedef struct btnode{//二叉树结点的定义
    char element;
    struct btnode *lchild,*rchild;
}BTnode;

typedef struct btree{
    //二叉树的结构体定义，
    //包含一个指向二叉树根节点的指针root
    struct btnode *root;
}BTree;

BTnode *PreCreate(BTnode *t)//创建二叉树的私有递归函数
{
    char ch;
    ch = getchar();
    if(ch == '#')//读取#，表示这里将建立一个空二叉树
        t = NULL;
    else{
        t = (BTnode *)malloc(sizeof(BTnode));//生成结点
        t -> element = ch;
        t -> lchild = PreCreate(t->lchild);//创建左子树
        t -> rchild = PreCreate(t->rchild);//创建右子树
    }
    return t;
}

void Create(BTree *Bt)//公有函数，为二叉树创建的函数提供接口
{
    Bt -> root = PreCreate(Bt->root);
}

void PreOrd(BTnode *t)//先序遍历的私有递归函数
{
    if(t){//进行根、左、右操作
        printf("%c ",t->element);
        PreOrd(t->lchild);
        PreOrd(t->rchild);
    }
}
void PreOrder(BTree *Bt){//为先序遍历提供接口
    PreOrd(Bt->root);
}

void InOrd(BTnode *t)//中序遍历的私有函数
{
    if(t){//进行左、根、右操作
        InOrd(t->lchild);
        printf("%c ",t->element);
        InOrd(t->rchild);
    }
}
void InOrder(BTree *Bt){//为中序遍历提供接口
    InOrd(Bt->root);
}

void PostOrd(BTnode *t){
    if(t){//左右根
        PostOrd(t->lchild);
        PostOrd(t->rchild);
        printf("%c ",t->element);
    }
}
void PostOrder(BTree *Bt){
    PostOrd(Bt->root);
}

int nodes(BTnode *t)//求二叉树中的结点数
{
    int tn,ln,rn;
    if(!t)//二叉树为空，结点数为0
        tn = 0;
    else{
        ln = nodes(t->lchild);
        rn = nodes(t->rchild);
        tn = ln + rn + 1;//非空情况下，二叉树的结点数为
                        //左右子树结点数+1
    }
    return tn;
}
int Treenodes(BTree *Bt)//为二叉树求结点数提供接口
{
    return nodes(Bt->root);
}

int depth(BTnode *t)//私有递归函数，求二叉树的高度
{
    int td,ld,rd;
    if(!t)
        td = 0;//二叉树为空，高度为0
    else{
        ld = depth(t->lchild);
        rd = depth(t->rchild);
        if(ld>rd)//二叉树非空，高度为左右子树高度大的再+1
            td = ld + 1;
        else
            td = rd + 1;
    }
    return td;
}
int TreeDepth(BTree *Bt){
    return depth(Bt->root);
}

int leaves(BTnode *t)//求二叉树中的叶子结点个数
{
    int tl,ll,rl;
    if(!t)//二叉树为空，叶子结点为0
        tl = 0;
    else if((t->lchild == NULL)&&(t->rchild == NULL))
        tl = 1;
    else{//当前结点既非空，又有非叶子
        ll = leaves(t->lchild);
        rl = leaves(t->rchild);
        tl = ll + rl;//叶子个数为左右子树叶子个数之和
    }
    return tl;
}
int Treeleaves(BTree *Bt){
    return leaves(Bt->root);
}

int main()
{
    BTree *bt;
    int tn,th,tl;
    bt = (BTree *)malloc(sizeof(BTree));
    printf("\nInput Create Order:\n");
    Create(bt);
    printf("\nThe preorder is:\n");
    PreOrder(bt);
    printf("\nThe inorder is:\n");
    InOrder(bt);
    printf("\nThe postorder is:\n");
    PostOrder(bt);
    tn = Treenodes(bt);
    printf("\nThe nodes of the tree is:%d",tn);
    th = TreeDepth(bt);
    printf("\nThe depth of the tree is:%d",th);
    tl = Treeleaves(bt);
    printf("\nThe leaves of the tree is:%d\n",tl);
    return 0;
}