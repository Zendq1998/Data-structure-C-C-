#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "DSqString.h"

bool format(DSqString S1,DSqString &S2,DSqString &S3,int n);

int main(){
	char str[] = "If not to the sun for smiling, warm is "
	"still in the sun there, but wewill laugh more confident calm;"
	" if turned to found his own shadow, appropriate escape, the sun"
	" will be through the heart,warm each place behind the corner; if "
	"an outstretched palm cannot fall butterfly, then clenched waving arms, "
	"given power; if I can't have bright smile, it will face to the sunshine,"
	" and sunshine smile together, in full bloom.";
	DSqString S1,S2,S3;
	StrAssign_Sq(S1,str);
	
	format(S1,S2,S3,50);
	
	StrTraveres_Sq(S2);
	StrTraveres_Sq(S3);
}

bool format(DSqString S1,DSqString &S2,DSqString &S3,int n){
	char str[]="";
	StrAssign_Sq(S2,str);
	StrAssign_Sq(S3,str);
	
	int lastrow = S1.length%n;
	SubString_Sq(S1,S3,S1.length-lastrow,lastrow);
	
	StrDelete_Sq(S1,S1.length-lastrow,lastrow);
	
	DSqString Sn;
	char enter[]="\n";
	StrAssign_Sq(Sn,enter);
	StrCopy_Sq(S2,S1);
	for(int m=n,i=0;m<S1.length;m+=n,i++){			
		StrInsert_Sq(S2,m+i,Sn);
	}
}


