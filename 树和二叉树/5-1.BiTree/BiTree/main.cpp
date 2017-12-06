//
//  main.cpp
//  BiTree
//
//  Created by Zendq on 2017/12/6.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
typedef char TElemType; //二叉树中的结点的数据为字符型
#include "bitree.h"     //算法都在这里哦

int main() {
    BiTree BT;          //声明一个二叉树根结点指针
    CreateBiTree(BT);   //1⃣️创建二叉树
    cout<<"结点数为"<<NumofNode(BT)<<endl;  //2⃣️调用统计二叉树结点的函数
    cout<<"叶子数为"<<Numofleaves(BT)<<endl;//3⃣️调用统计二叉树叶子的函数
    cout<<"输出叶子：";
    Outputleaves(BT);   //4⃣️输出所有的叶子结点
    cout<<endl;
    PrintBiTree(BT,3);  //5⃣️输出所有叶子到根的路径
    return 0;
}
