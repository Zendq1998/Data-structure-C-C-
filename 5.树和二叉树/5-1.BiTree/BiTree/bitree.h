//
//  bitree.h
//  BiTree
//
//  Created by Zendq on 2017/12/6.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#ifndef bitree_h
#define bitree_h


#endif /* bitree_h */

typedef struct BiTNode {
    TElemType data;  //节点的值
    struct BiTNode *lchild; //左孩子指针
    struct BiTNode *rchild; //右孩子指针
} BiTNode, *BiTree;

void CreateBiTree (BiTree &BT) {
    //先序创建二叉树
    TElemType a;
    cout<<"输入根结点（#为空根）：";
    cin>>a;                   //输入结点的值
    if (a == '#')             //如果输入为空
        BT = NULL;
    else {
        BT = (BiTree)malloc(sizeof(BiTNode)); //分配空间生成根结点
        if(!BT)
            exit(1);
        BT->data = a;              //赋值给根节点的data
        cout<<a<<"的左子树 ";
        CreateBiTree(BT->lchild);  //先序递归创建左子树
        cout<<a<<"的右子树 ";
        CreateBiTree(BT->rchild);  //先序递归创建右子树
    }
}//CreateBiTree

int NumofNode (BiTree BT) {
    //统计二叉树的结点个数
    if(!BT)
        return 0;   //当根结点不存在时返回0
    else
        return (NumofNode(BT->lchild) + NumofNode(BT->rchild) +1);
        //否则返回左子树的结点个数加上右子树的结点个数再加一
}//NumofNode

int Numofleaves (BiTree BT) {
    //统计二叉树叶子的个数
    if(!BT)
        return 0;   //当根结点不存在时返回0
    else if(!BT->lchild && !BT->rchild)
        return 1;   //当左右孩子都不存在时返回1
    else
        return (Numofleaves(BT->lchild) + Numofleaves(BT->rchild));
        //返回左子树的叶子个数加上右子树的叶子个数
}//Numofleaves

void Outputleaves (BiTree BT) {
    if (!BT) ; //若根不存在什么都不做
    else if (!BT->lchild && !BT->rchild)
        cout<<BT->data<<setw(3);  //若根不存在左孩子和右孩子即为叶子输出
    else {
        Outputleaves(BT->lchild);
        Outputleaves(BT->rchild);
    }//否则先后输出左子树和右子树的叶子
}//Outputleaves

void PrintBiTree(BiTree BT,int n)
{  // 采用凹入表形式输出二叉树,n为缩进层数,初值为1
    int i;
    if(!BT)return;
    PrintBiTree(BT->rchild,n+1);                  // 在第n+1层递归打印右子树
    for(i=2;i<n;++i)                              // 打印空格
        cout<<"      ";
    if(n>1)cout<<"  - - -";                       // 打印连线
    cout<<BT->data<<endl;                         // 打印根结点的值
    PrintBiTree(BT->lchild,n+1);                  // 在第n+1层递归打印左子树
}// PrintBiTree

