#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal(BinTree BT);

void PreorderTraversal(BinTree BT);

void PostorderTraversal(BinTree BT);

void LevelorderTraversal(BinTree BT);

void create(BinTree *t)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        *t = NULL;
    else
    {
        (*t) = malloc(sizeof(BinTree));
        (*t)->Data = ch;
        create(&(*t)->Left);
        create(&(*t)->Right);
    }
}

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
    return 0;
}

/* 你的代码将被嵌在这里 */
BinTree CreatBinTree()
{
    BinTree t;
    create(&t);
    return t;
}

void InorderTraversal(BinTree BT)//中
{
    if (BT == NULL)
    {
        return;
    }

    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);
}

void PreorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}//先序

void PostorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}//后序

void LevelorderTraversal(BinTree BT)
{
    if(BT==NULL)
        return;
    BinTree date[1000];
    int rear, front;
    rear = front = 0;
    date[rear++] = BT;
    BinTree t1, t2;
    t1=date[front]->Left;
    t2=date[front]->Right;
    while (rear!=front)
    {

        t1=date[front]->Left;
        t2=date[front]->Right;
        printf(" %c",date[front]->Data);
        front++;
        if(t1)
            date[rear++] = t1;
        if(t2)
            date[rear++] = t2;
    }
}