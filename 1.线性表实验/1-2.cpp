#include <iostream>
#include <iomanip>
#include <stdlib.h>
typedef int ElemType;
#include "LinkList.h"

int main() {
	LinkList L;	//定义一个结构体指针变量L 
	int a[]={1,1,2,2,10,17,34};	//定义将要插入链表data部分的数组 
	CreateList_L_Front(L, a,sizeof(a)/sizeof(int) );// 利用尾插法创建单链表L
	ListTraverse_L(L);	//按链表的顺序遍历一遍data 
	cout<<"请输入您要删除的整数"<<endl;
	int x;
	cin>>x;  	//按照输入将要删除的元素
	dataDelete_L(L, x);//调用自己写的函数 L是要操作的链式表，x是要删除结点的data值 
	ListTraverse_L(L);	//再次遍历data值 
} 
