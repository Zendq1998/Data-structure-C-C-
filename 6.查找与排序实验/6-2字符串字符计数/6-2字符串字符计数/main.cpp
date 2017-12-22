//
//  main.cpp
//  6-2字符串字符计数
//
//  Created by 1 on 2017/12/22.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct Cnode{
    char e;
    int num;
    struct Cnode *lchild;
    struct Cnode *rchild;
} Cnode,*BT;
void insert_BiTree(BT &head,char e);
void MidOrderTree(BT head);
int main() {
    string test;
    cin>>test;
    BT head = NULL;
    for (int i=0; i<test.length(); i++) {
        insert_BiTree(head, test[i]);
    }
    MidOrderTree(head);
    return 0;
}

void insert_BiTree(BT &head,char e){
    if (!head) {
        head = (BT)malloc(sizeof(Cnode));
        head->e = e;
        head->num = 1;
        head->lchild = NULL;
        head->rchild = NULL;
    }
    else if (head->e > e) {
        insert_BiTree(head->lchild, e);
    }
    else if (head->e < e) {
        insert_BiTree(head->rchild, e);
    }
    else {
        head->num ++;
    }
}
void MidOrderTree(BT head){
    if (head) {
        MidOrderTree(head->lchild);
        cout<<(head->e)<<"："<<(head->num)<<"times"<<endl;
        MidOrderTree(head->rchild);
    }
}
