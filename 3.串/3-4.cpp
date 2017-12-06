#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "DSqString.h"

DSqString LongestRepetSubstring(DSqString S);

#define max 100
int main(){
	char str[max];
	cout<<"请输入串S："<<endl;
	cin.get(str,max);
	DSqString S;
	StrAssign_Sq(S,str);
	
	if(LongestRepetSubstring(S).str){
		cout<<"出现的第一个重复的字符串是：";
		StrTraveres_Sq(LongestRepetSubstring(S));
	}
	else{
		cout<<"没有重复的字符串"; 
	}
}

DSqString LongestRepetSubstring(DSqString S){
	DSqString St;
	char str[] = "";
	StrAssign_Sq(St,str);
	int j;
	for(int n = S.length-1;n>0;n--){
		int i=0;
		while(SubString_Sq(S,St,i,n)){
			if(Index_Sq(S,St,j,i+1)){
				return St;
			}
			i++;
		}		
	}
	DestroyString_Sq(St);
	return St;
} 
