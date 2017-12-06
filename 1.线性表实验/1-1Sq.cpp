#include <iostream> 
#include <stdlib.h>		//包含malloc()、realloc()和free()等
#include <iomanip>	//包含输入流输出流cin、cout及控制符setw()
typedef int ElemType;	//将抽象对象类型具体化为整形 
#include "SqList.h"	//包含顺序数据对象的描述及相关操作 


int main(){
	SqList mylist;					//定义名为mylist的顺序表
	int n=10;						//定义n的大小 
	InitList_Sq(mylist, n, 10);		//构造一个最大容量为n的顺序表mylist 
	int a[] = {1,4,5,8,10,17,34};	//定义将要插入顺序表元素的递增的值为一元数组 
	for(int i=0;i<sizeof(a)/sizeof(int);i++) 
		ListInsert_Sq(mylist, i, a[i]);		//把数组a的值依次插入顺序表元素 
	ListTraverse_Sq(mylist);				//遍历插入前的顺序表元素 
	cout<<"请输入您要插入的整数"<<endl;
	int x;
	cin>>x;
	int i=0;	//输入要插入的整数 
	for(i=0;i<mylist.length&&x>mylist.elem[i];i++);//顺序查找法找到要插入的位置i 
	cout<<i<<endl;
	ListInsert_Sq(mylist, i, x);	//调用库里面的插入函数进行插入操作 
	ListTraverse_Sq(mylist); 		//顺序遍历所有元素 
	DestroyList_Sq(mylist); 	//释放顺序表存在的空间 
} 


