//
//  main.cpp
//  5-2单词排序
//
//  Created by 1 on 2017/12/6.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
typedef string TElemType;
#include "BiTree.h"

int StrCompare(string S,string T);
bool InsertBiNode(BiTree &head, string word);
void InorderBiTree (BiTree BT);

int main() {
    BiTree head;
    string word;
    cin>>word;
    CreateBiNode(head, word);
    while (1) {
        cin>>word;      //输入一个单词
        bool is_word = true;    //定义一个布尔类型确定该个输入是否时单词
        for(int i=0;i<word.length();i++) {
            if((word[i]>='A'&&word[i]<='Z') ||
               (word[i]>='a'&&word[i]<='z'))
                continue;
            else {
                is_word = false;
                break;
            }//若遇见了非字母则将is_word置为false
        }
        if (is_word) {
            InsertBiNode(head, word);
        }
        if (getchar() == '\n')
            break;
    }
    cout<<"单词排序的结果"<<endl;
    InorderBiTree(head);
    return 0;
}

int StrCompare(string S,string T) {
    int i;
    for (i=0; i<S.length() && i<T.length(); i++) {
        char l = S[i];
        char r = T[i];
        if (l>='A' && l<='Z') {
            l += 32;
        }
        if (r>='A' && r<='Z') {
            r += 32;
        }
        if (l > r)
            return 1;
        else if (l < r) {
            return -1;
        }
    }
    if(i < S.length())
        return 1;
    if(i < T.length())
        return -1;
    return 0;
}

bool InsertBiNode(BiTree &head, string word) {
    //将BT插入树head
    BiTree p = head;
    BiTree BT;
    int cmp = StrCompare(p->data, word);
    if(cmp == 0) {
        //不作插入 结点的num加一
        p->num ++;
        return false;
    }
    if(cmp == 1) {
        //插入左子树
        if(!p->lchild) {
            CreateBiNode(BT, word);
            p->lchild = BT;
            return true;
        }//若左子树空则直接将BT作为p的左子树
        InsertBiNode(p->lchild,word);
        //若左子树非空则递归BT插入左子树
    }
    if(cmp == -1) {
        //插入右子树
        if(!p->rchild) {
            CreateBiNode(BT, word);
            p->rchild = BT;
            return true;
        }//若右子树空则直接将BT作为p的右子树
        InsertBiNode(p->rchild,word);
        //若右子树非空则递归BT插入右子树
    }
    return false;
}

void InorderBiTree (BiTree BT) {
    if (BT) {
        InorderBiTree(BT->lchild);
        cout<<BT->data<<":"<<BT->num<<"次  ";
        InorderBiTree(BT->rchild);
    }
}//中序遍历二叉树
