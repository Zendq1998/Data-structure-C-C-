#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

bool Saddlepoint(int *maxtrix,int m,int n,int &saddle);

int main() {
	int a[4][3] = {{1,2,3},{8,5,6},{2,8,9},{0,11,12}};
	int saddle;
	if(Saddlepoint((int*)a,3,4,saddle)) {
		cout<<"马鞍点是："<<saddle;	
	}
	else {
		cout<<"没有马鞍点！";
	}
}

bool Saddlepoint(int *maxtrix,int m,int n,int &saddle) {
	//n行 m列 
	for (int i=0;i<n;i++) {
		int min = maxtrix[i*m];
		int col=0;
		for (int j=1;j<m;j++) {
			if(maxtrix[i*m+j]<min) {
				min = maxtrix[i*m+j];
				col = j;
			}
		}
		int max = min;
		int k;
		int flag=1;
		for (k=0;k<n;k++) {
			if(maxtrix[k*m+col]>max) {
				flag=0;
				break;
			}
		}
		if (flag!=0) {
			saddle = max;
			return true;
		}
	}
	return false;
}


