#include <iostream>
#include <iomanip>	//包含cin cout setw() 
#include <stdlib.h> //包含malloc() 等
typedef int ElemType ;//将抽象对象类型具体化为整形 
#include "LinkList.h"//包含链式数据对象的描述及相关操作

int main() {
	LinkList L;	//定义一个结构体指针变量L 
	int a[]={1,4,5,8,10,17,34};	//定义将要插入链表data部分的数组 
	CreateList_L_Front(L, a,sizeof(a)/sizeof(int) );// 利用尾插法创建单链表L
	ListTraverse_L(L);	//按链表的顺序遍历一遍data 
	cout<<"请输入您要插入的整数"<<endl;
	int x;
	cin>>x;		//输入要插入的整数 

	for(int i=1;i<=ListLength_L(L)+1;i++){
		if(x>GetElem_L(L,i)&&i<=ListLength_L(L)) continue;
		ListInsert_L(L, i, x);
		break;
	}	//找到插入的整数应该插进的节点位置 并且调用插入函数进行插入操作 
	ListTraverse_L(L); //遍历插入后的节点的data 
	DestroyList_L(L);//释放链表所占用的空间 
}


 
