#include <iostream>
#include <iomanip>
#include <stdlib.h>
typedef int ElemType;
#include "SqQueue.h"
using namespace std;

bool Line_Up_Wait(SqQueue &Q,int a){
	//�Ŷ� 
	EnQueue_Sq(Q,a);
	return true;
}

bool Acces_To_Cure(SqQueue &Q,int &x){
	//���� 
	if(DeQueue_Sq(Q,x))
		return true;
	else false;
}

void Check_Line(SqQueue Q){
	//�鿴�Ŷ� 
	int x;
	while(DeQueue_Sq(Q,x)){
		cout<<x<<setw(5);
	}
}

bool Cure_All(SqQueue &Q){
	//�����Ŷ� 
	int x;
	while(DeQueue_Sq(Q,x));
	return true;
}

int main(){
	int x,a;
	cout<<"�����б�"<<endl;
	cout<<"���Ŷ�  �ھ���  �۲鿴�Ŷ�  �ܲ����Ŷ�  ���°�"<<endl;
	SqQueue Q;
	InitQueue_Sq(Q);
	while(1){
		cout<<"��������Ҫ���еĲ�����ţ�"; 
		cin>>x;
		switch(x){
			case 1:{
				cout<<"�Ŷ� ���������Ĳ����ţ�";
				cin>>a;
				if(Line_Up_Wait(Q,a))
					cout<<"�Ŷӳɹ����������"<<endl; 
				else cout<<"����ʧ�ܣ�"<<endl;
				break;
			}
			case 2:{
				if(Acces_To_Cure(Q,x))
					cout<<"��"<<x<<"��ǰ������"<<endl;
				else cout<<"û���������"<<endl; 
				break;
			}
			case 3:{
				cout<<"�鿴�Ŷӣ�"<<endl; 
				Check_Line(Q);
				cout<<endl;
				break;
			}
			case 4:{
				cout<<"��";
				Check_Line(Q);
				cout<<"��ǰ������"<<endl;
				if(Cure_All(Q))
					cout<<"����ɹ���"<<endl;
				else cout<<"����ʧ��"<<endl;
				exit(1);
			}
			case 5:{
				//�°� 
				exit(1);
			}		
		}
	cout<<"***********************************************************************" <<endl;	
	} 
}


