#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h> 
typedef char ElemType;
#include "SqStack.h"

bool kuohao_match(char *Expre)
{//�жϱ��ʽ�е������Ƿ�ƥ����㷨
	SqStack S;//����˳��ջ����S
	InitStack_Sq(S);//��ʼ��˳��ջ
	Expre=strcat(Expre,"#");//���ʽβ����ӽ�����# 
	char e,a;//ջ��Ԫ�� 
	int i=0;

	while(Expre[i]!='#'){
		if(Expre[i]!='('&&Expre[i]!=')'&&Expre[i]!='['&&Expre[i]!=']'&&Expre[i]!='{'&&Expre[i]!='}'){
			i++;
			continue;
		} //����������i++�����һ���ַ�
		if(Expre[i]=='('||Expre[i]=='['||Expre[i]=='{'){
			Push_Sq(S,Expre[i]);
			i++;
			continue;
		}//���������ţ�����ջ�� 
		if(Expre[i]==')'){
			GetTop_Sq(S,e);//ȡջ��Ԫ�� 
			if(e=='('){
				Pop_Sq(S,a);
				i++;
				continue; 
			} //��ƥ����ɾ��ջ��Ԫ��
			else{
				return false;
			}//��������ֱ�ӷ���false 
		}
		if(Expre[i]==']'){
			GetTop_Sq(S,e);//ȡջ��Ԫ�� 
			if(e=='['){
				Pop_Sq(S,a);
				i++;
				continue; 
			} //��ƥ����ɾ��ջ��Ԫ��
			else{
				return false;
			}//��������ֱ�ӷ���false 
		}
		if(Expre[i]=='}'){
			GetTop_Sq(S,e);//ȡջ��Ԫ�� 
			if(e=='{'){
				Pop_Sq(S,a);
				i++;
				continue; 
			} //��ƥ����ɾ��ջ��Ԫ��
			else{
				return false;
			}//��������ֱ�ӷ���false 
		}
	
	}
	return StackEmpty_Sq(S);//��ջ���Ϊ���򷵻�ture���򷵻�false 
}
int main(){
	char Expre[80]="A+{(b-c)/d}*e";
	if(kuohao_match(Expre))
		cout<<"ƥ�䣡"<<endl;
	else
		cout<<"��ƥ�䣡"<<endl; 
}
