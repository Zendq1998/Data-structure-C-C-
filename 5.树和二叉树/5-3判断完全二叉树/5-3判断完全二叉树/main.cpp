//
//  main.cpp
//  5-3判断完全二叉树
//
//  Created by Zendq1998 on 2017/12/7.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;
typedef char TElemType;
typedef struct TNode{
    TElemType data;
    TNode *lchild;
    TNode *rchild;
} TNode, *BiTree;
typedef BiTree ElemType;
#include "SQueue.h"

void CreateBiNode(BiTree &BT, TElemType e);
void CreateBiTree (BiTree &BT);
bool LevelOrderBiTree(BiTree BT);
void PrintBiTree(BiTree BT,int n);


int main() {
    BiTree BT;
    CreateBiTree(BT);
    PrintBiTree(BT,2);
    if (LevelOrderBiTree(BT)) {
        cout<<"该树是完全二叉树";
    }
    else {
        cout<<"该树不是完全二叉树";
    }
    return 0;
}

void CreateBiNode(BiTree &BT, TElemType e) {
    BT = (BiTree)malloc(sizeof(TNode));
    BT->data = e;
}

void CreateBiTree(BiTree &BT) {
    TElemType a;
    cin>>a;
    if(a == '#')
        BT = NULL;
    else {
        CreateBiNode(BT,a);
        CreateBiTree(BT->lchild);
        CreateBiTree(BT->rchild);
    }
}

void PrintBiTree(BiTree BT,int n) {
    //采用凹入表形式输出二叉树，n为缩进层数，初值为1
    int i;
    if (!BT) {
        return;
    }
    PrintBiTree(BT->rchild,n+1);//在第n+1层递归打印右子树
    for (i=2; i<n; ++i) {
        cout<<"   ";            //打印空格
    }
    if(n>1)
        cout<<" - - -";         //打印连线
    cout<<BT->data<<endl;       //打印根结点
    PrintBiTree(BT->lchild,n+1);//在第n+1层递归打印左子树
}

bool LevelOrderBiTree(BiTree BT) {
    //层序遍历BT并判断BT是否为完全二叉树
    SqQueue Q;
    BiTree p;
    int tag = 1;                //标志位用于判断是否遇到过缺右孩子的结点
    if (BT) {
        InitQueue_Sq(Q);        //初始化队列
        EnQueue_Sq(Q, BT);      //根指针进队
        while (!QueueEmpty_Sq(Q)) {
                                //队列非空
            DeQueue_Sq(Q, p);   //出队 元素赋给p
            
            if (tag == 1) {
                //迄今为止还没有碰到过缺右孩子的结点
                if (!p->lchild && p->rchild) {
                    return false;
                }//若p没有左孩子但是有右孩子直接返回false
                else if (p->lchild && p->rchild) {
                    //若p的左右孩子都存在
                    EnQueue_Sq(Q, p->lchild);
                    //左孩子进队
                    EnQueue_Sq(Q, p->rchild);
                    //右孩子进队
                }
                else {
                    //缺左孩子或者右孩子
                    tag = 0;
                    if(p->lchild) {
                        EnQueue_Sq(Q, p->lchild);
                    }//左孩子存在就进队
                }
            }
            else {
                //碰到了缺少右孩子的结点剩下的一定都是叶子
                if (p->lchild || p->rchild) {
                    return false;
                }
            }
        }
    }
    return true;
}
