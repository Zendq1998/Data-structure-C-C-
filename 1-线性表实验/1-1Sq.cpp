#include <iostream> 
#include <stdlib.h>		//����malloc()��realloc()��free()��
#include <iomanip>	//���������������cin��cout�����Ʒ�setw()
typedef int ElemType;	//������������;��廯Ϊ���� 
#include "SqList.h"	//����˳�����ݶ������������ز��� 


int main(){
	SqList mylist;					//������Ϊmylist��˳���
	int n=10;						//����n�Ĵ�С 
	InitList_Sq(mylist, n, 10);		//����һ���������Ϊn��˳���mylist 
	int a[] = {1,4,5,8,10,17,34};	//���彫Ҫ����˳���Ԫ�صĵ�����ֵΪһԪ���� 
	for(int i=0;i<sizeof(a)/sizeof(int);i++) 
		ListInsert_Sq(mylist, i, a[i]);		//������a��ֵ���β���˳���Ԫ�� 
	ListTraverse_Sq(mylist);				//��������ǰ��˳���Ԫ�� 
	cout<<"��������Ҫ���������"<<endl;
	int x;
	cin>>x;
	int i=0;	//����Ҫ��������� 
	for(i=0;i<mylist.length&&x>mylist.elem[i];i++);//˳����ҷ��ҵ�Ҫ�����λ��i 
	cout<<i<<endl;
	ListInsert_Sq(mylist, i, x);	//���ÿ�����Ĳ��뺯�����в������ 
	ListTraverse_Sq(mylist); 		//˳���������Ԫ�� 
	DestroyList_Sq(mylist); 	//�ͷ�˳�����ڵĿռ� 
} 


