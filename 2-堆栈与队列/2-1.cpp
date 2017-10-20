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
	
	cout<<"队列的队首元素："<<GetHead_Type(Q);
	cout<<endl;
	DeQueue_Type(Q,x);
	cout<<"出队一个元素之后，队首元素："<<GetHead_Type(Q)<<endl;
	cout<<"剩下所有元素出队："<<endl; 
	while(DeQueue_Type(Q,x)) 
		cout<<x<<setw(3);
	cout<<endl<<"队列是否为空？"<<endl;
	if(QueueEmpty_Sq)
		cout<<"队列为空"<<endl;
	else
		cout<<"队列非空"<<endl; 
	
	
}
