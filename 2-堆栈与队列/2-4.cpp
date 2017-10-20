#include <iostream>
#include <iomanip>
#include <stdlib.h>
typedef int ElemType;
#include "SqQueue.h"
using namespace std;

bool Line_Up_Wait(SqQueue &Q,int a){
	//排队 
	EnQueue_Sq(Q,a);
	return true;
}

bool Acces_To_Cure(SqQueue &Q,int &x){
	//就诊 
	if(DeQueue_Sq(Q,x))
		return true;
	else false;
}

void Check_Line(SqQueue Q){
	//查看排队 
	int x;
	while(DeQueue_Sq(Q,x)){
		cout<<x<<setw(5);
	}
}

bool Cure_All(SqQueue &Q){
	//不再排队 
	int x;
	while(DeQueue_Sq(Q,x));
	return true;
}

int main(){
	int x,a;
	cout<<"操作列表："<<endl;
	cout<<"①排队  ②就诊  ③查看排队  ④不再排队  ⑤下班"<<endl;
	SqQueue Q;
	InitQueue_Sq(Q);
	while(1){
		cout<<"请输入您要进行的操作编号："; 
		cin>>x;
		switch(x){
			case 1:{
				cout<<"排队 请输入您的病例号：";
				cin>>a;
				if(Line_Up_Wait(Q,a))
					cout<<"排队成功，请您候诊。"<<endl; 
				else cout<<"候诊失败！"<<endl;
				break;
			}
			case 2:{
				if(Acces_To_Cure(Q,x))
					cout<<"请"<<x<<"号前来就诊"<<endl;
				else cout<<"没有人来就诊！"<<endl; 
				break;
			}
			case 3:{
				cout<<"查看排队："<<endl; 
				Check_Line(Q);
				cout<<endl;
				break;
			}
			case 4:{
				cout<<"请";
				Check_Line(Q);
				cout<<"号前来就诊"<<endl;
				if(Cure_All(Q))
					cout<<"就诊成功！"<<endl;
				else cout<<"就诊失败"<<endl;
				exit(1);
			}
			case 5:{
				//下班 
				exit(1);
			}		
		}
	cout<<"***********************************************************************" <<endl;	
	} 
}


