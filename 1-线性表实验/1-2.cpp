#include <iostream>
#include <iomanip>
#include <stdlib.h>
typedef int ElemType;
#include "LinkList.h"

int main() {
	LinkList L;	//����һ���ṹ��ָ�����L 
	int a[]={1,1,2,2,10,17,34};	//���彫Ҫ��������data���ֵ����� 
	CreateList_L_Front(L, a,sizeof(a)/sizeof(int) );// ����β�巨����������L
	ListTraverse_L(L);	//�������˳�����һ��data 
	cout<<"��������Ҫɾ��������"<<endl;
	int x;
	cin>>x;  	//�������뽫Ҫɾ����Ԫ��
	dataDelete_L(L, x);//�����Լ�д�ĺ��� L��Ҫ��������ʽ��x��Ҫɾ������dataֵ 
	ListTraverse_L(L);	//�ٴα���dataֵ 
} 
