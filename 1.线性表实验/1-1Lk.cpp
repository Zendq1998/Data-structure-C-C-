#include <iostream>
#include <iomanip>	//����cin cout setw() 
#include <stdlib.h> //����malloc() ��
typedef int ElemType ;//������������;��廯Ϊ���� 
#include "LinkList.h"//������ʽ���ݶ������������ز���

int main() {
	LinkList L;	//����һ���ṹ��ָ�����L 
	int a[]={1,4,5,8,10,17,34};	//���彫Ҫ��������data���ֵ����� 
	CreateList_L_Front(L, a,sizeof(a)/sizeof(int) );// ����β�巨����������L
	ListTraverse_L(L);	//�������˳�����һ��data 
	cout<<"��������Ҫ���������"<<endl;
	int x;
	cin>>x;		//����Ҫ��������� 

	for(int i=1;i<=ListLength_L(L)+1;i++){
		if(x>GetElem_L(L,i)&&i<=ListLength_L(L)) continue;
		ListInsert_L(L, i, x);
		break;
	}	//�ҵ����������Ӧ�ò���Ľڵ�λ�� ���ҵ��ò��뺯�����в������ 
	ListTraverse_L(L); //���������Ľڵ��data 
	DestroyList_L(L);//�ͷ�������ռ�õĿռ� 
}


 
