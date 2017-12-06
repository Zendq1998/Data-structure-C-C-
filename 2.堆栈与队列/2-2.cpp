#include <iostream>
#include <iomanip>
#include <stdlib.h>
typedef int ElemType;
#include "SqQueue.h"
#include "SqStack.h"
using namespace std;

bool InverQueue_Sq(SqQueue &Q){
	SqStack T;			//定义一个堆栈T
	InitStack_Sq(T);	//为T分配空间
	int x;
	while(DeQueue_Sq(Q,x)){
		Push_Sq(T,x);
	}
	
	while(Pop_Sq(T,x)){
		EnQueue_Sq(Q,x);
	}
	return true;
}
int main(){
	SqQueue Q;			//定义一个队列Q 
	InitQueue_Sq(Q);	//为Q分配空间
	SqStack T;			//定义一个堆栈T
	InitStack_Sq(T);	//为T分配空间
	
	int i=0,a[]={1,2,3,4,5,6,7,9,22},x; 
	while(a[i]){
		EnQueue_Sq(Q,a[i++]);
	}//a[i]依次进队

//	while(DeQueue_Sq(Q,x)){
//		Push_Sq(T,x);
//	}
//	
//	while(Pop_Sq(T,x)){
//		EnQueue_Sq(Q,x);
//	}
	
	InverQueue_Sq(Q);
	
	while(DeQueue_Sq(Q,x)){
		cout<<x<<endl;
	}
}
