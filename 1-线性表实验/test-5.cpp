#include <iostream>
#include <iomanip>
#include <stdlib.h>
typedef int ElemType;
#include "LinkList.h"

int main() {
	LinkList L;	//����һ���ṹ��ָ�����L 
	int a[]={1,2,3,4,5,6,7};	//���彫Ҫ��������data���ֵ����� 
	CreateList_L_Front(L, a,sizeof(a)/sizeof(int) );// ����β�巨����������L
	ListTraverse_L(L);	//�������˳�����һ��data 
//	cout<<"��������Ҫɾ��������"<<endl;
//	int x;
//	cin>>x;  	//�������뽫Ҫɾ����Ԫ��
	//dataDelete_L(L, x);//�����Լ�д�ĺ��� L��Ҫ��������ʽ��x��Ҫɾ������dataֵ 
	//�ٴα���dataֵ 
	Inverse_L(L);
	ListTraverse_L(L);
} 
