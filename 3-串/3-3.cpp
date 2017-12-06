#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "DSqString.h"

typedef struct{
	DSqString value;
	int times;
}TimesOfvalue;
typedef TimesOfvalue ElemType;

#include "SqList.h"

void Count(DSqString S,SqList &L);

int main(){
	char str[] = "The policy of Belt and Road has been the hot topic in"
	" the year of 2017, and many foreign countries have joined this plan. "
	"For the foreign students, they become more interested in Chinese and "
	"learn the culture, at the same time, Chinese students have faced the "
	"opportunity and challenge.This great policy provides the chance to do "
	"business between countries, so it is important to master the international "
	"language¡ªEnglish. Though many Chinese students have learned it for a long time,"
	" they can¡¯t use it fluently because of the lack of chance to communicate with local"
	" people. At the same time, culture is the inevitable part during making  connection "
	"with another countries, so it is important to learn the culture. For the students "
	"who want to work on the International company, they need to improve their language "
	"ability and the ability to make connection with foreigners.The policy of Belt and Road"
	" have won praise from people all around the world. They are expecting to seek for "
	"cooperation. In the future, more business chances will come. If you are ready for it, you will be ahead of others. ";
	DSqString S;
	StrAssign_Sq(S,str);
	SqList L;
	InitList_Sq(L);
	
	Count(S,L);
	
	for(int i=0;i<L.length;i++){
		StrTraveres_Sq(L.elem[i].value);
		cout<<":"<<L.elem[i].times<<"´Î";
		if(i>0&&i%6==0){
			cout<<endl;
		} 
		else{
			cout<<setw(4);
		}
	}
}

void Count(DSqString S,SqList &L){
	DSqString St;
	char str[]="";
	StrAssign_Sq(St,str);
	for(int i=0,n=0;i<S.length+1;i++){
		if(S.str[i]>='a'&&S.str[i]<='z'||S.str[i]>='A'&&S.str[i]<='Z'){
			n++;
		}
		else{					
			SubString_Sq(S,St,i-n,n);
			n=0;
			int j;
			for(j=0;j<L.length;j++){
				if(StrCompare_Sq(St,L.elem[j].value)==0){
					L.elem[j].times++;
					break;
				}
			}
			if(j>=L.length){
				TimesOfvalue e;
				StrCopy_Sq(e.value,St);
				e.times = 1;
				ListInsert_Sq(L,j,e);
			}
		}
	}
}


