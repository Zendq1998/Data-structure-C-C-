#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#include "DSqString.h"


typedef struct{
	char X; //�洢���ֵĺϷ����ַ�
	int num=0;//��Ӧ���ַ����ֵĸ��� 
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
	cout<<"������һ���ַ�����ͳ�ƺϷ����֣��Ϸ��ַ�Ϊ'A'��'Z'��26����ĸ��'0'��'9'��10�����֣�" <<endl; 
	cin.get(S,max);
	//������ַ����ݴ浽S�� 
	
	DSqString Str;	
	StrAssign_Sq(Str,S);
	
	cout<<endl<<"ͳ�ƽ��Ϊ"<<endl;
	
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

