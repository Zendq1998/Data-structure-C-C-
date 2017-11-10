#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#include "DSqString.h"


typedef struct{
	char X; //存储出现的合法的字符
	int num=0;//对应的字符出现的个数 
}NumofX;


void num(char a,NumofX *result){
	int i = a-48;
	result[i].X=a;
	result[i].num++;	
}

void letter(char a,NumofX *result){
	int i = a-65+10;
	result[i].X=a;
	result[i].num++;
	
}

#define max 50 
int main(){
	char S[max];
	cout<<"请输入一段字符串，统计合法数字（合法字符为'A'～'Z'这26个字母和'0'～'9'这10个数字）" <<endl; 
	cin.get(S,max);
	//输入的字符串暂存到S中 
	
	DSqString Str;	
	StrAssign_Sq(Str,S);
	
	cout<<endl<<"统计结果为"<<endl;
	
	NumofX result[36];
	
	for(int i=0;i<Str.length;i++){
		if(Str.str[i]>='0'&&Str.str[i]<='9')
			num(Str.str[i],result);
		if(Str.str[i]>='A'&&Str.str[i]<='Z')
			letter(Str.str[i],result);	
	}
	for(int i=0;i<36;i++){
		if(result[i].num>0)
			cout<<result[i].X<<":"<<setw(2)<<result[i].num<<endl;
	}
	 
} 

