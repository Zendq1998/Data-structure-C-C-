#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void Plus_V (int *a,int *b,int *c,int n);
void TraverseV(int *a,int n);
int multy_xy (int *a,int *b,int n,int x,int y);
void Multy_V (int *a,int *b,int *c,int n);

int main() {
	int n = 5; //二维数组的阶数
	int m = n*(n+1)/2+1; //三角矩阵所需要的空间
	
	int Va[m] = {2,4,1,4,0, 3,3,1,6, 5,3,3, 4,4, 2, 0};
	int Vb[m] = {3,1,1,3,2, 6,5,12,3, 3,5,5, 2,6, 8, 0};
	int Vc[m];
	cout<<"矩阵a："<<endl;
	TraverseV(Va,n);
	cout<<endl<<"矩阵b："<<endl;
	TraverseV(Vb,n);
	cout<<endl;
	Plus_V(Va,Vb,Vc,n);
	cout<<endl<<"矩阵a和矩阵b相加："<<endl;
	TraverseV(Vc,n);
	Multy_V(Va,Vb,Vc,n);
	cout<<endl<<"矩阵a和矩阵b相乘："<<endl;
	TraverseV(Vc,n);
	
}

void Plus_V (int *a,int *b,int *c,int n) {
	int m = n*(n+1)/2+1;
	for(int i=0;i<m;i++) {
		c[i] = a[i]+b[i];
	}
}

int multy_xy (int *a,int *b,int n,int x,int y) {
	int k=0;
	for(int i=0;i<n;i++) {
		k+=(x<=i?a[x*(2*n-x+1)/2+i-x]:a[n*(n+1)/2])*
			(i<=y?b[i*(2*n-i+1)/2+y-i]:b[n*(n+1)/2]);
	}
	return k;
}

void Multy_V (int *a,int *b,int *c,int n) {
	int m = n*(n+1)/2+1;
	int k;
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			k = i*(2*n-i+1)/2+j-i;
			c[k]= multy_xy(a,b,n,i,j);
		}
	}
	c[n*(n+1)/2] = 0;
}

void TraverseV(int *a,int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			int k;
			if(i<=j) {
				k = i*(2*n-i+1)/2+j-i;
			}
			else {
				k = n*(n+1)/2;
			}
			cout<<a[k];
			if(j!=n-1) {
				cout<<setw(4);
			}
		}
		cout<<endl;
	}
} 
