#include <iostream>
#include <iomanip>
#include <stdlib.h>
typedef int ElemType;
#include "QueueType.h"
using namespace std;

int main(){
	QueueType Q;
	InitQueue_Type(Q);
	int a[]={1,2,3,4,5,6,7,8,9,10},i=0,x;
	for(int i=0;i<sizeof(a)/sizeof(int);i++){
		EnQueue_Type(Q,a[i]);	
	}
	
	cout<<"���еĶ���Ԫ�أ�"<<GetHead_Type(Q);
	cout<<endl;
	DeQueue_Type(Q,x);
	cout<<"����һ��Ԫ��֮�󣬶���Ԫ�أ�"<<GetHead_Type(Q)<<endl;
	cout<<"ʣ������Ԫ�س��ӣ�"<<endl; 
	while(DeQueue_Type(Q,x)) 
		cout<<x<<setw(3);
	cout<<endl<<"�����Ƿ�Ϊ�գ�"<<endl;
	if(QueueEmpty_Sq)
		cout<<"����Ϊ��"<<endl;
	else
		cout<<"���зǿ�"<<endl; 
	
	
}
