#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
#include "SqStack.h"
using namespace std;

bool odd_even_Rand_Push_Stack_Sq(int n, int a, int b, SqStack &S1, SqStack &S2){
	int x;
	for(int i=0;i<n;i++){
		x=rand()%(b-a+1)+a;
		if(x%2)
			Push_Sq(S1,x);
		else
			Push_Sq(S2,x);	
	}
}

int main(){
	SqStack S1,S2;
	InitStack_Sq(S1);
	InitStack_Sq(S2);
	odd_even_Rand_Push_Stack_Sq(30,0,100,S1,S2);
	int x,y;
	
	cout<<"ÆæÊýÕ»:"<<setw(21)<<"Å¼ÊýÕ»£º" <<endl;
	while(Pop_Sq(S1,x)&&Pop_Sq(S2,y)){
		cout<<x<<setw(20)<<y<<endl;
	}
	while(Pop_Sq(S1,x))
		cout<<x<<endl;
	while(Pop_Sq(S2,y))
		cout<<setw(22)<<y<<endl;
		
	DestroyStack_Sq(S1);
	DestroyStack_Sq(S2);
	
		
}
