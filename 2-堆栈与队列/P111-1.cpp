#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h> 
typedef char ElemType;
#include "SqStack.h"

bool kuohao_match(char *Expre)
{//判断表达式中的括号是否匹配的算法
	SqStack S;//定义顺序栈类型S
	InitStack_Sq(S);//初始化顺序栈
	Expre=strcat(Expre,"#");//表达式尾部添加结束符# 
	char e,a;//栈顶元素 
	int i=0;

	while(Expre[i]!='#'){
		if(Expre[i]!='('&&Expre[i]!=')'&&Expre[i]!='['&&Expre[i]!=']'&&Expre[i]!='{'&&Expre[i]!='}'){
			i++;
			continue;
		} //遇到非括号i++检查下一个字符
		if(Expre[i]=='('||Expre[i]=='['||Expre[i]=='{'){
			Push_Sq(S,Expre[i]);
			i++;
			continue;
		}//遇到左括号，插入栈顶 
		if(Expre[i]==')'){
			GetTop_Sq(S,e);//取栈顶元素 
			if(e=='('){
				Pop_Sq(S,a);
				i++;
				continue; 
			} //若匹配则删除栈顶元素
			else{
				return false;
			}//若不是则直接返回false 
		}
		if(Expre[i]==']'){
			GetTop_Sq(S,e);//取栈顶元素 
			if(e=='['){
				Pop_Sq(S,a);
				i++;
				continue; 
			} //若匹配则删除栈顶元素
			else{
				return false;
			}//若不是则直接返回false 
		}
		if(Expre[i]=='}'){
			GetTop_Sq(S,e);//取栈顶元素 
			if(e=='{'){
				Pop_Sq(S,a);
				i++;
				continue; 
			} //若匹配则删除栈顶元素
			else{
				return false;
			}//若不是则直接返回false 
		}
	
	}
	return StackEmpty_Sq(S);//若栈最后为空则返回ture否则返回false 
}
int main(){
	char Expre[80]="A+{(b-c)/d}*e";
	if(kuohao_match(Expre))
		cout<<"匹配！"<<endl;
	else
		cout<<"不匹配！"<<endl; 
}
