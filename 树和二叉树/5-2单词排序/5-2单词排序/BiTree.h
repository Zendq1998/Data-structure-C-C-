//
//  BiTree.h
//  5-2单词排序
//
//  Created by 1 on 2017/12/6.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#ifndef BiTree_h
#define BiTree_h


#endif /* BiTree_h */

typedef struct BiNode{
    TElemType data;     //结点的值
    struct BiNode *lchild; //左孩子指针
    struct BiNode *rchild; //右孩子指针
    int num ;        //出现次数
}BiNode, *BiTree;

void CreateBiNode(BiTree &BT, TElemType e) {
    BT = (BiTree)malloc(sizeof(BiNode));
    BT->data = e;
    BT->lchild = NULL;
    BT->rchild = NULL;
    BT->num = 1;
}
